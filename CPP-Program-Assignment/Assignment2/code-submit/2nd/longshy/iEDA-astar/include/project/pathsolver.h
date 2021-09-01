/**
 * @Author: shuaiying long (longshy@pcl.ac.cn)
 * @Date: 2021-07-31
 * @Description:This is the header file of pathsolver.
 * @FilePath: /IEDA-ASTAR/include/project/pathsolver.h
 */

#pragma once
#include "map2d.h"
using map_t = map2d;

/**
 * @brief The base class of astar class.
 *
 */
class pathsolver {
 public:
  pathsolver() {}
  virtual ~pathsolver() {}
  virtual bool solve(const map_t& map) = 0;
  virtual std::vector<location2d> getPath() const = 0;
};
