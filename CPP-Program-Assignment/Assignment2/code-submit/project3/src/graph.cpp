/*
@file: graph.cpp
@brief: definition of functions in graph class
@author: Shengkun Wu
@data: 2021/7/26
*/
#include "graph.h"


/*
@fn: Graph
@brief: generation of a graph through a matrix M
@param[in]; M has to be a matrix;
*/
Graph::Graph(const std::vector<std::vector<int> > M){
    _xmax=(int)M.size(); _ymax=(int)M[0].size();
    for (int i = 0; i < _xmax; ++i){
        std::vector<Node*> tmp;
        for(int j=0; j<_ymax;++j){
            Node *tn=new Node;
            tn->_x=i; tn->_y=j;
            tn->_color=M[i][j];
            tmp.push_back(tn);
        }
        _nodes.push_back(tmp);
    }
    for(int j=0; j<_ymax;++j){
        for (int i = 0; i < _xmax; ++i){
            if( i-1>=0 && j-1>=0  && _nodes[i-1][j-1]->_color==0 &&
                (_nodes[i-1][j]->_color==0 || _nodes[i][j-1]->_color==0) ){
                Cor co; co._x=i-1;co._y=j-1; _nodes[i][j]->aroud.push_back(co);
            }
            if( i-1>=0 && j+1<_ymax  && _nodes[i-1][j+1]->_color==0 &&
                (_nodes[i-1][j]->_color==0 || _nodes[i][j+1]->_color==0) ){
                Cor co; co._x=i-1;co._y=j+1; _nodes[i][j]->aroud.push_back(co);
            }
            if( i+1<_xmax && j-1>=0  && _nodes[i+1][j-1]->_color==0 &&
                (_nodes[i+1][j]->_color==0 || _nodes[i][j-1]->_color==0) ){
                Cor co; co._x=i+1;co._y=j-1; _nodes[i][j]->aroud.push_back(co);
            }
            if( i+1<_xmax && j+1<_ymax  && _nodes[i+1][j+1]->_color==0 &&
                (_nodes[i+1][j]->_color==0 || _nodes[i][j+1]->_color==0) ){
                Cor co; co._x=i+1;co._y=j+1; _nodes[i][j]->aroud.push_back(co);
            }
            if( j+1<_ymax  && _nodes[i][j+1]->_color==0 ){
                Cor co; co._x=i; co._y=j+1; _nodes[i][j]->aroud.push_back(co);
            }
            if( j-1>=0 && _nodes[i][j-1]->_color==0){
                Cor co; co._x=i; co._y=j-1; _nodes[i][j]->aroud.push_back(co);
            }
            if(i-1>0 && _nodes[i-1][j]->_color==0){
                Cor co; co._x=i-1; co._y=j; _nodes[i][j]->aroud.push_back(co);
            }
            if(i+1<_xmax && _nodes[i+1][j]->_color==0){
                Cor co; co._x=i+1; co._y=j; _nodes[i][j]->aroud.push_back(co);
            }
        }
    }
}

/*
@fn: ~Graph
@brief: generation of a graph through a matrix M
@param[in]; M has to be a matrix;
*/
Graph::~Graph(){
    for(int i=0;i<_nodes.size();++i){
        for(int j=0; j<_ymax;++j){
            delete this->_nodes[i][j];
        }
    }
}

/*
@fn: SetDist
@brief: Compute distance of all point from (i,j)
@param[in]： i(j) is the x(y) coordinate of the start point 
@details: initial value of dist of each point is -1;
*/
void Graph::SetDist(const int i,const int j, Graph &G){
    G._nodes[i][j]->_dist=0;
    std::vector<Cor> tt;
    std::vector<Cor> nt;
    Cor cord;
    cord._x=i;cord._y=j;
    tt.push_back(cord);
    while(tt.size()!=0){
        for(int m=0;m<tt.size();++m){
            int x=tt[m]._x; int y=tt[m]._y;
            std::vector<Cor> ar=G._nodes[x][y]->aroud;
            for(int n=0; n<ar.size();++n){
                int x2=ar[n]._x;int y2=ar[n]._y;
                int dx=x2-x;
                int dy=y2-y;
                double d=sqrt(dx*dx+dy*dy);
                if(G._nodes[x2][y2]->_dist==-1){
                    nt.push_back(ar[n]);
                }
                if(G._nodes[x2][y2]->_dist==-1 || \
                    G._nodes[x2][y2]->_dist>(d+G._nodes[x][y]->_dist) )
                {
                    G._nodes[x2][y2]->_dist=d+G._nodes[x][y]->_dist;
                }
                
            }
        }
        tt=nt;
        nt.clear();
    }
    return;
}

/*
@fn: GetDist
@brief: return the distance of the node (k,l) to the start point
@param[in]：(k,l) is the end point
*/
double Graph::GetDist(int k, int l){
    if(k>=0&& k<_xmax && l>=0 && l<_ymax ){
        return _nodes[k][l]->_dist;
    }
    else{
        return -1;
    }
};


/*
@fn: PrintPath
@param[in]： (i,j) is the start point，(k,l) is the end point
*/
void Graph::PrintPath(const int i,const int j,const int k,const int l){
    if(_nodes[k][l]->_dist==-1){printf("Can't find a path."); return;}
    std::vector<Cor> path;
    Cor endp;   endp._x=k; endp._y=l;
    path.push_back(endp);

    int m=k; int n=l;
    while(m!=i || n!=j){
        std::vector<Cor> ar=_nodes[m][n]->aroud;
        int x=ar[0]._x; int y=ar[0]._y;
        double d=_nodes[x][y]->_dist;
        for(int i=0;i<ar.size();++i){
            int x1=ar[i]._x; int y1=ar[i]._y;
            if(d>_nodes[x1][y1]->_dist){
                x=ar[i]._x; y=ar[i]._y;
                d=_nodes[x][y]->_dist;
            }
        }
        Cor cord; cord._x=x; cord._y=y;
        path.insert(path.begin(),cord);
        m=x; n=y;
    }

    std::vector<Cor>::iterator it;
    for(it=path.begin();it!=path.end(); ++it){
        printf("(%d,%d)->",(*it)._x,(*it)._y);
    }
    printf("\n");
    return;
}


/*
@fn: PrintGraph
@brief: print the structure of the graph
@details: using to check the graph generated by a matrix
*/
void Graph::PrintGraph(){
    for (int i=0; i<_xmax; ++i){
        for(int j=0; j<_ymax;++j){
            printf("color=%d (%d,%d)->",_nodes[i][j]->_color,i,j);
            std::vector<Cor> ar=_nodes[i][j]->aroud;
            for(int k=0; k<ar.size();++k ){
                printf("(%d,%d)->",ar[k]._x,ar[k]._y);
            } 
            printf("\t%ld",ar.size());
            printf("\n");
        }
    }
    return;
}
