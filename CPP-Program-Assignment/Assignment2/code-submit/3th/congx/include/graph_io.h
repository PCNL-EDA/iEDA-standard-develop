/**
 * @file graph.h
 * @author congx
 * @brief This is a io class of graph. 
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRAPH_IO_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRAPH_IO_H_

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "location.h"

namespace pather{

class GraphIO {
 public:
  void read(const std::string& file, std::vector<std::vector<char>>& map) const;
  void write(const std::vector<std::vector<char>>& map) const;
};

} // astar
#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRAPH_IO_H_
