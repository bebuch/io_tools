#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)

# Build test
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$PROJECT_DIR/usr ..
make

# Run tests
test/cpp11/cpp11tests
test/cpp17/cpp17tests

# Install
make install

# Check install
git diff --no-index $PROJECT_DIR/usr/include $PROJECT_DIR/include
