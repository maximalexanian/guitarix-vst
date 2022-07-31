#!/bin/bash

#start from library with vcpkg-x64-osx and vcpkg-arm64-osx folders built

mkdir vcpkg-mac
cd vcpkg-mac
ln -s ../vcpkg-x64-osx/installed/x64-osx x64-osx
ln -s ../vcpkg-arm64-osx/installed/arm64-osx arm64-osx
mkdir uni-osx
cd uni-osx
mkdir lib
cd ..
mkdir debug
cd debug
mkdir lib

cd ../../../x64-osx/lib
for f in $(ls *.a)
do
    lipo $f ../../../../vcpkg-arm64-osx/installed/arm64-osx/lib/$f -output ../../../../vcpkg-mac/uni-osx/lib/$f -create
done

cd ../debug/lib
for f in $(ls *.a)
do
    lipo $f ../../../../../vcpkg-arm64-osx/installed/arm64-osx/debug/lib/$f -output ../../../../../vcpkg-mac/uni-osx/debug/lib/$f -create
done
