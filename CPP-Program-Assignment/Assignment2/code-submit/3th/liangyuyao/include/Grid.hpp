/**
 * @file        Grid.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __GRID_HPP_
#define __GRID_HPP_

#include <cmath>
#include <string>
#include <vector>

#include "Point.hpp"

namespace DROP_3TH_ASSIGNMENT2 {

// the value indicates the cost to go this cell from neighbours
// Zero means unreachable
typedef std::vector<std::vector<int>> Grid2D;

enum Direction {
  kBegin,
  kNorth,
  kWest,
  kSouth,
  kEast,
  kNorthWest,
  kSouthWest,
  kSouthEast,
  kNorthEast,
  kEnd,
};

class Grid {
 public:
  Grid() = default;
  ~Grid() = default;
  Grid(Grid&) = default;
  Grid(Grid&&) = delete;

  Grid2D getGrid() { return _grid; }
  Point getSrc() { return _src; }
  Point getDst() { return _dst; }
  std::vector<Point> getNeighbours(const Point);
  Point getDirectNeighbour(Point, Direction);

  bool isValid(int x, int y) {
    return _grid.size() && (y >= 0 && y < (int)_grid.size()) &&
           (x >= 0 && x < (int)_grid[0].size());
  }
  bool isUnBlocked(int x, int y) { return isValid(x, y) && _grid[y][x] != 0; }
  bool isDestnation(Point p) { return p == _dst; }
  bool isConnected(Point, Direction);
  void addRowData(std::vector<int> row) { _grid.push_back(row); }
  double calNeigCost(Point p1, Point p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                     (p1.y - p2.y) * (p1.y - p2.y));
  }

 private:
  Grid2D _grid;
  Point _src = Point(0, 0);
  Point _dst = Point(7, 3);
};

}  // namespace DROP_3TH_ASSIGNMENT2
#endif