#include "astar_solver.h"
#include <cmath>
namespace Assignment2 {

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