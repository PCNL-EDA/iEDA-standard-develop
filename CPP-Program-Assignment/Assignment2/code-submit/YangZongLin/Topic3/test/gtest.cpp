/*
 * @Author: YangZongLin
 * @Date: 2021-08-1
 * @Description:
 * @FilePath: /Topic3/test/gtest.cpp
 * @copyright:
 */
#include "gtest/gtest.h"

#include "../include/project/Model.hpp"

TEST(canFindAWay, canReach) {
  astar::Model m;
  m.initMap(5, 5);
  m.addObstacle(0, 1);
  m.addObstacle(1, 1);
  m.addObstacle(2, 3);
  m.addObstacle(3, 1);
  m.addObstacle(4, 3);
  m.setStartPoint(0, 0);
  m.setEndPoint(4, 4);
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
  EXPECT_FALSE(m.showTheWay());
}
