# config more compiler flags
if(BUILD_MODE STREQUAL "release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
elseif(BUILD_MODE STREQUAL "debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g") #-fsanitize=address")
  # link_libraries("-fsanitize=address")
endif()

# set include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# collect cpp source files
aux_source_directory(. SRC)

# compile source file to executable binary
add_executable(hello ${SRC})