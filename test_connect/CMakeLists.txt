cmake_minimum_required(VERSION 3.4)
project(test_connect)

add_executable(test_connect ${CMAKE_CURRENT_SOURCE_DIR}/GMOCK.cpp)
target_link_libraries(test_connect PUBLIC gmock gmock_main connect)