/**
 * @file          main.cc
 * @brief         Execute Euler path printing program
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <iostream>
#include "Graph.h"

int main(int argc, const char **argv) {
  Euler::Graph g;
  g.setGraph(argc, argv);
  g.getGraphType();
  g.getEulerPath();
  g.printEulerPath();
  return 0;
}