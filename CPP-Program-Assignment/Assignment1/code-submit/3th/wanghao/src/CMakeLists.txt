if(BUILD_MODE STREQUAL "release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
elseif(BUILD_MODE STREQUAL "debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address")
  link_libraries("-fsanitize=address")
endif()

aux_source_directory(. SRC)
add_executable(hello ${SRC})