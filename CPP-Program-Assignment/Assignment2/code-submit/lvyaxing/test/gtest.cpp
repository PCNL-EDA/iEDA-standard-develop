/**
 * @file gtest.cpp
 * @author lvyaxing
 * @brief googletest file
 * @version 0.1
 * @date 2021-08-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "gtest/gtest.h"
#include"../include/AStar.h"
#include"../include/Node.h"
#include"../include/Coordinate.h"
#include"../include/Map.h"
namespace {
  TEST(RoutingTest, Reached)
  {
    MyAStar::Map a(4,8);
    std::vector<std::vector<int>>_obstaclelist=a.getMap({{0, 2},
                                                         {0, 3},
                                                         {1, 2},
                                                         {3, 2},
                                                         {4, 0},
                                                         {4, 2},
                                                         {5, 0},
                                                         {5, 1},
                                                         {6, 0},
                                                         {6, 1},
                                                         {7, 0},
                                                         {7, 1}});
    //<Set start and end node
    MyAStar::Node _start(0,0);
    MyAStar::Node _end(3,7);									   
    MyAStar::AStar astar(_obstaclelist);
    //EXPECT_TRUE(astar.getPath(_start, _end, false).size());
    EXPECT_EQ(8,astar.getPath(_start, _end, false).size());
  }
}  // namespace
