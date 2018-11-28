project(test)

# Add test cpp file
file(GLOB CPP11_SOURCE_FILES "../cpp11/*.cpp")

add_executable(cpp11tests ${CPP11_SOURCE_FILES})

set_property(TARGET cpp11tests PROPERTY CXX_STANDARD 11)
set_property(TARGET cpp11tests PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(cpp11tests PUBLIC io_tools GTest::GTest GTest::Main)

target_include_directories(cpp11tests PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
