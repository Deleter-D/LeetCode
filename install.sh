#!/bin/bash

cd ./build/
cmake ..

make -j8
make install

cd ..
