#!/bin/bash

mkdir build

cd ./build/
cmake ..

make -j32
make install
