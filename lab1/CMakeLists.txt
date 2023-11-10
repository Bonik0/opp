cmake_minimum_required(VERSION 3.10)
project(gtest)
enable_testing()

add_subdirectory(googletest) 
include_directories(googletest/googletest/include)
add_executable(test1 test1.cpp)
target_link_libraries(test1 gtest_main)

add_test(NAME BASIC COMMAND test1)