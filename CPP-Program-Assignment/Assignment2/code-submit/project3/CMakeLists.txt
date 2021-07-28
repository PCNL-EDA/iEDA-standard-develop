cmake_minimum_required(VERSION 3.0)

project(graph)

include_directories(include)

add_executable(myexe main.cpp src/graph.cpp src/mytest.cpp)

