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
set(SRC astar_data.cpp astar_solver.cpp solver.cpp)

if(GTEST STREQUAL "on")
  set(SRC gtest.cpp ${SRC})
  link_libraries(libgtest.a libgtest_main.a pthread)
else()
  set(SRC main.cpp ${SRC})
endif()

# compile source file to executable binary
add_executable(hello ${SRC})