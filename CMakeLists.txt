cmake_minimum_required(VERSION 3.13)
project(LoopFun)
set(CMAKE_CXX_STANDARD 14)

# Change the path from /Users/mercer/CLionProjects to the path with catch.cpp
include_directories(/Users/mercer/CLionProjects)
include_directories(cmake-build-debug)

add_executable(LoopFun LoopFunTest.cpp)