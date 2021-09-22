cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "-g -std=c++11")

include_directories(
    ${PROJECT_SOURCE_DIR}/data
    ${PROJECT_SOURCE_DIR}/algorithm
    ${PROJECT_SOURCE_DIR}/flow)
    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(SRC 
    ${PROJECT_SOURCE_DIR}/utils/MyUtils.cc
    ${PROJECT_SOURCE_DIR}/algorithm/AstarAlgorithm.cc
    ${PROJECT_SOURCE_DIR}/flow/FindPath.cc
)
add_library(libfindoptimalpath
    ${SRC}
)

message(${PROJECT_SOURCE_DIR})
link_libraries(libfindoptimalpath)

# add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/main.cc)
add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/tests/test.cc)

target_link_libraries(${EXECUTABLE_NAME} libgtest.a libgtest_main.a pthread)