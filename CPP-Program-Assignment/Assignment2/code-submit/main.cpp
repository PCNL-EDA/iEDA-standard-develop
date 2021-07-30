/**
 * @file     main.cpp
 * @brief    source code implement astart algorithm.    
 * @details  this file includes all definitions of function decleared in tmp.hpp and astart.h.
 * @author   liujikang
 * @date     2021/07/28
 * @version  1.0.0
 * @note     all the definition of functions located in this project should define in this file. 
 * @copyright liujikang
 * 
 */
#include <gtest/gtest.h>
#include "include/project/astart.h"


TEST(TmpAddTest, CheckValues) {
  // ASSERT_EQ(tmp::add(1, 2), 3);
  EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  Astart::Node * start;
  Astart::Node * endNode;
  Astart::initMapArr(start, endNode);
  std::cout << "初始图状态：" <<std::endl;
  Astart::printMap();
  std::cout << "最短路径下标序列：" <<std::endl;
  Astart::searchPath(start, endNode);
  std::cout << "图中展示路径：" <<std::endl;
  Astart::printMap();

  return RUN_ALL_TESTS();
}
