/**
 * @file astar.cpp
 * @brief Core algorithm, using A* algorithm for pathfinding.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "astar.h"

namespace model {

bool SortCompare(const Point *point1, const Point *point2) {
  return point1->_f < point2->_f;
}

void AStar::findWayPreprocess(Point *beginpoint, Point *endpoint,
                              vector<vector<Point *>> &allpoints) {
#ifndef _GTEST
  printf("\e[0;32m[SUCCESS]\033[0m point->findWay(): Finding the shortest path "
         "using AStar Algorithms.\n"
         "\e[0;34mThe startpoint:[%d][%d] ---> The endpoint:[%d][%d]\033[0m\n",
         beginpoint->_x, beginpoint->_y, endpoint->_x, endpoint->_y);
#endif
  _allpoints = allpoints;
  _endpoint = endpoint;
  if (_endpoint->_type == Type::TYPE_BARRIER) {
    printf("The end point is an obstacle.\n");
    _findway = false;
    assert(false);
  }
  if (*_endpoint == *beginpoint) {
    printf("The start and end points are the same.\n");
    _findway = false;
    assert(false);
  }
  _openlist.push_back(beginpoint);
  beginpoint->_type = Type::TYPE_OPENED;
  beginpoint->_f = computeFCost(beginpoint, Direction::OCTAGONAL);
}
/**
 * @brief  A star algorithms implementation.
 * @link   https://www.redblobgames.com/pathfinding/a-star/introduction.html
 * @param  *beginpoint: the startpoint
 * @param  *endpoint: the endpoint
 * @param  &allpoints: the girdmap
 * @param  &display: the information of input file
 * @retval all the points in the shortest path
 */
Point *AStar::findWay(Point *beginpoint, Point *endpoint,
                      vector<vector<Point *>> &allpoints, Display &display) {
  findWayPreprocess(beginpoint, endpoint, allpoints);

  int step_count = 0;
  do {
    ++step_count;
    _curpoint = _openlist[0];
#ifndef _GTEST
    printf("\e[0;34mStep %d: point[%d][%d] is selected\033[0m \n", step_count,
           _curpoint->_x, _curpoint->_y);
#endif
    _openlist.erase(_openlist.begin());
    _curpoint->_type = Type::TYPE_CLOSED;
    _closelist.push_back(_curpoint);
    if (*_curpoint == *_endpoint) {
      _findway = true;
#ifndef _GTEST
      printf("Found way and end searching.\n");
#endif
      return _curpoint;
    }
    vector<Point *> nevec = findNeighboringPoint(_curpoint, display);
    computeNeighboringValue(nevec, _openlist);
    sort(_openlist.begin(), _openlist.end(), SortCompare);
  } while (_openlist.size() > 0);
  printf("\e[0;32m[FAILURE]\033[0m Can not find way.\n");
  _findway = false;
  return nullptr;
}

vector<Point *> AStar::findNeighboringPoint(Point *point, Display &display) {
  _neighbourlist.clear();
  findOneNeighborPoint(point, display, FindDirection::LEFTDOWN);
  findOneNeighborPoint(point, display, FindDirection::LEFTUP);
  findOneNeighborPoint(point, display, FindDirection::RIGHTDOWN);
  findOneNeighborPoint(point, display, FindDirection::RIGHTUP);
  findOneNeighborPoint(point, display, FindDirection::LEFT);
  findOneNeighborPoint(point, display, FindDirection::RIGHT);
  findOneNeighborPoint(point, display, FindDirection::UP);
  findOneNeighborPoint(point, display, FindDirection::DOWN);
  return _neighbourlist;
}

int AStar::computeFCost(Point *point, const Direction &direction) {
  switch (direction) {
  case Direction::OCTAGONAL:
    return (point->_g + computeHCost(point, Direction::OCTAGONAL));
    break;
  case Direction::MANHATTAN:
    return (point->_g + computeHCost(point, Direction::MANHATTAN));
    break;
  case Direction::EUCLIDEAN:
    return (point->_g + computeHCost(point, Direction::EUCLIDEAN));
    break;
  default:
    return (point->_g + computeHCost(point, Direction::OCTAGONAL));
  }
}

