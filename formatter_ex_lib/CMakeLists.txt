cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

add_library(formatter_ex STATIC sources/formatter_ex.cpp)

target_include_directories(formatter_ex PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib/include
)

target_link_libraries(formatter_ex PUBLIC formatter)