/**
 * @file graph.h
 * @author congx
 * @brief This is google test class to check if program is rigth.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "path_solver.h"
#include "a_star.h"
#include "grid_graph.h"

namespace pather{

TEST(PathSolverTest, Reached) {
  AStar astar;
  GridGraph grid_graph;
  GraphIO graph_io;
  PathSolver path_solver(astar, grid_graph, graph_io);
  std::vector<Location> path;

  path_solver.initMap("../data/test_map1.txt");
  path_solver.findPath(Location(0, 0), Location(7, 3), path);
  EXPECT_TRUE(path.size());
}

TEST(PathSolverTest, NotReached) {
  AStar astar;
  GridGraph grid_graph;
  GraphIO graph_io;
  PathSolver path_solver(astar, grid_graph, graph_io);
  std::vector<Location> path;

  path_solver.initMap("../data/test_map2.txt");
  path_solver.findPath(Location(0, 0), Location(7, 3), path);
  EXPECT_TRUE(path.size() == 0);
}

} // astar
