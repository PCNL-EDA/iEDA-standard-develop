#ifndef __GRID_HPP_
#define __GRID_HPP_

#include <vector>

#include "Point.hpp"

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

  void addRowData(std::vector<int> row) { _grid.push_back(row); }
  bool isValid(int row, int col) {
    return _grid.size() && (row >= 0 && row < (int)_grid.size()) &&
           (col >= 0 && col < (int)_grid[0].size());
  }
  bool isUnBlocked(int row, int col) {
    return isValid(row, col) && _grid[row][col] != 0;
  }
  bool isDestnation(Point p) { return p == _dst; }
  std::vector<Point> getNeighbours(const Point);

 private:
  Grid2D _grid;
  Point _src = Point(0, 0);
  Point _dst = Point(3, 7);
};

#endif