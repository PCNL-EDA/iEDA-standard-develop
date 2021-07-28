#include "project/tmp.hpp"

zb::Map::Map()
{
}

void zb::Map::findWay()
{
    kOpenSet.insert(kStartPoint);
    while(!kOpenSet.empty()){
        kM=*kOpenSet.begin();
        distance+=(kNow.x==kM.x || kNow.y==kM.y) ? 1:1.4;
        kNow=*kOpenSet.begin();
        kOpenSet.clear();
        kEndPoint.weight=kNow.weight;
        if(kNow==kEndPoint){
            break;
        }else{
            kCloseSet.push_front(kNow);
            for (int i = kNow.x-1;i <= kNow.x+1;i++)
                for (int j =kNow.y-1;j <= kNow.y+1;j++)
                    if((i!=kNow.x || j!=kNow.y) && i>=0 && j>=0 && i<sizeof(kAllPoint)/sizeof(kAllPoint[0]) && j<sizeof(kAllPoint[0])/sizeof(kAllPoint[0][0]) && kAllPoint[i][j]==0){
                        kM.x=i;kM.y=j;kM.weight=distance-(i==kNow.x||j==kNow.y ? 1:1.4)+kEndPoint.x-i+kEndPoint.y-j;
                        if(std::find(kCloseSet.begin(),kCloseSet.end(),kM) ==std::end(kCloseSet)){
                            kM.weight=distance+(i==kNow.x||j==kNow.y ? 1:1.4)+kEndPoint.x-i+kEndPoint.y-j;
                            kOpenSet.insert(kM);
                        }
                    } 
        }
    }
    for (std::list<Point>::reverse_iterator i = kCloseSet.rbegin(); i != kCloseSet.rend(); i++)
    {
        std::cout<<"("<<(*i).x<<","<<(*i).y<<")->";
    }
    std::cout<<"("<<kEndPoint.x<<","<<kEndPoint.y<<")"<<std::endl;
}

zb::Map::~Map()
{
}