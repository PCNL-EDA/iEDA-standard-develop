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
enum class Direction { MANHATTAN, INCLINE };

class Point {

public:
  Point()
      : x_(0), y_(0), h_(0), f_(0), g_(0), parent_(nullptr),
        type_(Type::TYPE_UNKNOWN){};
  ~Point(){};
  bool operator==(const Point &point) {
    if (x_ == point.x_ && y_ == point.y_) {
      return true;
    }
    return false;
  }
  bool operator!=(const Point &point) {
    if (x_ != point.x_ || y_ != point.y_) {
      return true;
    }
    return false;
  }

  int x_;
  int y_;
  int f_;
  int g_;
  int h_;
  Point *parent_;
  Type type_;
  Direction direction_;
};

#endif // INCLUDE_POINT_H_
