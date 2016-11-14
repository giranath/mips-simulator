cmake_minimum_required(VERSION 3.0)

project(mips)

set(CMAKE_CXX_STANDARD 11)

# Main library
add_library(mips
	src/normal_register.cpp
	src/machine.cpp
	src/memory.cpp
	)
target_include_directories(mips PUBLIC include)

# Catch linking
add_Library(Catch INTERFACE)
target_include_directories(Catch INTERFACE Catch/include)

# Tests executables
enable_testing()

# Register's tests
add_executable(test_register 
	test/register.cpp)
target_link_libraries(test_register
	Catch
	mips)

# Machine's tests
add_executable(test_machine
	test/machine.cpp)
target_link_libraries(test_machine
	Catch
	mips)

# Memory's tests
add_executable(test_memory
	test/memory.cpp)
target_link_libraries(test_memory
	Catch
	mips)

add_test(NAME registers COMMAND test_register)
add_test(NAME machine COMMAND test_machine)
add_test(NAME memory COMMAND test_memory)
