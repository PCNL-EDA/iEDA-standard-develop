/**
 * @file graph.h
 * @author congx
 * @brief This is a class of path solver.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PATH_SOLVER_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PATH_SOLVER_H_

#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

#include "graph.h"
#include "graph_io.h"
#include "graph_search.h"
#include "location.h"


namespace pather{

class PathSolver {
 public:
  PathSolver() : _path_search(nullptr), _graph(nullptr) {}
  PathSolver(GraphSearch& path_search, Graph& graph, GraphIO& graph_io);

  void findPath(Location start, Location goal,
                std::vector<Location>& path) const;
  void initMap(const std::string& file = "");
  void output(const std::vector<Location>& path) const;

 private:
  void writeDataToGraph(const std::vector<std::vector<char>>& path);

 private:
  GraphSearch* _path_search;
  Graph* _graph;
  GraphIO* _graph_io;
};

} // astar
#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_PATH_SOLVER_H_
