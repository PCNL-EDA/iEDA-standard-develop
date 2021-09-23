/**
 * @file          Grid.h
 * @brief         Grid class, the basic unit of the grid map, which records the information needed by the A* algorithm
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_DATA_GRID_H_
#define _FINDOPTIMALPATH_DATA_GRID_H_

#include <utility>

namespace findOptimalPath {

enum class GridType { kPassable = 0, kObstacle = 1, kStart = 2, kEnd = 3 };
enum class GridState { kNone = 0, kOpen = 1, kClose = 2 };

using Coordinate = std::pair<int, int>;

/**
 * @brief Grid class. The main data are coordinate, type, state, cost...
 */
class Grid {
 public:
  // ctor and dtor
  Grid() = default;
  Grid(int x, int y) { _coordinate = std::make_pair(x, y); }
  ~Grid() { _came_from_grid = nullptr; }

  // getter
  Coordinate get_coordinate() const { return _coordinate; }
  GridType  get_type() const { return _type; }
  GridState get_state() const { return _state; }
  Grid *get_came_from_grid() const { return _came_from_grid; }
  int  get_cost_so_far() const { return _cost_so_far; }
  int  get_estimate_cost() const { return _estimate_cost; }
  bool get_on_optimal_path() const { return _on_optimal_path; }
  int  get_total_cost() const { return _cost_so_far + _estimate_cost; }

  // setter
  void set_coordinate(int x, int y) { _coordinate = std::make_pair(x, y); }
  void set_type(GridType type) { _type = type; }
  void set_state(GridState state) { _state = state; }
  void set_came_from_grid(Grid *came_from_grid) { _came_from_grid = came_from_grid; }
  void set_cost_so_far(int cost_so_far) { _cost_so_far = cost_so_far; }
  void set_estimate_cost(int estimate_cost) { _estimate_cost = estimate_cost; }
  void set_on_optimal_path(bool on_optimal_path) { _on_optimal_path = on_optimal_path; }

  // judge grid's type and state
  bool isStart() { return _type == GridType::kStart; }
  bool isEnd() { return _type == GridType::kEnd; }
  bool isObstacle() { return _type == GridType::kObstacle; }
  bool isOpen() { return _state == GridState::kOpen; }
  bool isClose() { return _state == GridState::kClose; }
  bool isOnOptimalPath() { return _on_optimal_path; }

 private:
  Coordinate  _coordinate;
  GridType   _type  = GridType::kPassable;
  GridState  _state = GridState::kNone;

  Grid  *_came_from_grid = nullptr;
  int   _cost_so_far     = 0;
  int   _estimate_cost   = 0;
  bool  _on_optimal_path = false;
};

struct cmpGridCost {
  bool operator()(Grid *a, Grid *b) const { return a->get_total_cost() >= b->get_total_cost(); }
};

}  // namespace findOptimalPath

#endif