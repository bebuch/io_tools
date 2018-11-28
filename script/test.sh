#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)

# Configure Project
mkdir -p $PROJECT_DIR/build
cd $PROJECT_DIR/build
cmake -DCMAKE_INSTALL_PREFIX=$PROJECT_DIR/usr -DIO_TOOLS_BUILD_TESTS=ON ..

# Build test
make

# Run tests
test/cpp11/cpp11tests
test/cpp14/cpp14tests
test/cpp17/cpp17tests

# Install
make install

# Check install
git diff --no-index $PROJECT_DIR/usr/include $PROJECT_DIR/include

CMAKE_FIND_FILE=$PROJECT_DIR/usr/lib/cmake/io_tools/io_tools-config.cmake
if [ -a $CMAKE_FIND_FILE ]
then
    echo "$CMAKE_FIND_FILE - Found"
else
    echo "$CMAKE_FIND_FILE - Not found"
    false
fi

# Check install by example project
mkdir -p $PROJECT_DIR/build-package-test
cd $PROJECT_DIR/build-package-test
cmake -DCMAKE_PREFIX_PATH=$PROJECT_DIR/usr ../test-package
make
./test
