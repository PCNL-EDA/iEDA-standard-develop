/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the source file of astar.
 * @FilePath: /a-star/src/astar.cpp
 */

#include "astar.h"

double astar::distance(const value_type& lhs, const value_type& rhs) {
  double dx = abs(lhs.x - rhs.x);
  double dy = abs(lhs.y - rhs.y);
  // return kLinearCost * max(dx, dy) + (kObliqueCost - kLinearCost) * min(dx,
  // dy);
  return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

bool astar::solve(const map_t& map) {
  _m_dead.clear();
  _m_path.clear();

  std::vector<map_t::value_type> next;
  map_t::value_type start = map.getStartLocation();
  map_t::value_type end = map.getEndLocation();
  _m_path.push_back(start);
  map_t::value_type curr;
  while (_m_path.empty() == false) {
    curr = _m_path.back();
    if (curr == end) break;
    map.getAdjacentLocation(curr, next);
    // process the unreachable points
    if (next.empty()) {
      _m_inpath.erase(curr);
      _m_dead.insert(curr);
      _m_path.pop_back();
    } else {
      // order the adjacencies from smallest to largest
      std::sort(
          next.begin(), next.end(),
          [&](const map_t::value_type& lhs, const map_t::value_type& rhs) {
            return distance(lhs, end) < distance(rhs, end);
          });
      bool flag = false;
      for (const map_t::value_type& n : next) {
        // do not take the location that has been taken
        if (_m_dead.find(n) == _m_dead.end() &&
            _m_inpath.find(n) == _m_inpath.end()) {
          flag = true;
          _m_path.push_back(n);
          _m_inpath.insert(n);
          break;
        }
      }
      // deal with the points that have taken
      if (flag == false) {
        _m_inpath.erase(curr);
        _m_dead.insert(curr);
        _m_path.pop_back();
      }
    }
  }
  return _m_path.empty() == false;
}

std::vector<value_type> astar::getPath() const { return _m_path; }