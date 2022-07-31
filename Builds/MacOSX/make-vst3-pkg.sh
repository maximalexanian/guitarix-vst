#!/bin/sh

# Stub to work in the current directory.
if [[ "$CONFIGURATION_BUILD_DIR" == "" ]]; then
	CONFIGURATION_BUILD_DIR="$(pwd)"
fi

Src="$CONFIGURATION_BUILD_DIR"
Dst="$CONFIGURATION_BUILD_DIR"
Build="$CONFIGURATION_TEMP_DIR/Installer"
DataDir="$PROJECT_DIR/../../Data"
if [ -e "$Build" ]; then rm -R "$Build"; fi
mkdir -p "$Build"

Payload_Plugin="$Build/Payload/Library/Audio/Plug-Ins/VST3"
mkdir -p "$Payload_Plugin"
if ( ! cp -aL "$Src/Guitarix.vst3" "$Payload_Plugin"/ )
	then echo Error $?: Plug-in not copied!; exit 1; fi
#codesign -s "Developer ID Application" -f --timestamp "$Payload_Plugin/Guitarix.vst3"

Payload_PresetsVST="$Build/Payload/Library/Audio/Presets/Guitarix/Guitarix"
mkdir -p "$Payload_PresetsVST"
if ( ! ditto -xk "$DataDir/GuitarixPresetsVST.zip" "$Payload_PresetsVST"/ )
	then echo Error $?: Plug-in not copied!; exit 1; fi
 
#---------------------------------------------------------------------------

# Preinstall and Postinstall scripts

mkdir -p "$Build/Scripts"
pushd "$Build/Scripts" >> /dev/null

#preinstall
echo "#!/bin/bash" > preinstall
echo "rm -R \"\$LibDir/Audio/Plug-Ins/VST3/Guitarix.vst3\"" >> preinstall
echo "true" >> preinstall
chmod a+x preinstall

#postinstall
echo "#!/bin/bash" > postinstall
if [ -e "$DataDir/guitarix.zip" ]; then
    cp -a "$DataDir/guitarix.zip" ./
    echo "if [ -e \"\$1/guitarix.zip\" ]" >> postinstall
	echo "then mkdir -p \"\$HOME\"/.config" >> postinstall
	echo "     ditto -xk \"\$1/guitarix.zip\" \"\$HOME\"/.config" >> postinstall
	echo "fi" >> postinstall
fi
chmod a+x postinstall

popd >> /dev/null
#---------------------------------------------------------------------------

PkgId="$PRODUCT_BUNDLE_IDENTIFIER"
if [[ "$PkgId" == "" ]]; then
	PkgId="com.guitarix.guitarix.pkg"
fi
ProdVersion="$GX_PRODUCT_VERSION"
if [[ "$ProdVersion" == "" ]]; then
	ProdVersion="1.0.0"
fi
if ! pkgbuild --root "$Build/Payload" \
   --install-location "/" \
   --identifier "$PkgId" \
   --version "$ProdVersion" \
   --scripts "$Build/Scripts" \
   "$Build/GuitarixVST3.pkg"
then echo "Not built: error $?"; exit 2; fi

#if ! productsign --sign "Developer ID Installer" --timestamp "$Build/GuitarixVST3.pkg" "$Build/GuitarixVST3.pkg"
#then echo "Not signed: error $?"; exit 3; fi

mkdir -p "$Build/Resources"
pushd "$Build/Resources" >> /dev/null
cp -pf "$DataDir/License.rtf" License.rtf
chown "$USER" *
chflags nouchg *
chmod u+w,a+rx *
popd >> /dev/null

if ! productbuild \
        --distribution "$PROJECT_DIR/Guitarix.xml" \
        --package-path "$Build" \
        --resources "$Build/Resources" \
        --version "$ProdVersion" \
        "$Build/Guitarix.pkg"
then echo "productbuild error $?"; exit 1; fi
#if ! productsign --sign "Developer ID Installer" --timestamp "$Build/Guitarix.pkg" "$Dst/GuitarixSetup$ProdVersion.pkg"
#then echo "productsign error $?"; exit 2; fi

rm -R "$Build"
