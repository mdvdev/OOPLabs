cmake_minimum_required(VERSION 3.27)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(lab2 src/main.cpp
        include/BinarySearchTree.h
        src/BinarySearchTree.cpp)
