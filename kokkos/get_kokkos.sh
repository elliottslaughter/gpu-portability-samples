#!/bin/bash

set -e

if [[ ! -d kokkos ]]; then
    git clone -b develop https://github.com/kokkos/kokkos.git
fi

cd kokkos
mkdir build
cd build
cmake -DCMAKE_CXX_COMPILER=$PWD/../bin/nvcc_wrapper \
    -DKokkos_ENABLE_CUDA=on \
    -DKokkos_ENABLE_OPENMP=off \
    -DKokkos_ENABLE_SERIAL=on \
    -DCMAKE_INSTALL_PREFIX="$PWD/../install" \
    ..
make install -j8
