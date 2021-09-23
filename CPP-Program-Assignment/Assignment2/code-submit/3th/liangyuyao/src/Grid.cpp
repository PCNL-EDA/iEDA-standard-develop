/**
 * @file        Grid.cpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#include "Grid.hpp"

#include <assert.h>
#include <stdio.h>

namespace DROP_3TH_ASSIGNMENT2 {

std::vector<Point> Grid::getNeighbours(const Point cur) {
  std::vector<Point> neighbours;
  for (auto direct = Direction::kBegin + 1; direct < Direction::kEnd;
       ++direct) {
    if (isConnected(cur, (Direction)direct)) {
      neighbours.push_back(getDirectNeighbour(cur, (Direction)direct));
    }
  }
  return neighbours;
}

bool Grid::isConnected(Point current, Direction dir) {
  switch (dir) {
    case Direction::kNorth:
      return isUnBlocked(current.x, current.y - 1);
    case Direction::kWest:
      return isUnBlocked(current.x - 1, current.y);
    case Direction::kSouth:
      return isUnBlocked(current.x, current.y + 1);
    case Direction::kEast:
      return isUnBlocked(current.x + 1, current.y);
    case Direction::kNorthWest:
      return isUnBlocked(current.x - 1, current.y - 1);
    case Direction::kSouthWest:
      return isUnBlocked(current.x - 1, current.y + 1);
    case Direction::kSouthEast:
      return isUnBlocked(current.x + 1, current.y + 1);
    case Direction::kNorthEast:
      return isUnBlocked(current.x + 1, current.y - 1);
    default:
      assert(Direction::kBegin < dir && dir < Direction::kEnd);
      return false;
  }
}

Point Grid::getDirectNeighbour(Point current, Direction dir) {
  Point tmp;
  switch (dir) {
    case Direction::kNorth:
      tmp = Point(current.x, current.y - 1);
      break;
    case Direction::kWest:
      tmp = Point(current.x - 1, current.y);
      break;
    case Direction::kSouth:
      tmp = Point(current.x, current.y + 1);
      break;
    case Direction::kEast:
      tmp = Point(current.x + 1, current.y);
      break;
    case Direction::kNorthWest:
      tmp = Point(current.x - 1, current.y - 1);
      break;
    case Direction::kSouthWest:
      tmp = Point(current.x - 1, current.y + 1);
      break;
    case Direction::kSouthEast:
      tmp = Point(current.x + 1, current.y + 1);
      break;
    case Direction::kNorthEast:
      tmp = Point(current.x + 1, current.y - 1);
      break;
    default:
      assert(Direction::kBegin < dir && dir < Direction::kEnd);
  }
  assert(isValid(tmp.x, tmp.y));
  return tmp;
}

}  // namespace DROP_3TH_ASSIGNMENT2