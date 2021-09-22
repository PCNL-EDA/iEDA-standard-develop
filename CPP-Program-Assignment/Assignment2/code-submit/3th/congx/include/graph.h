/**
 * @file graph.h
 * @author congx
 * @brief This is a graph class interface
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRAPH_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRAPH_H_

#include <unordered_set>
#include <vector>

#include "location.h"


namespace pather{

class Graph {
 public:
  Graph() = default;
  virtual ~Graph() = default;
  
  virtual std::vector<Location> adjacentNodes(
      const Location& current) const = 0;
  virtual double edgeWeight(const Location& begin,
                            const Location& end) const = 0;

  virtual bool passable(const Location& current) const = 0;
  virtual void set_barrier(Location location) = 0;
  virtual int get_width() const = 0;
  virtual int get_height() const = 0;
  virtual void set_width(int width) = 0;
  virtual void set_height(int height) = 0;
};

} // astar

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRID_GRAPH_H_
