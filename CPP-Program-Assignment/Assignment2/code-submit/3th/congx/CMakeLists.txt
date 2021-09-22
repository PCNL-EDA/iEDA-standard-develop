cmake_minimum_required(VERSION 3.14)

set(this congx)

project(this)

set(CMAKE_CXX_FLAGS "-g -Wall -O0 -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)

install(TARGETS astar RUNTIME DESTINATION bin)
