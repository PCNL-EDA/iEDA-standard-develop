cmake_minimum_required(VERSION 3.16.3)

project (Assignment1_pro)
include_directories(include)
aux_source_directory(./src CPPSRC)
add_executable(Assignment1.out main.cpp ${CPPSRC})

if (debug STREQUAL "1")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall -ggdb3 -O0")
else()
SET(CMAKE_BUILD_TYPE "RELEASE")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -Wall -O3")
endif()
