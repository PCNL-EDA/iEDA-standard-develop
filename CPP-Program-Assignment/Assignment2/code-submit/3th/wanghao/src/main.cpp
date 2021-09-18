#include "solver.h"
#include "astar_solver.h"

int manhattanDistance(const std::pair<int, int> &node_a, const std::pair<int, int> &node_b) {
  return abs(node_a.first - node_b.first) + abs(node_a.second - node_b.second);
}

int main(int argc, char **argv) {
  Assignment2::PathFindingSolverInterface *solver = new Assignment2::AstarSolver(manhattanDistance);

  solver->displaySolverName();
  solver->import_grid_map_from_file(argv[1]);
  solver->set_start_and_end({0, 0}, {7, 3});
  solver->displayPorblemToBeSolved();
  // solver->runSolver();
  // solver->displayResults();

  return 0;
}