#!/bin/bash

git clone https://github.com/Microsoft/vcpkg.git vcpkg-x64-osx
cd vcpkg-x64-osx
./bootstrap-vcpkg.sh
export VCPKG_OSX_DEPLOYMENT_TARGET=10.11
./vcpkg install glib:x64-osx
./vcpkg install glibmm:x64-osx
./vcpkg install fftw3:x64-osx
./vcpkg install libsndfile:x64-osx
./vcpkg install boost-iostreams:x64-osx
./vcpkg install boost-format:x64-osx
./vcpkg install boost-thread:x64-osx
./vcpkg install eigen3:x64-osx
