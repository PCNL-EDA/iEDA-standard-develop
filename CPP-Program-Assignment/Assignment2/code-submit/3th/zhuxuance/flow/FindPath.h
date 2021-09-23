/**
 * @file          FindPath.h
 * @brief         Used to find the optimal path for the gridmap, which can be supplemented with a variety of different
 * algorithms
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_FLOW_FINDPATH_H_
#define _FINDOPTIMALPATH_FLOW_FINDPATH_H_

#include "../algorithm/AstarAlgorithm.h"

namespace findOptimalPath {

enum class AlgorithmType { kAstar = 0, kOther = 1 };

/**
 * @brief A tool class for finding the optimal path
 */
class FindPath {
 public:
  // ctor
  FindPath()  = default;
  FindPath(FindPath &) = delete;
  FindPath(FindPath &&) = delete;
  ~FindPath() = default;

  // function
  void findPathBy(const std::string &algorithm_type, GridMap<Grid> &grid_map);
  AlgorithmType checkAlgorithmType(std::string algorithm_type);
};

}  // namespace findOptimalPath

#endif