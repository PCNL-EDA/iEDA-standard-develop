cmake_minimum_required(VERSION 3.11)
project(Lvyaxing)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

add_executable(test1 test/test.cpp src/AStar.cpp src/Map.cpp)
add_executable(gtest1 test/gtest.cpp src/AStar.cpp src/Map.cpp)
target_link_libraries(gtest1 libgtest.a libgtest_main.a pthread)