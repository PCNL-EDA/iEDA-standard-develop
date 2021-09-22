/**
 * @file          FindPathAlgorithm.h
 * @brief         Used to find the optimal path for the gridmap, which can be supplemented with a variety of different algorithms
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_INCLUDE_FINDPATHALGORITHM_H_
#define _FINDOPTIMALPATH_INCLUDE_FINDPATHALGORITHM_H_

#include "AstarAlgorithm.h"

namespace findOptimalPath {

/**
 * @brief A tool class for finding the optimal path
 */
class FindPathAlgorithm {
 public:
  // ctor
  FindPathAlgorithm()  = default;
  FindPathAlgorithm(FindPathAlgorithm &)  = delete;
  FindPathAlgorithm(FindPathAlgorithm &&) = delete;
  ~FindPathAlgorithm() = default;

  // function
  void findPathByAstar(GridMap<Grid> &grid_map);
  void findPathByOtherAlgorithm(GridMap<Grid> &grid_map);

};

}  // namespace findOptimalPath

#endif