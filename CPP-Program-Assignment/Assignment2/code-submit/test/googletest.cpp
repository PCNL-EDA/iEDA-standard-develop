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

  //EXPECT_EQ(node.get_index_x(), 0);
  EXPECT_EQ(node.get_index_y(), 0);
}

} // namespace