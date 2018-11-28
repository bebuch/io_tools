project(test)

# Add test cpp file
file(GLOB CPP11_SOURCE_FILES "../cpp11/*.cpp")
file(GLOB CPP14_SOURCE_FILES "../cpp14/*.cpp")
file(GLOB CPP17_SOURCE_FILES "../cpp17/*.cpp")

add_executable(cpp17tests ${CPP11_SOURCE_FILES} ${CPP14_SOURCE_FILES} ${CPP17_SOURCE_FILES})

set_property(TARGET cpp17tests PROPERTY CXX_STANDARD 17)
set_property(TARGET cpp17tests PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(cpp17tests PUBLIC io_tools GTest::GTest GTest::Main)

target_include_directories(cpp17tests PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
