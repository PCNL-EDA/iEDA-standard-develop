/*
@file: test.h
@brief: definition of my test functions
@author: Shengkun Wu
@data: 2021/7/26
*/
#include "graph.h"

/*
@fn: CheckMatrx
@brief: check if M is a metrix
@details: if M is a matrix return true, or return false
*/
bool CheckMatrx(const std::vector<std::vector<int> > M){
    if(M.size()==0){return false;}
    int y=M.size(); int x=M[0].size();
    for(int i=0; i<M.size(); ++i){
        if(x!=M[i].size()){return false;}
    }
    return true;
}

/*
@fn: test1
@brief: 
@details: my test function. Based on a 2d array, print the path.
*/
void test1(){
    //Generate a 2d vector M from 2d array Matrix
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
    if(!CheckMatrx(M)){
        printf("not metrix\n");
        return;
    }
    
    //using M to generate a graph G
    Graph G(M);
    //G.PrintGraph();
    //Compute the distance of each point from (0,0)
    G.SetDist(0,0,G);
    //print the shortest path
    printf("!!!Path is ");
    G.PrintPath(0,0,3,7);
    return;
}