#include "FindPath.h"
#include <algorithm>

namespace findOptimalPath {

/**
 * @brief Use A* algorithm to find the optimal path of gridmap
 * @param grid_map
 */
void FindPath::findPathBy(const std::string &algorithm_type, GridMap<Grid> &grid_map) {
  if (checkAlgorithmType(algorithm_type) == AlgorithmType::kAstar) {
    AstarAlgorithm astar(grid_map);
    astar.initAstarAlgorithm();
    printf("\nstart to find path by Astar algorithm...\n");
    astar.findOptimalPath();
    astar.updateOptimalPath();
  } else if (checkAlgorithmType(algorithm_type) == AlgorithmType::kOther) {
    printf("please develop other algorithm\n");
  } else {
    printf("findPathBy err\n");
  }
}

AlgorithmType FindPath::checkAlgorithmType(std::string algorithm_type) {
  std::transform(algorithm_type.begin(), algorithm_type.end(), algorithm_type.begin(), ::tolower);
  if(0==algorithm_type.compare("astar") || 0==algorithm_type.compare("a*")) {
    return AlgorithmType::kAstar;
  } else {
    return AlgorithmType::kOther;
  }
}

}  // namespace findOptimalPath