int AStar::computeHCost(Point *point, const Direction &direction) {
  switch (direction) {
  case Direction::OCTAGONAL:
    return kManhattanMoveCost * (abs(_endpoint->_x - point->_x) +
                                 abs(_endpoint->_y - point->_y)) +
           (kInclineMoveCost - 2 * kManhattanMoveCost) *
               std::min(abs(_endpoint->_x - point->_x),
                        abs(_endpoint->_y - point->_y));
    break;
  case Direction::MANHATTAN:
    return (abs(_endpoint->_y - point->_y) + abs(_endpoint->_x - point->_x)) *
           kManhattanMoveCost;
    break;
  case Direction::EUCLIDEAN:
    return sqrt((_endpoint->_y - point->_y) * (_endpoint->_y - point->_y) +
                (_endpoint->_x - point->_x) * (_endpoint->_x - point->_x)) *
           kManhattanMoveCost;
    break;
  default:
    return kManhattanMoveCost * (abs(_endpoint->_x - point->_x) +
                                 abs(_endpoint->_y - point->_y)) +
           (kInclineMoveCost - 2 * kManhattanMoveCost) *
               std::min(abs(_endpoint->_x - point->_x),
                        abs(_endpoint->_y - point->_y));
  }
}

void AStar::findOneNeighborPoint(Point *point, Display &display,
                                 const FindDirection &finddirection) {
  switch (finddirection) {
  case FindDirection::LEFT:
    if (point->_x > 0) {
      if (_allpoints[point->_x - 1][point->_y]->_type != Type::TYPE_BARRIER) {
        _allpoints[point->_x - 1][point->_y]->_direction = Direction::MANHATTAN;
        _neighbourlist.push_back(_allpoints[point->_x - 1][point->_y]);
      }
    }
    break;
  case FindDirection::RIGHT:
    if (point->_x < display.get_max_row() - 1) {
      if (_allpoints[point->_x + 1][point->_y]->_type != Type::TYPE_BARRIER) {
        _allpoints[point->_x + 1][point->_y]->_direction = Direction::MANHATTAN;
        _neighbourlist.push_back(_allpoints[point->_x + 1][point->_y]);
      }
    }
    break;
  case FindDirection::DOWN:
    if (point->_y > 0) {
      if (_allpoints[point->_x][point->_y - 1]->_type != Type::TYPE_BARRIER) {
        _allpoints[point->_x][point->_y - 1]->_direction = Direction::MANHATTAN;
        _neighbourlist.push_back(_allpoints[point->_x][point->_y - 1]);
      }
    }
    break;
  case FindDirection::UP:
    if (point->_y < display.get_max_colunm() - 1) {
      if (_allpoints[point->_x][point->_y + 1]->_type != Type::TYPE_BARRIER) {
        _allpoints[point->_x][point->_y + 1]->_direction = Direction::MANHATTAN;
        _neighbourlist.push_back(_allpoints[point->_x][point->_y + 1]);
      }
    }
    break;
  case FindDirection::LEFTUP:
    if (point->_x > 0 && point->_y < display.get_max_colunm() - 1) {
      if (_allpoints[point->_x - 1][point->_y + 1]->_type !=
          Type::TYPE_BARRIER) {
        if (!(_allpoints[point->_x - 1][point->_y]->_type ==
                  Type::TYPE_BARRIER &&
              _allpoints[point->_x][point->_y + 1]->_type ==
                  Type::TYPE_BARRIER)) {
          _allpoints[point->_x - 1][point->_y + 1]->_direction =
              Direction::INCLINE;
          _neighbourlist.push_back(_allpoints[point->_x - 1][point->_y + 1]);
        }
      }
    }
    break;
  case FindDirection::LEFTDOWN:
    if (point->_x > 0 && point->_y > 0) {
      if (_allpoints[point->_x - 1][point->_y - 1]->_type !=
          Type::TYPE_BARRIER) {
        if (!(_allpoints[point->_x - 1][point->_y]->_type ==
                  Type::TYPE_BARRIER &&
              _allpoints[point->_x][point->_y - 1]->_type ==
                  Type::TYPE_BARRIER)) {
          _allpoints[point->_x - 1][point->_y - 1]->_direction =
              Direction::INCLINE;
          _neighbourlist.push_back(_allpoints[point->_x - 1][point->_y - 1]);
        }
      }
    }
    break;
  case FindDirection::RIGHTUP:
    if (point->_x < display.get_max_row() - 1 &&
        point->_y < display.get_max_colunm() - 1) {
      if (_allpoints[point->_x + 1][point->_y + 1]->_type !=
          Type::TYPE_BARRIER) {
        if (!(_allpoints[point->_x + 1][point->_y]->_type ==
                  Type::TYPE_BARRIER &&
              _allpoints[point->_x][point->_y + 1]->_type ==
                  Type::TYPE_BARRIER)) {
          _allpoints[point->_x + 1][point->_y + 1]->_direction =
              Direction::INCLINE;
          _neighbourlist.push_back(_allpoints[point->_x + 1][point->_y + 1]);
        }
      }
    }
    break;
  case FindDirection::RIGHTDOWN:
    if (point->_x < display.get_max_row() - 1 && point->_y > 0) {
      if (_allpoints[point->_x + 1][point->_y - 1]->_type !=
          Type::TYPE_BARRIER) {
        if (!(_allpoints[point->_x + 1][point->_y]->_type ==
                  Type::TYPE_BARRIER &&
              _allpoints[point->_x][point->_y - 1]->_type ==
                  Type::TYPE_BARRIER)) {
          _allpoints[point->_x + 1][point->_y - 1]->_direction =
              Direction::INCLINE;
          _neighbourlist.push_back(_allpoints[point->_x + 1][point->_y - 1]);
        }
      }
    }
    break;
  }
}

