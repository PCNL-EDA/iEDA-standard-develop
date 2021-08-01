/**
 * @file test.cpp
 * @author lvyaxing
 * @brief
 * @version 0.1
 * @date 2021-07-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"../include/AStar.h"
#include"../include/Node.h"
#include"../include/Coordinate.h"
#include"../include/Map.h"
#include<iostream>
/**
 * @brief Test the given example
 * @fn main 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(){
  MyAStar::Map a(4,8);
  std::vector<std::vector<int>>obstacle_list=a.getMap({{0, 2},
                                                       {0, 3},
                                                       {1, 2},
                                                       {3, 2},
                                                       {4, 0},
                                                       {4, 2},
                                                       {5, 0},
                                                       {5, 1},
                                                       {6, 0},
                                                       {6, 1},
                                                       {7, 0},
                                                       {7, 1}});

  ///<Set start and end node
  MyAStar::Node start_node(0,0);
  MyAStar::Node end_node(3,7);									   
  MyAStar::AStar astar(obstacle_list);
  ///< A star algorithm finding path
  std::list<MyAStar::Node *> path = astar.getPath(start_node, end_node, false);
  ///<Print results
  for (MyAStar::Node*p : path) 
  {
    std::cout << "(" << p->get_x() << "," << p->get_y() << ") ";
  }
  std::cout << "\n";
  return 0;                   
      
}
