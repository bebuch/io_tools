project(test)

# Add test cpp file
file(GLOB SOURCE_FILES "*.cpp")

add_executable(cpp17tests ${SOURCE_FILES})

target_link_libraries(cpp17tests PUBLIC io_tools GTest::GTest GTest::Main)

target_include_directories(cpp17tests PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET cpp17tests PROPERTY CXX_STANDARD 17)
