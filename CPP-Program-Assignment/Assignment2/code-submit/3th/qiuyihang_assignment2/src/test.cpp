/**
 * @file test.cpp
 * @brief The entry of GoogleTest.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "../include/astar.h"
#include "../include/gridmap.h"
#include "gtest/gtest.h"

TEST(canFindAWay, sample1) {
  resource::Display display;
  data::GridMap gridmap;
  algorithms::AStar astar;
  display.parseMapFile();
  gridmap.createGridMap(display);
  Point *point =
      astar.findWay(gridmap.set_start_point(0, 0), gridmap.set_end_point(3, 7),
                    gridmap.get_map_(), display);
  EXPECT_TRUE(astar.foundWay());
}

TEST(notFindAWay, sample2) {
  resource::Display display;
  data::GridMap gridmap;
  algorithms::AStar astar;
  display.parseMapFile();
  gridmap.createGridMap(display);
  Point *point =
      astar.findWay(gridmap.set_start_point(2, 1), gridmap.set_end_point(0, 7),
                    gridmap.get_map_(), display);
  EXPECT_TRUE(astar.foundWay());
}
