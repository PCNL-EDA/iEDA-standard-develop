cmake_minimum_required(VERSION 3.0)

project(gtest)

include_directories(../include)

link_libraries(gtest)

link_libraries(pthread)

add_executable(gexe testgraph.cpp testnode.cpp ../src/graph.cpp ../src/node.cpp)

