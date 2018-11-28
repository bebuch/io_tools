#!/bin/bash

# exit script on any error
set -e
set -o xtrace

PROJECT_DIR=$(pwd)
INSTALL_PATH=$PROJECT_DIR/../tmp/usr
mkdir -p $INSTALL_PATH

# Configure Project
mkdir -p $PROJECT_DIR/build
cd $PROJECT_DIR/build
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_PATH -DIO_TOOLS_BUILD_TESTS=ON ..

# Build test
make

# Run tests
test/cpp11/cpp11tests
test/cpp14/cpp14tests
test/cpp17/cpp17tests

# Install
make install

# Check install
git diff --no-index $INSTALL_PATH/include $PROJECT_DIR/include

CMAKE_FIND_FILE=$INSTALL_PATH/lib/cmake/io_tools/io_tools-config.cmake
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
cmake -DCMAKE_PREFIX_PATH=$INSTALL_PATH ../test-package
make
./test_io_tools_package
