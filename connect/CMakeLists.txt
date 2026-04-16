cmake_minimum_required(VERSION 3.4)
project(connect)

add_library(connect STATIC ${CMAKE_CURRENT_SOURCE_DIR}/connect.cpp)
target_include_directories(connect PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})