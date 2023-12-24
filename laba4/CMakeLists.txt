cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


enable_testing()

add_subdirectory(googletest)
add_executable(test_app test.cpp)
target_link_libraries(test_app gtest_main gmock_main)