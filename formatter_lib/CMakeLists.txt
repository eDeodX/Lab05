cmake_minimum_required(VERSION 3.10)
project(formatter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter STATIC ~/eDeodX/workspace/tasks/HM3/formatter_lib/sources/formatter.cpp)
include_directories(~/eDeodX/workspace/tasks/HM3/formatter_lib/include)