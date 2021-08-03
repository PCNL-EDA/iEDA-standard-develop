#ifndef _node_h
#define _node_h
#include <iostream>
#include <vector>

//coordinate class
struct Coordinate{
    int _x;
    int _y;
    Coordinate():_x(0),_y(0){};
    Coordinate(const Coordinate &c):_x(c._x),_y(c._y){};
    Coordinate(int i,int j):_x(i),_y(j){};
    ~Coordinate()=default;
    int connectDist(Coordinate c1);// return distance from this point to c1.
    bool checkIn( int xmax, int ymax);
    //check if c in a box with horizontal length xmax and width ymax.
    bool checkInVec(std::vector<Coordinate> vc);
    bool checkEq(const Coordinate c);
    //check if c in vc.
    void deleteFrom(std::vector<Coordinate> &vc);
    //delete this Coordinate from vc return a new vector<Coordinate>
};

enum Color{kWhite,kBlack};

//node class
class Node{
public:
    friend class Graph;
    Color _color; //color of a node, 0 for white, 1 for black
    std::vector<Coordinate> _around;// coordinates of surrounding white node
    int _dist; //distance of this point to the start point
    int _gen; // generation of a node. 
    Node():_x(0),_y(0),_color(kWhite),_around({}),_dist(-1),_gen(-1){};
    ~Node()=default;
private:
    int _x;//the x coordinate of a node
    int _y;//the y coordinate of a node
};

void printPath( std::vector<Coordinate> path);

#endif