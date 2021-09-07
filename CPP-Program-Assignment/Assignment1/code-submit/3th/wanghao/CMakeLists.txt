cmake_minimum_required (VERSION 3.0)
project (Assignment1_wanghao)

find_path(GXX_PATH g++)
if(${GXX_PATH} STREQUAL "GXX_PATH-NOTFOUND")
    message(FATAL_ERROR "g++ not found, please install g++ or set GXX_PATH in CMakeLists.txt")
endif()

set(CMAKE_CXX_COMPILER  ${GXX_PATH}/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
install(TARGETS hello RUNTIME DESTINATION bin)
