cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp)

file (GLOB_RECURSE files *.cpp)
add_executable(main ACWing/main.cpp)
add_executable(text text.cpp)
