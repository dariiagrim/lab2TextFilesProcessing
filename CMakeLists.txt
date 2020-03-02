cmake_minimum_required(VERSION 3.15)
project(Lab2Prog)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2Prog main.cpp)

target_link_libraries(Lab2Prog stdc++fs)