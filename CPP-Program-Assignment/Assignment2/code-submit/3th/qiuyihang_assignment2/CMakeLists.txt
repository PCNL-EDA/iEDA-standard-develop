cmake_minimum_required (VERSION 3.16.3)

project (solution)

include_directories(include)

# for main.cpp
file(GLOB SOURCES src/astar.cpp src/display.cpp src/gridmap.cpp src/main.cpp)
add_executable(solution ${SOURCES})
target_link_libraries(solution libgtest.a libgtest_main.a pthread)

# for test.cpp
# file(GLOB SOURCES src/astar.cpp src/display.cpp src/gridmap.cpp src/test.cpp)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GTEST")
# add_executable(solution ${SOURCES})
# target_link_libraries(solution libgtest.a libgtest_main.a pthread)
