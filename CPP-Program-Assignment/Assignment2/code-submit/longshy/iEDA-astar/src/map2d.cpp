/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the source file of map2d.
 * @FilePath: /a-star/src/map2d.cpp
 */

#include "map2d.h"

map2d::map2d(const std::vector<std::vector<char>>& rawmap,
             const std::vector<value_type>& move, const value_type& start,
             const value_type& end)
    : _m_map(rawmap), _m_move(move), _m_start(start), _m_end(end) {}

void map2d::getAdjacentLocation(const value_type& curr,
                                std::vector<value_type>& rlt) const {
  rlt.clear();
  for (int i = 0; i < _m_move.size(); i++) {
    value_type next = curr + _m_move[i];
    if (is_feaseable(next)) {
      rlt.push_back(next);
    }
  }
  return;
}

bool map2d::is_feaseable(const value_type& location) const {
  return location.y >= 0 && location.y < getRows() && location.x >= 0 &&
         location.y < getCols() && getElement(location) != 'x';
}
