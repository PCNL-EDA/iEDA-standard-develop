#include "project/tmp.hpp"

#include "project/astart.h"

#include <gtest/gtest.h>

TEST(TmpAddTest, CheckValues)
{
  ASSERT_EQ(tmp::add(1, 2), 3);
  EXPECT_TRUE(true);
}
/*
TEST(TmpAddTest, CheckSub)
{
  ASSERT_EQ(tmp::sub(3, 1), 2);
  EXPECT_FALSE(true);
}
*/
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  /*---------------------------------------------------------------------*/
  Astart::Node * start;
    Astart::Node * endNode;

    Astart::init_mapArr(start, endNode);
    std::cout << "初始图状态：" <<std::endl;
    Astart::print_map();
    std::cout << "最短路径下标序列：" <<std::endl;
    Astart::search_path(start, endNode);
    std::cout << "图中展示路径：" <<std::endl;
    Astart::print_map();
  
  return RUN_ALL_TESTS();
}
