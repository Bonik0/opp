cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab3_lib ${SOURCES})
add_executable(lab3 main.cpp)

target_link_libraries(lab3 PRIVATE lab3_lib)

enable_testing()

add_subdirectory(googletest)
add_executable(test_app test.cpp)
target_link_libraries(test_app gtest_main gmock_main lab3_lib)