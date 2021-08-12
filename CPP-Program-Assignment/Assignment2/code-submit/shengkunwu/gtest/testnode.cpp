/*
@file: testnode.cpp
@brief: test the functions of the class node
@author: Shengkun Wu
@data: 2021/7/26
*/
#include <vector>
#include <gtest/gtest.h>
#include "graph.h"

TEST(Coord, coordfunct){
    printf("-----testing coordinate----\n");
    std::vector<Coordinate> vc={};
    Coordinate c1(1,1);
    vc.push_back(c1);
    Coordinate c2(2,3);
    vc.push_back(c2);
    ASSERT_TRUE(c2.checkIn(3,4));
    ASSERT_EQ(c1.connectDist(c2),0);
    Coordinate c3(1,2);
    ASSERT_EQ(c1.connectDist(c3),10);
    Coordinate c4(2,2);
    ASSERT_FALSE(c4.checkIn(2,2));
    ASSERT_EQ(c1.connectDist(c4),14);
    ASSERT_TRUE(c1.checkInVec(vc));
    ASSERT_FALSE(c3.checkInVec(vc));
    c2.deleteFrom(vc);
    ASSERT_FALSE(c2.checkInVec(vc));
    ASSERT_TRUE(c1.checkEq(c1));
    ASSERT_FALSE(c1.checkEq(c2));
    printf("-----end testing coordinate----\n");
}