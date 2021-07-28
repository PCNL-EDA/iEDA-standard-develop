 /**
 * @file MODERN-CPP-TEMPLATE-MASTER
 * @brief Solution of an algorithm problem
 * 
 * A * algorithm is applied to static obstacle routing problem
 * 
 * @author ZongLin Yang,2441568697@qq.com
 * @version V1.0
 * @data 2021.7.23
 */

#include <iostream>
#include <set>
#include <list>
#include <algorithm>

#ifndef MAKE_USE_
#define MAKE_USE_

namespace zb
{
  struct Point
  {
      int x;
      int y;
      float weight;
      bool operator< (const Point &a) const{
          return a.weight>weight;
      }
      void operator= (const Point &a){
          x=a.x;
          y=a.y;
          weight=a.weight;
      }
      bool operator== (const Point &a) const{
          return a.x==x && a.y==y;
      }
  };

  ///@brief This class is an abstraction of the map in the problem

  class Map
  {
  private:
      Point kStartPoint={0,0,10};///<Record the location of the starting point
      Point kEndPoint={3,7};///<Record the location of the ending point
      Point kNow,kM;///<It is used to record the current node and the adjacent nodes of the current node respectively
      float distance=-1.4;///<Record the distance from the current node to the starting point
      int kAllPoint[4][8]={
          0,0,0,0,1,1,1,1,
          0,0,0,0,0,1,1,1,
          1,1,0,1,1,0,0,0,
          1,0,0,0,0,0,0,0
          };///<Record the specific situation of the diagram given by the title. 0 represents no obstacle and 1 represents obstacle
      std::set<Point> kOpenSet;///<Used to store nodes to be traversed
      std::list<Point> kCloseSet;///<Used to record nodes that have passed
  public:
      Map();
      void findWay();
      ~Map();
  };
}

#endif //MAKE_USE_