/*
 * @Author: YangZongLin
 * @Date: 2021-08-1
 * @Description:
 * @FilePath: /Topic3/test/gtest.cpp
 * @copyright:
 */
#include "gtest/gtest.h"

#include "../include/project/Model.hpp"

TEST(canFindAWay1, sample) {
  astar::Model m;
  m.initMap(4, 8);
  m.addObstacle(0, 4);
  m.addObstacle(0, 5);
  m.addObstacle(0, 6);
  m.addObstacle(0, 7);
  m.addObstacle(1, 5);
  m.addObstacle(1, 6);
  m.addObstacle(1, 7);
  m.addObstacle(2, 0);
  m.addObstacle(2, 1);
  m.addObstacle(2, 3);
  m.addObstacle(2, 4);
  m.addObstacle(3, 0);
  m.setStartPoint(0, 0);
  m.setEndPoint(3, 7);
  m.findBestWay();
  EXPECT_TRUE(m.showTheWay());
}

TEST(canFindAWay2, canReach) {
  astar::Model m;
  m.initMap(5, 5);
  m.addObstacle(0, 1);
  m.addObstacle(1, 1);
  m.addObstacle(2, 3);
  m.addObstacle(3, 1);
  m.addObstacle(4, 3);
  m.setStartPoint(0, 0);
  m.setEndPoint(4, 4);
  m.findBestWay();
  EXPECT_TRUE(m.showTheWay());
}

TEST(cantFindAWay, cantReach) {
  astar::Model m;
  m.initMap(4, 4);
  m.addObstacle(0, 2);
  m.addObstacle(1, 0);
  m.addObstacle(1, 2);
  m.addObstacle(2, 1);
  m.setStartPoint(0, 0);
  m.setEndPoint(3, 3);
  m.findBestWay();
  EXPECT_FALSE(m.showTheWay());
}
