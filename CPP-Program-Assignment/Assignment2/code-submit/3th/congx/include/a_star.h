/**
 * @file graph.h
 * @author congx
 * @brief This is a class of A* algorithm.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_A_STAR_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_A_STAR_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "graph_search.h"
#include "location.h"
#include "priority_queue.h"

namespace pather {

class AStar : public GraphSearch {
 public:
  AStar() = default;
  ~AStar() = default;

  void findPath(const Graph& graph, Location start, Location goal,
                std::vector<Location>& path) const override;

 private:
  double heuristic(Location begin, Location end) const;
  void buildPath(Location start, Location goal,
                 std::map<Location, Location>& reached_precursor,
                 std::vector<Location>& path) const;
};

}  // namespace pather
#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_A_STAR_H_
