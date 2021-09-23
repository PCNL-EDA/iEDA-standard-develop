/**
 * @file        Point.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __POINT_HPP_
#define __POINT_HPP_

namespace DROP_3TH_ASSIGNMENT2 {

class Point {
 public:
  Point() = default;
  Point(int x, int y) { this->x = x, this->y = y; }

  bool operator!=(const Point& p) const { return x != p.x || y != p.y; }
  bool operator==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator<(const Point& p) const {
    return x < p.x || ((x == p.x) && y < p.y);
  }
  int x;
  int y;
};

}  // namespace DROP_3TH_ASSIGNMENT2
#endif