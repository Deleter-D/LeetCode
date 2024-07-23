#!/bin/bash

cd ./build/
cmake ..

make -j16
make install

cd ..
