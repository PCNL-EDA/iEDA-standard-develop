CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0-rc3)
PROJECT(ASTAR)

# SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/third_party/googletest
)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g3 -ggdb")

###################################
###             exec
###################################

ADD_EXECUTABLE(Astar  ${PROJECT_SOURCE_DIR}/src/Astar.cpp )
TARGET_LINK_LIBRARIES(Astar libgtest.a libgtest_main.a pthread)

###################################
###             test
###################################

ADD_EXECUTABLE(test ${PROJECT_SOURCE_DIR}/test/gtest.cpp )
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/third_party/googletest)
TARGET_LINK_LIBRARIES(test libgtest.a libgtest_main.a pthread)