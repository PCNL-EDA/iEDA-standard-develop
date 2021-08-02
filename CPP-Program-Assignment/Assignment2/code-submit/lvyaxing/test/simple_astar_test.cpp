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
  TEST(RoutingTest, Reached)
  {
    MyAStar::Map a(4,8);
   std::vector<std::vector<int>>obstacle_list=a.getMap({{2,0},
                                                       {3,0},
                                                       {2,1},
                                                       {2,3},
                                                       {0,4},
                                                       {2,4},
                                                       {0,5},
                                                       {1,5},
                                                       {0,6},
                                                       {1,6},
                                                       {0,7},
                                                       {1,7}});
    //<Set start and end node
    MyAStar::Node start_node(0,0);
    MyAStar::Node end_node(3,7);									   
    MyAStar::AStar astar(obstacle_list);
    //EXPECT_TRUE(astar.getPath(start_node, end_node, false).size());
    EXPECT_EQ(8,astar.getPath(start_node, end_node, false).size());
  }