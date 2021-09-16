#include "FindPathAlgorithm.h"

namespace findOptimalPath {

/**
 * @brief Use A* algorithm to find the optimal path of gridmap
 * @param grid_map 
 */
void FindPathAlgorithm::findPathByAstar(GridMap<Grid> &grid_map) {
  AstarAlgorithm astar(grid_map);
  astar.initAstarAlgorithm();
  printf("\nstart to find path...\n");
  astar.findOptimalPath();
  astar.updateOptimalPath();
}

/**
 * @brief Use other algorithms to find the optimal path of the gridmap
 *        to be added...
 * @param gridmap 
 */
void FindPathAlgorithm::findPathByOtherAlgorithm(GridMap<Grid> &gridmap) {
  printf("\ntodo: other find path algorithm...\n");
}

}  // namespace findOptimalPath