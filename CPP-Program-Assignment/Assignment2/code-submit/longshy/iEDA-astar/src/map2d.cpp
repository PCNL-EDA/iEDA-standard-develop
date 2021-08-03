/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the source file of map2d.
 * @FilePath: /IEDA-ASTAR/src/map2d.cpp
 */

#include "map2d.h"

map2d::map2d(const std::vector<std::vector<char>>& rawmap,
             const std::vector<location2d>& move, const location2d& start,
             const location2d& end)
    : _map(rawmap), _move(move), _start(start), _end(end) {}

void map2d::getAdjacentLocation(const location2d& curr,
                                std::vector<location2d>& rlt) const {
  rlt.clear();
  for (int i = 0; i < _move.size(); i++) {
    location2d next = curr + _move[i];
    if (isFeaseable(next)) {
      rlt.push_back(next);
    }
  }
  return;
}

bool map2d::isFeaseable(const location2d& location) const {
  return location.y >= 0 && location.y < getRows() && location.x >= 0 &&
         location.y < getCols() && getElement(location) != 'x';
}
