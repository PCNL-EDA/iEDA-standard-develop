cmake_minimum_required(VERSION 3.14)

project(congx)

set(CMAKE_CXX_FLAGS "-g -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

install(TARGETS main RUNTIME DESTINATION bin)