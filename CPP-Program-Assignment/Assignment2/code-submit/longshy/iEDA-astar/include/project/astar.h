/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the header file of astar.
 * @FilePath: /a-star/include/astar.h
 */

#pragma once
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <vector>

#include "map2d.h"
#include "pathsolver.h"

using value_type = location2d;
using map_t = map2d;
class astar : public pathsolver {
 public:
  bool solve(const map_t& map);
  std::vector<value_type> getPath() const;

 private:
  // Points that have been traversed
  std::set<value_type> _m_dead;
  // Query whether the point is in the path
  std::set<value_type> _m_inpath;
  // Record the path
  std::vector<value_type> _m_path;

  static constexpr int kLinearCost = 5;
  static constexpr int kObliqueCost = 7;
  double distance(const value_type& lhs, const value_type& rhs);
  // double max(const double& lhs, const double& rhs) {
  //   return lhs < rhs ? rhs : lhs;
  // }
  // double min(const double& lhs, const double& rhs) {
  //   return lhs > rhs ? rhs : lhs;
  // }
};
