/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the source file of main function.
 * @FilePath: /a-star/src/main.cpp
 */

#include <iostream>

#include "astar.h"
#include "map2d.h"

int main() {
  std::vector<std::vector<char>> rawmap = {
      {'s', ' ', ' ', ' ', 'x', 'x', 'x', 'x'},
      {' ', ' ', ' ', ' ', ' ', 'x', 'x', 'x'},
      {'x', 'x', ' ', 'x', 'x', ' ', ' ', ' '},
      {'x', ' ', ' ', ' ', ' ', ' ', ' ', 'e'}};
  std::vector<location2d> move = {
      location2d(-1, 0), location2d(-1, -1), location2d(0, -1),
      location2d(1, -1), location2d(1, 0),   location2d(1, 1),
      location2d(0, 1),  location2d(-1, 1),
  };
  map2d amap(rawmap, move, location2d(0, 0), location2d(7, 3));
  pathsolver* abc_solver = new astar();
  bool has_solve = abc_solver->solve(amap);

  if (has_solve) {
    printf("ok: ");
    std::vector<location2d> path = abc_solver->getPath();
    for (int i = 0; i < path.size(); i++) {
      printf("->(%d,%d) ", path[i].y, path[i].x);
    }
    printf("\n");
  } else {
    printf("not ok");
  }

  delete abc_solver;
  return 0;
}
