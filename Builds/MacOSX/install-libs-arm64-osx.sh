#!/bin/bash

git clone https://github.com/Microsoft/vcpkg.git vcpkg-arm64-osx
cd vcpkg-arm64-osx
./bootstrap-vcpkg.sh
export VCPKG_OSX_DEPLOYMENT_TARGET=11.0
./vcpkg install glib:arm64-osx
./vcpkg install glibmm:arm64-osx
./vcpkg install fftw3:arm64-osx
./vcpkg install libsndfile:arm64-osx
./vcpkg install boost-iostreams:arm64-osx
./vcpkg install boost-format:arm64-osx
./vcpkg install boost-thread:arm64-osx
./vcpkg install eigen3:arm64-osx
