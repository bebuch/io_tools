#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)

# Build test
mkdir -p build
cd build
cmake ..
make

# Run tests
test/cpp11/cpp11tests
test/cpp17/cpp17tests
