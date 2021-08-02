cmake_minimum_required(VERSION 3.11)
project(Lvyaxing)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

add_executable(simple_astar test/simple_astar.cpp src/AStar.cpp src/Map.cpp)
add_executable(simple_astar_test test/simple_astar_test.cpp src/AStar.cpp src/Map.cpp)
target_link_libraries(simple_astar_test libgtest.a libgtest_main.a pthread)