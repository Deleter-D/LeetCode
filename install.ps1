if(-not (Test-Path "./build"))
{
    mkdir build
}

cd ./build/
cmake .. -G "MinGW Makefiles"

make -j32
make install

cd ..