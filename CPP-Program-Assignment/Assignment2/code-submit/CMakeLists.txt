cmake_minimum_required(VERSION 3.15)


project(
  ${CMAKE_PROJECT_NAME}Tests
  LANGUAGES CXX
)

include_directories(include)

add_executable(exe test/tmp_test.cpp src/tmp.cpp)





