cmake_minimum_required(VERSION 3.12.4)

project(test_io_tools_package)

find_package(io_tools REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} test.cpp)

include_directories(SYSTEM ${io_tools_INCLUDE_DIR})
