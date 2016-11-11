cmake_minimum_required(VERSION 3.0)

project(mips)

set(CMAKE_CXX_STANDARD 11)

# Main library
add_library(mips
	src/normal_register.cpp
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
add_test(NAME registers COMMAND test_register)
