cmake_minimum_required(VERSION 3.12.4)

project(io_tools LANGUAGES CXX)


# interface target
add_library(${PROJECT_NAME} INTERFACE)

set(CMAKE_CXX_STANDARD 11)

target_include_directories(${PROJECT_NAME}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(${PROJECT_NAME}
    SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)
target_compile_definitions(${PROJECT_NAME} INTERFACE)


# Setup package config
set(INCLUDE_INSTALL_DIR include)
set(LIB_INSTALL_DIR lib)
set(CONFIG_PACKAGE_INSTALL_DIR ${LIB_INSTALL_DIR}/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
configure_package_config_file(${PROJECT_NAME}-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
    INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${PROJECT_NAME}/cmake
    PATH_VARS INCLUDE_INSTALL_DIR)

# Install target
install(DIRECTORY include/${PROJECT_NAME}
    DESTINATION ${INCLUDE_INSTALL_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
    DESTINATION ${LIB_INSTALL_DIR}/cmake/${PROJECT_NAME})


# other subdirectories
# only add if not inside add_subdirectory()
option(IO_TOOLS_BUILD_TESTS "build all tests" OFF)
option(IO_TOOLS_BUILD_TESTS_CPP11 "build C++11 tests" OFF)
option(IO_TOOLS_BUILD_TESTS_CPP14 "build C++14 tests" OFF)
option(IO_TOOLS_BUILD_TESTS_CPP17 "build C++17 tests" OFF)

if(${IO_TOOLS_BUILD_TESTS} OR ${IO_TOOLS_BUILD_TESTS_CPP11})
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test/cpp11)
	add_test(NAME cpp11tests COMMAND cpp11tests)
endif()

if(${IO_TOOLS_BUILD_TESTS} OR ${IO_TOOLS_BUILD_TESTS_CPP14})
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test/cpp14)
    add_test(NAME cpp14tests COMMAND cpp14tests)
endif()

if(${IO_TOOLS_BUILD_TESTS} OR ${IO_TOOLS_BUILD_TESTS_CPP17})
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test/cpp17)
    add_test(NAME cpp17tests COMMAND cpp17tests)
endif()
