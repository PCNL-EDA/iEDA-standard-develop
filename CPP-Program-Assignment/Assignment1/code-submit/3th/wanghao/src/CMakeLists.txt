cmake_minimum_required (VERSION 3.1)
project (Assignment1_wanghao)

find_path(GXX_PATH g++)
if(${GXX_PATH} STREQUAL "GXX_PATH-NOTFOUND")
    message(FATAL_ERROR "g++ not found, please install g++ or set GXX_PATH in CMakeLists.txt")
endif()

set(CMAKE_CXX_COMPILER  ${GXX_PATH}/g++)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Og)

include_directories(../include)

add_executable(hello main.cpp)