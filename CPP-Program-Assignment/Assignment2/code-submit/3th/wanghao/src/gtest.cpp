#include "gtest/gtest.h"
#include "solver.h"
#include "astar_solver.h"

int manhattanDistance(const std::pair<int, int> &node_a, const std::pair<int, int> &node_b) {
  return abs(node_a.first - node_b.first) + abs(node_a.second - node_b.second);
}

TEST(ASTAR_TEST, map_print_test) {
  Assignment2::PathFindingSolverInterface *solver = new Assignment2::AstarSolver(manhattanDistance);

  solver->displaySolverName();
  solver->import_grid_map_from_file(
    "/home/wanghao/iEDA-standard-develop/CPP-Program-Assignment/Assignment2/code-submit/3th/wanghao/data/map.txt");
  solver->set_start_and_end({0, 0}, {7, 3});
  solver->displayPorblemToBeSolved();
  EXPECT_TRUE(1);
}