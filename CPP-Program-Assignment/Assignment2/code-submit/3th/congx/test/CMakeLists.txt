set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.cc)
TARGET_LINK_LIBRARIES(main astar)


add_executable(random_astar random_test.cc)
TARGET_LINK_LIBRARIES(random_astar astar)

add_executable(gtest_astar google_test.cc)
TARGET_LINK_LIBRARIES(gtest_astar libgtest.a libgtest_main.a pthread astar)

