/*
@file main.cpp
@brief main function
@author Shengkun Wu
@data 2021/7/25 
*/
#include <iostream>
#include "graph.h"

/*
@breif:check if a given 2d-vector is a metrix.
*/
bool CheckMatrx(const std::vector<std::vector<int> > M){
    if(M.size()==0){return false;}
    int y=M.size(); int x=M[0].size();
    for(int i=0; i<M.size(); ++i){
        if(x!=M[i].size()){return false;}
    }
    return true;
}

int example(){
    int Matrix[4][8]={{0,0,0,0,1,1,1,1},
                      {0,0,0,0,1,0,1,1},
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
        return 0;
    }
    
    Coordinate start(0,0); 
    Coordinate end(3,7);
    Graph G(M);
    G.genArround(M);
    //G.printGraph();
    G.assignAllDist(start,end);
    //G.printAlldist();
    std::vector<Coordinate> path=G.reverseSearch(start,end);
    printPath(path);
    return 0;
}
/*
@fn: main
@details: Show the given example;
*/
int main(){
    example();
}
