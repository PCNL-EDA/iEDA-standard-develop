/**
 * @file graph.h
 * @author congx
 * @brief This is a main function. The entry of program.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#include <vector>

#include "a_star.h"
#include "grid_graph.h"
#include "path_solver.h"

using namespace pather;

int main() {
  AStar astar;
  GridGraph grid_graph;
  GraphIO graph_io;
  PathSolver path_solver(astar, grid_graph, graph_io);

  Location start(0, 0);
  Location goal(7, 3);
  std::vector<Location> path;

  path_solver.initMap("../data/map.txt");
  path_solver.findPath(start, goal, path);
  path_solver.output(path);

  return 0;
}
