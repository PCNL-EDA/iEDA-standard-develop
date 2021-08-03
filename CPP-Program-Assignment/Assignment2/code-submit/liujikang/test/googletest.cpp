/**
 * @brief       test the function
 * @author      liujikang
 * @date        2021-08-1
 * @copyright   liujikang 
 */ 

#include "gtest/gtest.h"
#include "../include/Node.h"
#include "../include/GridMap.h"
#include "../include/Process.h"

namespace {

TEST(NodeFunc, func1) {
  astar::Node node;
  EXPECT_EQ(node.get_index_x(), 0);
}

TEST(NodeFunc, func2) {
  astar::Node node;
  node.set_index_x(1);
  EXPECT_EQ(node.get_index_x(), 1);
}

TEST(NodeFunc, func3) {
  astar::Node node;
  node.set_cost_start(1);
  node.set_cost_end(9);
  node.set_total_cost(node.get_start_cost() + node.get_end_cost());
  EXPECT_EQ(node.get_total_cost(), 10);
}

///< test the function of GribMap.h
TEST(MapFunc, func1) {
  astar::GridMap<astar::Node> map;
  map.initArrNode();
  EXPECT_NE(map.get_arrNode(), nullptr);
}

///< test process functions
TEST(Astarfunc, func) {
  astar::Process astar_proc;
  astar_proc.setMapSize(4, 8);
  astar_proc.setStartnode(0, 0);
  astar_proc.setEndNode(3, 7);
  astar_proc.setObstacleNode({ {0, 4}, {0, 5}, {0, 6}, {0, 7},
                               {1, 5}, {1, 6}, {1, 7}, {2, 0},
                               {2, 1}, {2, 3}, {2, 4}, {3, 0} });
  EXPECT_EQ(astar_proc.findPath(), true);
}

}  // namespace
