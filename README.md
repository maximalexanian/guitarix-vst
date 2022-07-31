# Guitarix.vst

Guitarix.vst is a Mac/Windows VST3 port of Guitarix virtual versatile amplification for Jack/Linux https://sourceforge.net/p/guitarix/git/ci/master/tree/

Branch from version 0.38.1 https://sourceforge.net/p/guitarix/git/ci/V0.38.1/tree/

GUI is recreated with JUCE. Added mono/stereo input option. Works with VST3 hosts on Windows 64-bit and macOS 64-bit Intel and M1. Preset handling is made via VST3 standard preset files.

# Building environment

Tools: XCode 13 on Mac, Visual Studio 2022 with WiX 3 (for making msi) on Windows.

Libraries: glib, glibmm, fftw3, libsndfile, boost-iostreams, boost-format, boost-thread, eigen3, pthreads (Windows only).

To install and build libraries I've used vcpkg (commit 38bb87c55 from June 3, 2022). Create subfolders vcpkg, vcpkg-x64-osx and vcpkg-arm64-osx at ../library, clone vcpkg there and install all libraries on Windows, Mac Intel and Mac M1. Use static build on Mac and dynamic on Windows (with exception for libsndfile). Please refer to ./Builds/MacOSX/install-libs* scripts for details. Use ./Builds/MacOSX/make_uni.sh to build universal binary versions of libs. Create ../library/msvc folder and put there msvcp140*, ucrtbase, vcruntime140* dlls from MS redistributable.

# Building and running

Project are in ./Builds folder. Please setup  Use Installer Scheme on Mac and GuitarixSetup project on Windows. Build results are in ../output. Mac version will run right after build, installer just adds VST3 presets to proper place. Windows version is more sophisticated since libraries are dynamic - bunch of dlls and proper regisrty key in nessesary, so use installer (or ) to have it proper setup. 

# Future development

Due to difference between platforms, some of Linux-specific code is handled roughly for the porting purposes. Going to make it in more compatible way when possible in order to merge with more recent versions of Linux version. GUI-heavy modules to be ported. Better preset handling (compatible with Linux version). There are standalone versions in there, but JUCE wrapper requires some work to be done for stable work.

If you encounder problems building or running Guitarix.vst, please email to gx@alexanian.name 