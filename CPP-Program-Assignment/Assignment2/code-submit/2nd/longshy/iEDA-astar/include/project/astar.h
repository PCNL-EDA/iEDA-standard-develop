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
  // points that have been traversed
  std::set<location2d> _dead;
  // query whether the point is in the path
  std::set<location2d> _inpath;
  // record the path
  std::vector<location2d> _path;
  // use totalDisToStart to record the distance from start to curr
  double _totaldis_to_start = 0;
  enum Cost {
    kLinearCost = 10,
    kObliqueCost = 14,
  };

  double disToEnd(const location2d& lhs, const location2d& rhs);
};
