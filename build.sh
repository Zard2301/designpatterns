#!/bin/bash

rm -rf output build
make clean

set -e

mkdir -p build
cd build
if [ -n "$1" ]
then
    cmake .. -DBUILD_DP_TYPE=$1
else
    cmake ..
fi

make
make install