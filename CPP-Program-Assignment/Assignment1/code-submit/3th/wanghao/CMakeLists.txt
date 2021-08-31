cmake_minimum_required (VERSION 3.0)
project (Assignment1_wanghao)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
install(TARGETS hello RUNTIME DESTINATION bin)
