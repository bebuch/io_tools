#!/bin/bash

# exit script on any error
set -e
set -o xtrace

# Build test
cd test
mkdir -p build
cd build
cmake ..
make

# Run the valid test
./tests
