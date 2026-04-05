cmake_minimum_required(VERSION 3.10)
project(solver_app)

add_executable(solver_app solver.cpp)

target_link_libraries(solver_app PRIVATE
	formatter_ex
	solver
)

target_include_directories(solver_app PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../../formatter_ex_lib/include
	${CMAKE_CURRENT_SOURCE_DIR}/../../solver_lib/include
)