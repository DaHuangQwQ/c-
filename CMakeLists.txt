cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
file (GLOB_RECURSE files *.cpp)

add_executable(untitled main.cpp)

add_executable(text text.cpp)



add_executable(main1 "luo gu/main1.cpp")

add_executable(836 ACWing/836.cpp)
add_executable(P1825 "luo gu/P1825.cpp")
add_executable(P1101 "luo gu/P1101.cpp")
add_executable(P1162 "luo gu/P1162.cpp")
add_executable(P2895 "luo gu/P2895.cpp")
add_executable(P1019 "luo gu/P1019.cpp")
add_executable(P1551 "luo gu/P1551.cpp")
add_executable(P1536 "luo gu/P1536.cpp")
add_executable(P3370 "luo gu/P3370.cpp")
add_executable(837 ACWing/837.cpp)