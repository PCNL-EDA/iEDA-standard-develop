/**
 * @file gtest.cpp
 * @brief The entry of GoogleTest.
 * @author DANGPENG (dangpeng21@mails.ucas.ac.cn)
 * @version 1.0
 * @date 2021-11-08
 * @copyright Copyright (c) 2021  DANGPENG
 */
#include "../include/Astar.h"
#include "gtest/gtest.h"

using namespace ::testing;

TEST(RoutingTest, Reached)
{
  Node beginPosition = {0, 0};
  Node endPosition = {3, 7};
  EXPECT_TRUE( compute_H(endPosition, beginPosition) );
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return 0;
}