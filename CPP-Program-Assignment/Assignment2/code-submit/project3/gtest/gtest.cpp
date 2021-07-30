/*
@file: gtest.cpp
@brief: definition of gtest functions
@author: Shengkun Wu
@data: 2021/7/26
*/
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include "graph.h"
#include "mytest.h"

/*
@brief: check Graph::SetDist() and Graph::GetDist()
*/
TEST(dist, distingraph)
{
    int Matrix[4][8]={{0,0,0,0,1,1,1,1},
                      {0,0,0,0,0,1,1,1},
                      {1,1,0,1,1,0,0,0},
                      {1,0,0,0,0,0,0,0}};
    std::vector<std::vector<int> > M;
    
    for(int i=0; i<sizeof(Matrix)/sizeof(Matrix[0]);++i){
        std::vector<int> Mt;
        for(int j=0;j<sizeof(Matrix[0])/sizeof(Matrix[0][0]);++j){
            Mt.push_back(Matrix[i][j]);
        }
        M.push_back(Mt);
    }
    //using M to generate a graph G
    Graph G(M);
    //G.PrintGraph();
    G.SetDist(0,0,G);
    EXPECT_EQ(sqrt(2),G.GetDist(1,1));
    EXPECT_EQ(2*sqrt(2),G.GetDist(2,2));
    EXPECT_EQ(3*sqrt(2),G.GetDist(3,3));
    EXPECT_EQ(3*sqrt(2)+4,G.GetDist(3,7));
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
