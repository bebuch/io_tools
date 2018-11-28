project(test)

# Add test cpp file
file(GLOB CPP11_SOURCE_FILES "../cpp11/*.cpp")
file(GLOB CPP14_SOURCE_FILES "../cpp14/*.cpp")

add_executable(cpp14tests ${CPP11_SOURCE_FILES} ${CPP14_SOURCE_FILES})

set_property(TARGET cpp14tests PROPERTY CXX_STANDARD 14)
set_property(TARGET cpp14tests PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(cpp14tests PUBLIC io_tools GTest::GTest GTest::Main)

target_include_directories(cpp14tests PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
