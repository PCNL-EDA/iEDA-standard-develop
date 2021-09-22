/**
 * @file graph.h
 * @author congx
 * @brief This is a graph implemented with an adjacency matrix.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRID_GRAPH_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRID_GRAPH_H_

#include <array>
#include <set>
#include <vector>

#include "graph.h"
#include "location.h"

namespace pather {

class GridGraph : public Graph {
 public:
  GridGraph() : GridGraph(0, 0) {}
  GridGraph(int rows, int cols) : _width(cols), _height(rows) {}

  std::vector<Location> adjacentNodes(const Location& current) const override;
  double edgeWeight(const Location& begin, const Location& end) const override;
  bool passable(const Location& current) const override;
  
  int get_width() const override { return _width; }
  int get_height() const override { return _height; }
  void set_width(int width) override { _width = width; }
  void set_height(int height) override { _height = height; }
  void set_barrier(Location location) override { _barriers.insert(location); }

 private:
  bool inBounds(const Location& current) const;

 private:
  int _width;
  int _height;
  std::set<Location> _barriers;

  static std::array<Location, 8> _directions;
};

}  // namespace pather

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_GRID_GRAPH_H_
