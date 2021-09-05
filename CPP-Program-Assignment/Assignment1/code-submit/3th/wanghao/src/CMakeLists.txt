find_path(GXX_PATH g++)
if(${GXX_PATH} STREQUAL "GXX_PATH-NOTFOUND")
    message(FATAL_ERROR "g++ not found, please install g++ or set GXX_PATH in CMakeLists.txt")
endif()

set(CMAKE_CXX_COMPILER  ${GXX_PATH}/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fsanitize=address")
link_libraries("-fsanitize=address")

aux_source_directory(. SRC)
add_executable(hello ${SRC})