cmake_minimum_required(VERSION 3.15)
project(ASTAR)

include_directories(${PROJECT_SOURCE_DIR}include
${PROJECT_SOURCE_DIR} /google/googletest
)#googletest的路径

add_library(lvyaxing 
${PROJECT_SOURCE_DIR} src/AStar.cpp src/Map.cpp
)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

add_executable(test1 ${PROJECT_SOURCE_DIR}/test/test.cpp)
target_link_libraries(test1 lvyaxing)

add_executable(gtest1 ${PROJECT_SOURCE_DIR}/ test/gtest.cpp)
link_directories(${PROJECT_SOURCE_DIR}/google/googletest)#google的路径
target_link_libraries(gtest1 libgtest.a libgtest_main.a pthread lvyaxing)
