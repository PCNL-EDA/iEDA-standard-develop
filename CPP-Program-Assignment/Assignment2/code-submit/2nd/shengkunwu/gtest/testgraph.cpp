/*
@file: gtest.cpp
@brief: definition of gtest functions
@author: Shengkun Wu
@data: 2021/7/26
*/
#include <vector>
#include <gtest/gtest.h>
#include "graph.h"


std::vector<std::vector<int> > setM(){
    int Matrix[5][8]={{0,0,0,0,1,1,1,1},
                      {0,0,0,0,1,0,1,1},
                      {1,1,1,0,1,0,0,0},
                      {1,0,0,0,1,0,0,0},
                      {1,1,1,0,0,0,1,0}};
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

inline Coordinate setStart(){
    Coordinate start(0,0);
    return start;
}

inline Coordinate setEnd(){
    Coordinate end(4,7);
    return end;
}

TEST(dist, distgraph)
{
    printf("-----testing graph ---\n");
    std::vector<std::vector<int> > M=setM();
    Coordinate start=setStart();
    Coordinate end=setEnd();
    Graph G(M); //use M to generate a graph G
    Coordinate c1(4,1);
    Coordinate c2(5,2);
    ASSERT_FALSE(G.checkJump(c1,c2));
    G.genArround(M);
    G.printGraph();
    G.assignAllDist(start,end);
    G.assignAllDist(start,end);
    G.printAlldist();
    printPath(G.reverseSearch(start,end));
    printf("-----end testing graph----\n");
}


TEST(dist, minidist){
    printf("-----testing mindist----\n");
    std::vector<std::vector<int> > M=setM();
    Coordinate start=setStart();
    Coordinate end=setEnd();
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
    printf("-----end testing mindist----\n");
}


/*
@brief: main function in google test
@details: call all google test functions
*/
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
