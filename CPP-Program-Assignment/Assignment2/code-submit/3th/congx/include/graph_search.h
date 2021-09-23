/**
 * @file graph.h
 * @author congx
 * @brief This is a interface class of graph search algorithm.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_GRAPH_SEARCH_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_GRAPH_SEARCH_H_

#include "graph.h"

namespace pather{

class GraphSearch {
 public:
  GraphSearch() = default;
  virtual ~GraphSearch() = default;

  virtual void findPath(const Graph& graph, Location start, Location goal,
                        std::vector<Location>& path) const = 0;
};

} // astar

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_GRAPH_SEARCH_H_
