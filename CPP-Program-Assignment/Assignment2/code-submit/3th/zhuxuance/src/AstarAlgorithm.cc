#include "AstarAlgorithm.h"

namespace findOptimalPath {

const std::vector<Coordinate> AstarAlgorithm::kMoveDirection = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                                                {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

/**
 * @brief Initialize the A* algorithm, set the start grid and end grid
 */
void AstarAlgorithm::initAstarAlgorithm() {
  _current_grid = &_grid_map[_grid_map.get_start_grid().first][_grid_map.get_start_grid().second];
  _end_grid = &_grid_map[_grid_map.get_end_grid().first][_grid_map.get_end_grid().second];
  _start_grid = &_grid_map[_grid_map.get_start_grid().first][_grid_map.get_start_grid().second];
  updateEstimateCost(_current_grid);
  updateCameFromGrid(_current_grid);
  addGridToOpenList(_current_grid);
}

/**
 * @brief Add grid to openlist. openlist is a priority queue that records the grids that will be visited.
 * @param grid 
 */
void AstarAlgorithm::addGridToOpenList(Grid *grid) {
  _open_list.push(grid);
  grid->set_state(kGridState::open);
}

/**
 * @brief Update the estimated cost of reaching the end of a grid
 * @param grid 
 */
void AstarAlgorithm::updateEstimateCost(Grid *grid) {
  grid->set_estimate_cost(caculateDiagonalDistance(grid, _end_grid));
}

/**
 * @brief Calculate the diagonal distance between two grids
 * @param a 
 * @param b 
 * @return int 
 */
int AstarAlgorithm::caculateDiagonalDistance(Grid *a, Grid *b) {
  int width = std::abs(a->get_coordinate().first - b->get_coordinate().first);
  int length = std::abs(a->get_coordinate().second - b->get_coordinate().second);
  return std::abs(length - width) * 10 + (length < width ? length : width) * 14;
}

/**
 * @brief Calculate the distance between the start grid and the next grid
 * @param next 
 * @return int 
 */
int AstarAlgorithm::caculateCostSoFar(Grid *next) {
  return _current_grid->get_cost_so_far() + caculateCurrentToNextCost(next);
}

/**
 * @brief Update the distance between the start grid and the next grid
 * @param next 
 */
void AstarAlgorithm::updateCostSoFar(Grid *next) {
  next->set_cost_so_far(_current_grid->get_cost_so_far() + caculateCurrentToNextCost(next));
}

/**
 * @brief Calculate the distance from current grid to the next grid
 * @param next 
 * @return int 
 */
int AstarAlgorithm::caculateCurrentToNextCost(Grid *next) {
  // If it moves diagonally, cost is 14.
  if (next->get_coordinate().first != _current_grid->get_coordinate().first &&
      next->get_coordinate().second != _current_grid->get_coordinate().second) {
    return 14;
  }
  // If it is moving horizontally or vertically, cost is 10.
  return 10;
}

/**
 * @brief Update the predecessor grid of the grid
 * @param next 
 */
void AstarAlgorithm::updateCameFromGrid(Grid *next) { next->set_came_from_grid(_current_grid); }

/**
 * @brief Use A* algorithm to find the optimal path
 */
void AstarAlgorithm::findOptimalPath() {
  while (!_open_list.empty()) {
    // Take out a grid with the smallest total cost to the end grid from the openlist
    fetchMinCostGrid();
    // If the extracted grid is the end grid, the optimal path has been found, and the algorithm terminates
    if (_current_grid == _end_grid) {
      _grid_map.set_have_optimal_path(true);
      break;
    }
    // If it is not the end grid, traverse its reachable neighbors
    searchCurrentGridNeighbors();
    for (auto next : _current_grid_neighbors) {
      int neighbor_cost_so_far = caculateCostSoFar(next);
      // If the neighbor has not been visited, or the cost_so_far is smaller than the previously recorded cost
      if (next->get_cost_so_far() == 0 || neighbor_cost_so_far < next->get_cost_so_far()) {
        // printStep(next);
        // Update the information of the neighbor grid
        updateCostSoFar(next);
        updateEstimateCost(next);
        addGridToOpenList(next);
        updateCameFromGrid(next);
      }
    }
  }
}

/**
 * @brief Take out a grid with the smallest total cost to the end grid from the openlist
 */
void AstarAlgorithm::fetchMinCostGrid() {
  _current_grid = _open_list.top();
  _open_list.pop();
  _current_grid->set_state(kGridState::close);
}

/**
 * @brief Find all reachable neighbors of a grid
 */
void AstarAlgorithm::searchCurrentGridNeighbors() {
  _current_grid_neighbors.clear();

  for (int i = 0; i < kMoveDirection.size(); ++i) {
    int x = _current_grid->get_coordinate().first + kMoveDirection[i].first;
    int y = _current_grid->get_coordinate().second + kMoveDirection[i].second;
    if (isLegalNeighbor(x, y)) {
      _current_grid_neighbors.push_back(&_grid_map[x][y]);
    }
  }
}

/**
 * @brief Determine whether the grid is within the gridmap range and whether it is an obstacle
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool AstarAlgorithm::isLegalNeighbor(int x, int y) {
  if (x < 0 || x >= (int)_grid_map.get_grid_map_width() || y < 0 || y >= (int)_grid_map.get_grid_map_length()) {
    return false;
  }
  kGridType neighbor_type = _grid_map[x][y].get_type();
  if (neighbor_type == kGridType::obstacle || neighbor_type == kGridType::start) {
    return false;
  }
  return true;
}

/**
 * @brief Backtracking to find and update the optimal path in the grid map
 */
void AstarAlgorithm::updateOptimalPath() {
  if (_end_grid->get_came_from_grid() == nullptr) {
    return;
  }

  printf("record optimal path...\n");

  Grid *grid = _end_grid;
  OptimalPath optimal_path;
  while (!grid->isStart()) {
    grid->set_on_optimal_path(true);
    optimal_path.push_back(std::make_pair(grid->get_coordinate().first, grid->get_coordinate().second));
    grid = grid->get_came_from_grid();
  }
  optimal_path.push_back(std::make_pair(_start_grid->get_coordinate().first, _start_grid->get_coordinate().second));
  _start_grid->set_on_optimal_path(true);
  for (int i = optimal_path.size() - 1; i >= 0; --i) {
    _grid_map.insertToOptimalPath(optimal_path[i]);
  }
}

/**
 * @brief Test some functions of the class and print the results
 */
void AstarAlgorithm::printTest() {
  printf("\n>>> 测试引用对象 <<<\n");
  _grid_map.printGridMap();
  _grid_map.updateStartGrid(1, 1);
  _grid_map.updateEndGrid(2, 6);
  _grid_map.printGridMap();
  printf("\n>>>>>>>>>   <<<<<<<<<\n");
}

/**
 * @brief Print current grid
 */
void AstarAlgorithm::printCurrentGrid() {
  printf("\n>>> current grid <<<\n");
  printf("(%d, %d)\n", _current_grid->get_coordinate().first, _current_grid->get_coordinate().second);
}

/**
 * @brief Print end grid
 */
void AstarAlgorithm::printEndGrid() {
  printf("\n>>> end grid <<<\n");
  printf("(%d, %d)\n", _end_grid->get_coordinate().first, _end_grid->get_coordinate().second);
  if (_end_grid->get_came_from_grid() == nullptr) {
    printf("_end_grid came from nullptr\n");
  } else {
    printf("_end_grid came from (%d, %d)\n", _end_grid->get_came_from_grid()->get_coordinate().first,
           _end_grid->get_came_from_grid()->get_coordinate().second);
  }
}

/**
 * @brief Print a specified grid
 * @param grid 
 */
void AstarAlgorithm::printGrid(Grid *grid) {
  printf("\n>>> print grid <<<\n");
  printf("(%d, %d)\n", grid->get_coordinate().first, grid->get_coordinate().second);
}

/**
 * @brief Print current grid's neighbors
 */
void AstarAlgorithm::printCurrentGridNeighbors() {
  printf("\n>>> print current grid neighbors <<<\n");
  for (auto next : _current_grid_neighbors) {
    printf("(%d, %d)\n", next->get_coordinate().first, next->get_coordinate().second);
  }
}

/**
 * @brief Print a step from current grid to next grid. To facilitate debugging
 * @param next 
 */
void AstarAlgorithm::printStep(Grid *next) {
  printf("\n>>> print a step from current to next <<<\n");
  printf("(%d, %d) -> (%d, %d)\n", _current_grid->get_coordinate().first, _current_grid->get_coordinate().second,
         next->get_coordinate().first, next->get_coordinate().second);
}

}  // namespace findOptimalPath