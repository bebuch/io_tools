cmake_minimum_required(VERSION 3.12.4)

project(io_tools)


# interface target
add_library(io_tools INTERFACE)

target_include_directories(io_tools INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_include_directories(io_tools SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)
target_compile_definitions(io_tools INTERFACE)


# Setup package config
include(CMakePackageConfigHelpers)
set(CONFIG_PACKAGE_INSTALL_DIR lib/cmake/io_tools)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/io_tools-config-version.cmake
    VERSION 0.2
    COMPATIBILITY SameMajorVersion
)


# Install target
install(DIRECTORY include/io_tools DESTINATION include)


# Only export target when using imported targets
if(IO_TOOLS_HAS_IMPORTED_TARGETS)
    install(TARGETS io_tools
        EXPORT io_tools-targets
        DESTINATION lib)

    install(EXPORT io_tools-targets
        DESTINATION ${CONFIG_PACKAGE_INSTALL_DIR})

    install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/io_tools-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/io_tools-config-version.cmake
        DESTINATION ${CONFIG_PACKAGE_INSTALL_DIR})
endif()


# other subdirectories
# only add if not inside add_subdirectory()
option(IO_TOOLS_BUILD_TESTS "build all tests" OFF)
option(IO_TOOLS_BUILD_TESTS_CPP11 "build C++11 tests" OFF)
option(IO_TOOLS_BUILD_TESTS_CPP17 "build C++17 tests" OFF)

if(${IO_TOOLS_BUILD_TESTS} OR ${IO_TOOLS_BUILD_TESTS_CPP11} OR (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test/cpp11)
	add_test(NAME cpp11tests COMMAND cpp11tests)
endif()

if(${IO_TOOLS_BUILD_TESTS} OR ${IO_TOOLS_BUILD_TESTS_CPP17} OR (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(test/cpp17)
    add_test(NAME cpp17tests COMMAND cpp17tests)
endif()
