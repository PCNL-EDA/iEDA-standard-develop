cmake_minimum_required (VERSION 3.16.3)

project (solution)

#Bring the headers(*.h) into the project
include_directories(include)

#Bring the source codes(*.cpp) into the project
file(GLOB SOURCES "src/*.cpp")

#Specify build target
add_executable(solution ${SOURCES})