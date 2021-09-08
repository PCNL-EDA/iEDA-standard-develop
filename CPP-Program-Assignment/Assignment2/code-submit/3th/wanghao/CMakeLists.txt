cmake_minimum_required (VERSION 3.0)
project (Assignment2_wanghao)

# export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set compiler and flags
find_path(GXX_PATH g++)
if(${GXX_PATH} STREQUAL "GXX_PATH-NOTFOUND")
    message(FATAL_ERROR "g++ not found, please install g++ or set GXX_PATH in CMakeLists.txt")
endif()
set(CMAKE_CXX_COMPILER  ${GXX_PATH}/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# go into subdirectory and continue cmake
add_subdirectory(src)

# install executable(RUNTIME) to path(DESTINATION)
install(TARGETS hello RUNTIME DESTINATION bin)