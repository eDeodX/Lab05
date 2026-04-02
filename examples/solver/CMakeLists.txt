cmake_minimum_required(VERSION 3.10)
project(solver_app)

add_executable(solver_app solver.cpp)

target_link_libraries(solver_app PRIVATE
	formatter_ex
	solver
)

target_include_directories(solver_app PRIVATE
	~/eDeodX/workspace/tasks/HM3/formatter_ex_lib/include
	~/eDeodX/workspace/tasks/HM3/solver_lib/include
)