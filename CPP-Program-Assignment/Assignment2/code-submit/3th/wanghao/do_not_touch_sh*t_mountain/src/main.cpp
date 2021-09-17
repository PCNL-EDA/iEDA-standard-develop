#include "astar_solver.h"

namespace Assignment2 {

int main(int argc, const char **argv) {
  PathFindingSolver *solver = new AstarSolver();

  solver->import_grid_map_from_file(argv[1]);
  // solver->displayPorblemToBeSolved();
  // solver->displaySolverName();
  solver->set_start_and_end({0, 0}, {3, 7});
  solver->runSolver();
  // solver->displayResults();
  // solver->displayExecTimeMS();
  return 0;
}

}  // namespace Assignment2