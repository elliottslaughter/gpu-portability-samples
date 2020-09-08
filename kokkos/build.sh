#!/bin/bash

set -e

if [[ ! -d build ]]; then
    mkdir build
    pushd build
    cmake .. -DCMAKE_PREFIX_PATH=$PWD/../kokkos/install -DCMAKE_CXX_COMPILER=$PWD/../kokkos/install/bin/nvcc_wrapper -DCMAKE_CXX_EXTENSIONS=Off
    popd
fi

make -C build
