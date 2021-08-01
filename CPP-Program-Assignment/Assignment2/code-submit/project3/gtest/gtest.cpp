/*
@file: gtest.cpp
@brief: definition of gtest functions
@author: Shengkun Wu
@data: 2021/7/26
*/
#include <vector>
#include <gtest/gtest.h>
#include "graph.h"


std::vector<std::vector<int> > testM(){
    int Matrix[4][8]={{0,0,0,0,1,1,1,1},
                      {0,0,0,0,0,0,1,1},
                      {1,1,1,0,1,0,0,0},
                      {1,0,0,0,0,0,0,0}};
    std::vector<std::vector<int> > M;
    
    for(int i=0; i<sizeof(Matrix)/sizeof(Matrix[0]);++i){
        std::vector<int> Mt;
        for(int j=0;j<sizeof(Matrix[0])/sizeof(Matrix[0][0]);++j){
            Mt.push_back(Matrix[i][j]);
        }
         M.push_back(Mt);
    }
    return M;
}

inline Coordinate get_start(){
    Coordinate start(0,0);
    return start;
}

inline Coordinate get_end(){
    Coordinate end(3,7);
    return end;
}

TEST(dist, distgraph)
{
    std::vector<std::vector<int> > M=testM();
    Coordinate start=get_start();
    Coordinate end=get_end();
    Graph G(M); //use M to generate a graph G
    Coordinate c1(4,1);
    Coordinate c2(5,2);
    ASSERT_FALSE(G.checkJump(c1,c2));
    G.genArround(M);
    //G.assignAllDist(start,end);
}

TEST(Coord, coordfunct){
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
    ASSERT_TRUE(c1.chekcInVec(vc));
    ASSERT_FALSE(c3.chekcInVec(vc));
    c2.deleteFrom(vc);
    ASSERT_FALSE(c2.chekcInVec(vc));
    ASSERT_TRUE(c1.checkEq(c1));
    ASSERT_FALSE(c1.checkEq(c2));
}

TEST(dist, minidist){
    std::vector<std::vector<int> > M=testM();
    Coordinate start=get_start();
    Coordinate end=get_end();
    Graph G(M);
    G.genArround(M);
    //G.printGraph();
    //G.printAlldist();
    std::vector<Coordinate> vc;
    G.assignDist(start,20);
    vc.push_back(start);
    Coordinate c1(0,1);
    vc.push_back(c1);
    G.assignDist(c1,11);
    Coordinate c2(1,0);
    vc.push_back(c2);
    G.assignDist(c2,10);
    Coordinate c3(1,1);
    vc.push_back(c3);
    G.assignDist(c3,9);
    ASSERT_EQ(c3._x, G.minDist(vc)._x);
    ASSERT_EQ(c3._y, G.minDist(vc)._y);
}

int mytest(){
    std::vector<std::vector<int> > M=testM();
    Coordinate start=get_start();
    Coordinate end=get_end();
    Graph G(M);
    G.genArround(M);
    G.printGraph();
    G.assignAllDist(start,end);
    G.printAlldist();
    printPath(G.reverseSearch(start,end));
    return 0;
}

/*
@brief: main function in google test
@details: call all google test functions
*/
int main(int argc, char *argv[])
{
    mytest();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
