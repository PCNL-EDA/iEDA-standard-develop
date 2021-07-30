cmake_minimum_required(VERSION 3.0)

project(graph)

include_directories(../include)

link_libraries(gtest)

link_libraries(pthread)

add_executable(gtextexe gtest.cpp ../src/graph.cpp)

