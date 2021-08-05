/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the source file of astar.
 * @FilePath: /IEDA-ASTAR/src/astar.cpp
 */

#include "astar.h"

inline double astar::disToEnd(const location2d& lhs, const location2d& rhs) {
  // use Euclidean distance as a heuristic function
  return 10 * sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) +
                   (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

bool astar::solve(const map_t& map) {
  _dead.clear();
  _path.clear();

  std::vector<location2d> next;
  location2d start = map.getStartLocation();
  location2d end = map.getEndLocation();
  _path.push_back(start);
  location2d curr;
  while (_path.empty() == false) {
    curr = _path.back();
    if (curr == end) {
      break;
    }
    map.getAdjacentLocation(curr, next);
    // process the unreachable points
    if (next.empty()) {
      _inpath.erase(curr);
      _dead.insert(curr);
      _path.pop_back();
    } else {
      // order the adjacencies from smallest to largest
      std::sort(next.begin(), next.end(),
                [&](const location2d& lhs, const location2d& rhs) {
                  return _totaldis_to_start + disToEnd(lhs, end) <
                         _totaldis_to_start + disToEnd(rhs, end);
                });
      bool flag = false;
      for (const location2d& n : next) {
        // do not take the location that has been taken
        if (_dead.find(n) == _dead.end() && _inpath.find(n) == _inpath.end()) {
          flag = true;
          _path.push_back(n);
          _inpath.insert(n);
          if (abs(curr.x - n.x) + abs(curr.y - n.y) == 1) {
            _totaldis_to_start += kLinearCost;
          } else {
            _totaldis_to_start += kObliqueCost;
          }
          break;
        }
      }
      // deal with the points that have taken
      if (flag == false) {
        _inpath.erase(curr);
        _dead.insert(curr);
        _path.pop_back();
      }
    }
  }
  return _path.empty() == false;
}

std::vector<location2d> astar::getPath() const { return _path; }