/**
 * @file          main.cc
 * @brief         Execute Euler path printing program
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "Graph.h"

int main(int argc, const char **argv) {
  if (argc != 3 || !argv[1] || !argv[2]) {
    printf("invalid parameters\n");
    return 0;
  }
  Euler::Graph g;
  std::string relationship_file_path(argv[1]);
  std::string people_file_path(argv[2]);

  g.initGraph(relationship_file_path, people_file_path);
  g.determineGraphType();
  g.findEulerPath();
  g.printEulerPath();
  return 0;
}