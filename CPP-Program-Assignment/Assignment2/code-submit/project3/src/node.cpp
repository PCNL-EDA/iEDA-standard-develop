#include "node.h"


/*
@details: If this point is connected with c1, then return ten times of their Euclidean distance.
Otherwise return 0;
*/
int Coordinate::connectDist(const Coordinate c1){
    if(_x-c1._x==0){
        if(_y-c1._y==1 || _y-c1._y==-1){
            return 10;
        }
    }
    if(_x-c1._x==1|| _x-c1._x==-1){
        if(_y-c1._y==0){
            return 10;
        }
        if(_y-c1._y==1||_y-c1._y==-1){
            return 14;
        }
    }
    return 0;
}

/*
@details:check if c in a box with horizontal length xmax and width 2.
*/
bool Coordinate::checkIn( const int xmax, const int ymax){
    if(_x>=0 && _y>=0 && _x<xmax && _y<ymax){
        return true;
    }
    return false;
}

/*
@para[in]: vc is a given vector of coordinate.
@details:check if this coordinate in a given vector of coordinate.
*/
bool Coordinate::chekcInVec(const std::vector<Coordinate> vc){
    for(int i=0; i<vc.size(); ++i){
        if(this->_x==vc[i]._x && this->_y==vc[i]._y){
            return true;
        }
    }
    return false;
}

/*
@para[in]: vc is a given vector of coordinate.
@details: Delete this coordinate from vc.If this coordinate isn't in vc, don't do anything.
*/
void Coordinate::deleteFrom(std::vector<Coordinate> &vc){
    for(std::vector<Coordinate>::iterator it=vc.begin(); it!=vc.end();++it){
        if((*it)._x==_x && (*it)._y==_y){
            vc.erase(it);
            return;
        }
    }
    return;
}

/*
@para[in]: c is a given coordinate.
@details:check if this coordinate equals to c.
*/
bool Coordinate::checkEq(const Coordinate c){
    if(_x==c._x && _y==c._y){
        return true;
    }
    else{
        return false;
    }
}

/*
@fn: printPath
@details： It is a global function and used to print a path.
*/
void printPath( std::vector<Coordinate> path){
    if(path.size()==0){
        printf("Can't arrive.\n");
        return;
    }
    for(std::vector<Coordinate>::iterator it=path.begin();it!=path.end();++it){
        printf("(%d,%d)->",(*it)._x,(*it)._y);
    }
    printf("\n");
}
