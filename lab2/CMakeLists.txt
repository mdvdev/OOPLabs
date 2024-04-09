cmake_minimum_required(VERSION 3.27)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(lab2 src/main.cpp
        include/BinarySearchTree.h
        src/BinarySearchTree.cpp)
