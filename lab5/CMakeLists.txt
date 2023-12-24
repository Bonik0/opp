cmake_minimum_required(VERSION 3.10)

project(lab05)


add_executable(${CMAKE_PROJECT_NAME} main.cpp)

enable_testing()

add_subdirectory(googletest)
add_executable(test_app test.cpp)
target_link_libraries(test_app gtest_main gmock_main)