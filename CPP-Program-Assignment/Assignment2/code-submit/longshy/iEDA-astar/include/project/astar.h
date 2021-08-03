/*
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the header file of astar.
 * @FilePath: /IEDA-ASTAR/include/project/astar.h
 */

#pragma once
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <vector>

#include "map2d.h"
#include "pathsolver.h"

class astar : public pathsolver {
 public:
  bool solve(const map2d& map);
  std::vector<location2d> getPath() const;

 private:
  // Points that have been traversed
  std::set<location2d> _dead;
  // Query whether the point is in the path
  std::set<location2d> _inpath;
  // Record the path
  std::vector<location2d> _path;

  enum Cost {
    kLinearCost = 5,
    kObliqueCost = 7,
  };

  double distance(const location2d& lhs, const location2d& rhs);
  double max(const double& lhs, const double& rhs) const {
    return lhs < rhs ? rhs : lhs;
  }
  double min(const double& lhs, const double& rhs) const {
    return lhs > rhs ? rhs : lhs;
  }
};
