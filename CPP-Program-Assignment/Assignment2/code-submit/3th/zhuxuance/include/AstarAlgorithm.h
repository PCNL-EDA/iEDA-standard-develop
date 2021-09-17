/**
 * @file          AstarAlgorithm.h
 * @brief         A* algorithm class, use A* algorithm to find the optimal path for the gridmap
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_INCLUDE_ASTARALGORITHM_H_
#define _FINDOPTIMALPATH_INCLUDE_ASTARALGORITHM_H_

#include "GridMap.h"
#include <queue>

namespace findOptimalPath {

using OpenList = std::priority_queue<Grid *, std::vector<Grid *>, cmpGridCost>;

/**
 * @brief A* algorithm, the concrete realization of the algorithm
 */
class AstarAlgorithm {
 public:
  // ctor and dtor
  AstarAlgorithm() = default;
  AstarAlgorithm(GridMap<Grid> &grid_map) : _grid_map(grid_map) {}
  ~AstarAlgorithm() = default;
  void operator=(const AstarAlgorithm &) = delete;

  // function
  void initAstarAlgorithm();
  void addGridToOpenList(Grid *grid);
  void updateEstimateCost(Grid *grid);
  int  caculateDiagonalDistance(Grid *a, Grid *b);
  int  caculateCostSoFar(Grid *next);
  void updateCostSoFar(Grid *next);
  int  caculateCurrentToNextCost(Grid *next);
  void updateCameFromGrid(Grid *next);
  void findOptimalPath();
  void fetchMinCostGrid();
  void searchCurrentGridNeighbors();
  bool isLegalNeighbor(int x, int y);
  void updateOptimalPath();

  // print
  void printTest();
  void printCurrentGrid();
  void printEndGrid();
  void printGrid(Grid *grid);
  void printCurrentGridNeighbors();
  void printStep(Grid *next);

  AstarAlgorithm(AstarAlgorithm &)  = delete;
  AstarAlgorithm(AstarAlgorithm &&) = delete;

 private:
  const static std::vector<Coordinate> kMoveDirection;
  GridMap<Grid> &_grid_map;
  OpenList _open_list;
  Grid *_current_grid = nullptr;
  Grid *_end_grid     = nullptr;
  Grid *_start_grid   = nullptr;
  std::vector<Grid *> _current_grid_neighbors;
};

}  // namespace findOptimalPath

#endif