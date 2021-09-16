/**
 * @file        AStarSearch.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __ALGORITHM_HPP_
#define __ALGORITHM_HPP_

#include <assert.h>

#include <cmath>
#include <map>

#include "Grid.hpp"
#include "Point.hpp"

namespace DROP_3TH_ASSIGNMENT2 {

typedef double (*HeuristicFunc)(Point src, Point dst);

enum HeuristicType { kDiagonal, kManhattan, kEuclidean };

class AStarSearch {
 public:
  AStarSearch(Grid, Point, Point, HeuristicType);

  double heuristicDiagonal(Point p1, Point p2) {
    static const double D = 1;
    static const double D2 = std::sqrt(2);
    double dx = std::abs(p1.x - p2.x);
    double dy = std::abs(p1.y - p2.y);
    return D * (dx + dy) - (2 * D - D2) * std::min(dx, dy);
  }

  double heuristicManhattan(Point p1, Point p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y) + 0.0;
  }

  double heuristicEuclidean(Point p1, Point p2) { return distance(p1, p2); }

  double distance(Point p1, Point p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                     (p1.y - p2.y) * (p1.y - p2.y));
  }

  Point popMinFrontierPoint(std::map<Point, double>&);

  double heuristic(HeuristicType, Point, Point);

 private:
  void printPath(Grid, Point, Point, std::map<Point, Point>);
};

}  // namespace DROP_3TH_ASSIGNMENT2
#endif  //__ALGORITHM_HPP_