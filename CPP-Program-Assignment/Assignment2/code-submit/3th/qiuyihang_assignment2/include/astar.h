/**
 * @file astar.h
 * @brief Core algorithm, using A* algorithm for pathfinding.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_

#include <algorithm>
#include <math.h>

#include "point.h"

using std::vector;
const int kManhattanMoveCost = 100;
const int kInclineMoveCost = 140;

namespace algorithms {
class AStar {

public:
  AStar() : endpoint_(nullptr), curpoint_(nullptr) {}
  ~AStar() {
    openlist_.clear();
    closelist_.clear();
    neighbourlist_.clear();
    allpoints_.clear();
  }
  bool foundWay() { return findway_; }
  int getFManhattan(Point *point) { return (point->g_ + getHManhattan(point)); }
  int getFEuclidean(Point *point) { return (point->g_ + getHEuclidean(point)); }
  int getFOctagonal(Point *point) { return (point->g_ + getHOctagonal(point)); }
  int getHManhattan(Point *point) {
    return (abs(endpoint_->y_ - point->y_) + abs(endpoint_->x_ - point->x_)) *
           kManhattanMoveCost;
  }
  int getHEuclidean(Point *point) {
    return sqrt((endpoint_->y_ - point->y_) * (endpoint_->y_ - point->y_) +
                (endpoint_->x_ - point->x_) * (endpoint_->x_ - point->x_)) *
           kManhattanMoveCost;
  }
  int getHOctagonal(Point *point) {
    return kManhattanMoveCost * (abs(endpoint_->x_ - point->x_) +
                                 abs(endpoint_->y_ - point->y_)) +
           (kInclineMoveCost - 2 * kManhattanMoveCost) *
               std::min(abs(endpoint_->x_ - point->x_),
                        abs(endpoint_->y_ - point->y_));
  }
  void computeNeighboringValue(vector<Point *> &nevec,
                               vector<Point *> &openlist_);
  Point *findWay(Point *beginpoint, Point *endpoint,
                 vector<vector<Point *>> &allpoints,
                 resource::Display &display);
  vector<Point *> getNeighboringPoint(Point *point, resource::Display &display);
  void getLeftDownNeighboringPoint(Point *point, resource::Display &display);
  void getLeftUpNeighboringPoint(Point *point, resource::Display &display);
  void getRightUpNeighboringPoint(Point *point, resource::Display &display);
  void getRightDownNeighboringPoint(Point *point, resource::Display &display);
  void getRightNeighboringPoint(Point *point, resource::Display &display);
  void getLeftNeighboringPoint(Point *point, resource::Display &display);
  void getUpNeighboringPoint(Point *point, resource::Display &display);
  void getDownNeighboringPoint(Point *point, resource::Display &display);

private:
  Point *endpoint_;
  Point *curpoint_;
  bool findway_;
  vector<Point *> openlist_;
  vector<Point *> closelist_;
  vector<Point *> neighbourlist_;
  vector<vector<Point *>> allpoints_;
};

} // namespace algorithms

#endif // INCLUDE_ASTAR_H_
