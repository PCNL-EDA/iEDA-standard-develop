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

#include "point.h"
#include <algorithm>
#include <assert.h>
#include <math.h>

using std::vector;
constexpr int kManhattanMoveCost = 100;
constexpr int kInclineMoveCost = 140;

namespace model {
class AStar {

public:
  AStar() : _endpoint(nullptr), _curpoint(nullptr) {}
  ~AStar() {
    _openlist.clear();
    _closelist.clear();
    _neighbourlist.clear();
    _allpoints.clear();
  }
  int computeFCost(Point *point, const Direction &direction);
  int computeHCost(Point *point, const Direction &direction);
  bool foundWay() { return _findway; }
  void computeValueNotInOpenList(Point *point);
  void computeValueInOpenList(Point *point);
  void findOneNeighborPoint(Point *point, Display &display,
                            const FindDirection &finddirection);
  void computeNeighboringValue(vector<Point *> &nevec,
                               vector<Point *> &openlist_);
  void findWayPreprocess(Point *beginpoint, Point *endpoint,
                         vector<vector<Point *>> &allpoints);
  Point *findWay(Point *beginpoint, Point *endpoint,
                 vector<vector<Point *>> &allpoints, Display &display);
  vector<Point *> findNeighboringPoint(Point *point, Display &display);

private:
  Point *_endpoint;
  Point *_curpoint;
  bool _findway;
  vector<Point *> _openlist;
  vector<Point *> _closelist;
  vector<Point *> _neighbourlist;
  vector<vector<Point *>> _allpoints;
};

} // namespace model

#endif // INCLUDE_ASTAR_H_
