#!/bin/bash

mkdir build

cd ./build/
cmake .. -G "MinGW Makefiles"

mingw32-make -j32
mingw32-make install
