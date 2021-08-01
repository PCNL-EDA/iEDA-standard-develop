cmake_minimum_required(VERSION 3.16.3)

project(
    "astar"
    VERSION 1.0.0
    LANGUAGES CXX
)

include_directories("include")

add_library(modelLib src/Model.cpp)

add_executable(testExe test/sample.cpp src/Model.cpp)

add_executable(gtestExe test/gtest.cpp src/Model.cpp)

target_link_libraries(gtestExe libgtest.a libgtest_main.a pthread)