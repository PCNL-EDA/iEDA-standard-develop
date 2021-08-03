cmake_minimum_required(VERSION 3.11)
project(ASTAR)


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(
${PROJECT_SOURCE_DIR}/include
#${PROJECT_SOURCE_DIR}/src
)


add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp src/process.cpp)
add_executable(test_astar ${PROJECT_SOURCE_DIR}/test/googletest.cpp src/process.cpp)
target_link_libraries(test_astar libgtest.a libgtest_main.a pthread)
