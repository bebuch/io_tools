#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)

# Build test
cd $PROJECT_DIR/test/cpp11
mkdir -p build
cd build
cmake ..
make

# Run the valid test
./tests
