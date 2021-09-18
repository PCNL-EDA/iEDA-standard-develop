#include "astar_solver.h"
#include <cmath>
namespace Assignment2 {

AstarSolver::AstarSolver(int (*heuristic)(const std::pair<int, int> &, const std::pair<int, int> &))
    : _data(heuristic) {}

AstarSolver::~AstarSolver() {}

void AstarSolver::import_grid_map_from_file(const char *file) { _data.import_grid_map_from_file(file); };
void AstarSolver::set_start_and_end(pair<int, int> &&start, pair<int, int> &&end) {
  _data.set_start(Node(start, 0));
  _data.set_end(Node(end, 0));
}

void AstarSolver::displayPorblemToBeSolved() const { _data.displayMap(); }
void AstarSolver::displayResults() const { _data.displayPath(_path); }
void AstarSolver::displaySolverName() const { printf("%s\n", "astar solver"); }

void AstarSolver::runSolver() {
  initSolver();

  while (!isOpenListEmpty()) {
    const Node &current = get_lowest_cost_from_open_list();

    if (isEndNode(current)) {
      break;
    }

    // for each neighbors
    auto neighbors = get_neighbors(current);
    for (auto &neighbor : neighbors) {
      int new_cost = get_new_cost_with_neighbor(current, neighbor);
      if (needUpdate(neighbor, new_cost)) {
        updateNeighborsCost(neighbor, new_cost);
        add_node_to_path(current, neighbor);
      }
    }
  }
  save_path();
}
}  // namespace Assignment2