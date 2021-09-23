/**
 * @file gridmap.h
 * @brief Define the attributes of each point in a graph.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#ifndef INCLUDE_GRIDMAP_H_
#define INCLUDE_GRIDMAP_H_

#include "display.h"
#include "point.h"

namespace model {
class GridMap {

public:
  GridMap() = default;
  ~GridMap() = default;

  Point *get_start_point(const int x, const int y) const { return _map[x][y]; }
  Point *get_end_point(const int x, const int y) const { return _map[x][y]; }
  vector<vector<Point *>> &get_map_() { return _map; }

  void createGridMap(Display &display);
  void printResultMap(Point *point, Display &display);

private:
  vector<vector<Point *>> _map;
};

} // namespace model

#endif // INCLUDE_GRIDMAP_H_
