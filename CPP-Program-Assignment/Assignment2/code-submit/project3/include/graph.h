/*
@file: test.h
@brief: declaration of classes of graph
@author: Shengkun Wu
@data: 2021/7/26
*/
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <math.h>

//coordinate class
class Cor{
public:
    int _x;
    int _y;
};

//node class
class Node{
public:
    int _x;//x coordinate of a node
    int _y;//y coordinate of a node
    int _color;//color of a node, 0 for white, 1 for black
    std::vector<Cor> aroud;// coordinates of surrounding white node
    double _dist; //distance of this point from the start point
    Node(){
        _x=0;_y=0;_color=0;  aroud={}; _dist=-1; 
    }
};

//graph class
class Graph{
private:
    int _xmax;//max value of x-1
    int _ymax;//max value of y-1
    std::vector<std::vector<Node*> > _nodes;
public:
    Graph(const std::vector<std::vector<int>> M);// generation of a graph through a matrix M
    ~Graph(){
        for(int i=0;i<_nodes.size();++i){
            for(int j=0; j<_ymax;++j){
                delete this->_nodes[i][j];
            }
        }
    };
    void SetDist(const int i,const int j, Graph &G);//Compute distance of all point from (i,j)
    void PrintPath(const int i,const int j,const int k,const int l);
    //print the path from (i,j) to (k,l)
    int getxmax(){return _xmax;}
    int getymax(){return _ymax;}
    void PrintGraph();//print graph
    void PrintDist(int k,int l){
        if(k>=0&& k<_xmax && l>=0 && l<_ymax ){
            printf("end point dist=%f\n",_nodes[k][l]->_dist);
        }
        else{printf("Can't find this point\n");}
    }
};

#endif
