/*
 * @Author: YangZongLin
 * @Date: 2021-08-1
 * @Description: 
 * @FilePath: /Topic3/test/sample.cpp
 * @copyright:
 */
#include "../include/project/Model.hpp"

int main(int argc, char const *argv[]) {
  astar::Model m;
  m.initMap(4, 8);
  m.addObstacle(0, 4);
  m.addObstacle(0, 5);
  m.addObstacle(0, 6);
  m.addObstacle(0, 7);
  m.addObstacle(1, 5);
  m.addObstacle(1, 6);
  m.addObstacle(1, 7);
  m.addObstacle(2, 0);
  m.addObstacle(2, 1);
  m.addObstacle(2, 3);
  m.addObstacle(2, 4);
  m.addObstacle(3, 0);
  m.setStartPoint(0, 0);
  m.setEndPoint(3, 7);
  m.showTheWay();
  return 0;
}