/**
 * @file point.h
 * @brief Define the attributes of one point.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#ifndef INCLUDE_POINT_H_
#define INCLUDE_POINT_H_

#include "display.h"

enum class Type {
  TYPE_UNKNOWN,
  TYPE_CLOSED,
  TYPE_OPENED,
  TYPE_BARRIER,
  TYPE_PATH
};
enum class Direction { MANHATTAN, INCLINE, EUCLIDEAN, OCTAGONAL };
enum class FindDirection {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  LEFTDOWN,
  RIGHTUP,
  LEFTUP,
  RIGHTDOWN
};

class Point {

public:
  Point()
      : _x(0), _y(0), _h(0), _f(0), _g(0), _parent(nullptr),
        _type(Type::TYPE_UNKNOWN){};
  ~Point() = default;
  bool operator==(const Point &point) {
    if (_x == point._x && _y == point._y) {
      return true;
    }
    return false;
  }
  bool operator!=(const Point &point) {
    if (_x != point._x || _y != point._y) {
      return true;
    }
    return false;
  }

  int _x;
  int _y;
  int _f;
  int _g;
  int _h;
  Point *_parent;
  Type _type;
  Direction _direction;
};

#endif // INCLUDE_POINT_H_
