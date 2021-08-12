/*
@file: graph.h
@brief: declaration of classes of graph
@author: Shengkun Wu
@data: 2021/7/26
*/
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "node.h"


/*
@brief: graph class
*/
class Graph{
public:
    Graph(const std::vector<std::vector<int>> M); 
    // initialization of a graph through a matrix M
    bool checkJump(const Coordinate c1, const Coordinate c2);
    // check if c1 can jump to c2 directly
    void genArround(const std::vector<std::vector<int>> M);
    //generate the arround tabel of each node
    ~Graph(); //destructor;
    bool assignDist(Coordinate c, int dist);
    //assign d to _dist of node with coordinate c.
    void setGen(Coordinate c, int n);
    std::vector<Coordinate> findNext(std::vector<Coordinate> tt);
    //set n to node[i][j]->_gen,where i=c._x and j=c._y
    
    Coordinate minDist(std::vector<Coordinate> tt);
    int getDist(Coordinate c){return _nodes[c._x][c._y]->_dist;};
    int getGen(Coordinate c){return _nodes[c._x][c._y]->_gen;};
    void assignAllDist(Coordinate start,Coordinate end); 
    //Compute the distance of each point to start
    std::vector<Coordinate> getAround(const Coordinate c){return _nodes[c._x][c._y]->_around;}
    std::vector<Coordinate> reverseSearch(Coordinate start,Coordinate end);
    //search the path from the start point to the end point
    int get_xmax(){return _xmax;}
    int get_ymax(){return _ymax;}
    void printAlldist();
    void printGraph(); 
    //print graph
private:
    int _xmax; //horizontal length
    int _ymax; //longitudinal length
    std::vector<std::vector<Node*> > _nodes; // node matrix
};

#endif
