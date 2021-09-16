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

namespace data {
class GridMap {

public:
  GridMap() {}
  ~GridMap() {}

  void createGridMap(resource::Display &display);
  void printResultMap(Point *point, resource::Display &display);

  Point *set_start_point(const int x, const int y) const { return map_[x][y]; }
  Point *set_end_point(const int x, const int y) const { return map_[x][y]; }

  vector<vector<Point *>> &get_map_() { return map_; }

private:
  vector<vector<Point *>> map_;
};

} // namespace data

#endif // INCLUDE_GRIDMAP_H_