void AStar::computeValueNotInOpenList(Point *tmpoint) {
  tmpoint->_parent = _curpoint;
  if (tmpoint->_direction == Direction::MANHATTAN) {
    tmpoint->_g = _curpoint->_g + kManhattanMoveCost;
#ifndef _GTEST
    printf("point[%d][%d]:\tvalue_G=%d", tmpoint->_x, tmpoint->_y, tmpoint->_g);
#endif
  } else {
    tmpoint->_g = _curpoint->_g + kInclineMoveCost;
#ifndef _GTEST
    printf("point[%d][%d]:\tvalue_G=%d", tmpoint->_x, tmpoint->_y, tmpoint->_g);
#endif
  }
  tmpoint->_h = computeHCost(tmpoint, Direction::OCTAGONAL);
  tmpoint->_f = computeFCost(tmpoint, Direction::OCTAGONAL);
#ifndef _GTEST
  printf("\tvalue_H=%d\tvalue_F=%d\n", tmpoint->_h, tmpoint->_f);
#endif
  _openlist.push_back(tmpoint);
  tmpoint->_type = Type::TYPE_OPENED;
}

void AStar::computeValueInOpenList(Point *tmpoint) {
  if (tmpoint->_h < _curpoint->_h) {
    tmpoint->_parent = _curpoint;
    if (tmpoint->_direction == Direction::MANHATTAN) {
      tmpoint->_g = _curpoint->_g + kManhattanMoveCost;
    } else {
      tmpoint->_g = _curpoint->_g + kInclineMoveCost;
    }
    tmpoint->_f = computeFCost(tmpoint, Direction::OCTAGONAL);
  }
#ifndef _GTEST
  printf("point[%d][%d]:\tvalue_G=%d\tvalue_H=%d\tvalue_F=%d\n", tmpoint->_x,
         tmpoint->_y, tmpoint->_g, tmpoint->_h, tmpoint->_f);
#endif
}

void AStar::computeNeighboringValue(vector<Point *> &nevec,
                                    vector<Point *> &openlist_) {
  for (int i = 0; i < nevec.size(); ++i) {
    auto tmpoint = nevec[i];
    if (tmpoint->_type == Type::TYPE_CLOSED) {
      continue;
    }
    if (tmpoint->_type != Type::TYPE_OPENED) {
      computeValueNotInOpenList(tmpoint);
    } else {
      computeValueInOpenList(tmpoint);
    }
  }
}

} // namespace model
