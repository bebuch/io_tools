#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)

# Build C++11 test
cd $PROJECT_DIR/test/cpp11
mkdir -p build
cd build
cmake ..
make

# Run C++11 tests
./tests


# Build C++17 test
cd $PROJECT_DIR/test/cpp17
mkdir -p build
cd build
cmake ..
make

# Run C++17 tests
./tests
