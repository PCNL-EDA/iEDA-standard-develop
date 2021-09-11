cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "-g -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(SRC 
    ${PROJECT_SOURCE_DIR}/src/Graph.cc
    ${PROJECT_SOURCE_DIR}/src/MyUtils.cc
    ${PROJECT_SOURCE_DIR}/src/People.cc
)
add_library(libeuler 
    ${SRC}
)

message(${PROJECT_SOURCE_DIR})
link_libraries(libeuler)

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/main.cc)