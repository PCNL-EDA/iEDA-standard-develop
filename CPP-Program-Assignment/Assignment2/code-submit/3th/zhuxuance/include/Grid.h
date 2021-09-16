/**
 * @file          Grid.h
 * @brief         Grid class, the basic unit of the grid map, which records the information needed by the A* algorithm
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_INCLUDE_GRID_H_
#define _FINDOPTIMALPATH_INCLUDE_GRID_H_

#include <utility>

namespace findOptimalPath {

enum class kGridType { passable = 0, obstacle = 1, start = 2, end = 3 };
enum class kGridState { none = 0, open = 1, close = 2 };

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
  Coordinate get_coordinate() { return _coordinate; }
  kGridType  get_type() { return _type; }
  kGridState get_state() { return _state; }
  Grid *get_came_from_grid() { return _came_from_grid; }
  int  get_cost_so_far() { return _cost_so_far; }
  int  get_estimate_cost() { return _estimate_cost; }
  bool get_on_optimal_path() { return _on_optimal_path; }
  int  get_total_cost() { return _cost_so_far + _estimate_cost; }

  // setter
  void set_coordinate(int x, int y) { _coordinate = std::make_pair(x, y); }
  void set_type(kGridType type) { _type = type; }
  void set_state(kGridState state) { _state = state; }
  void set_came_from_grid(Grid *came_from_grid) { _came_from_grid = came_from_grid; }
  void set_cost_so_far(int cost_so_far) { _cost_so_far = cost_so_far; }
  void set_estimate_cost(int estimate_cost) { _estimate_cost = estimate_cost; }
  void set_on_optimal_path(bool on_optimal_path) { _on_optimal_path = on_optimal_path; }

  // judge grid's type and state
  bool isStart() { return _type == kGridType::start; }
  bool isEnd() { return _type == kGridType::end; }
  bool isObstacle() { return _type == kGridType::obstacle; }
  bool isOpen() { return _state == kGridState::open; }
  bool isClose() { return _state == kGridState::close; }
  bool isOnOptimalPath() { return _on_optimal_path; }

 private:
  Coordinate  _coordinate;
  kGridType   _type  = kGridType::passable;
  kGridState  _state = kGridState::none;

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