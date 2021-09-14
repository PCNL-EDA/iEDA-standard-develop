#ifndef __POINT_HPP_
#define __POINT_HPP_

class Point {
 public:
  Point(int x, int y) { this->x = x, this->y = y; }

  bool operator==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator<(const Point& p) const { return x < p.x || y < p.y; }
  int x;
  int y;
};

#endif