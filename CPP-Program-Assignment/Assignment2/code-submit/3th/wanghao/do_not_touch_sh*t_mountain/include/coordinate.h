#ifndef COORDINATE_H_
#define COORDINATE_H_

#include "error_code.h"

using std::pair;

namespace Assignment2 {

/**
 * @brief
 *
 * @note
 * requires function implementation of "void displayAll()" in class Attribute
 */
template <class Attribute>
class Coordinate {
 public:
  Coordinate() : _coordinate({0, 0}), _attribute() {}
  Coordinate(int x, int y) : _coordinate({x, y}) {}
  explicit Coordinate(pair<int, int> coordinate) : _coordinate(coordinate) {}
  ~Coordinate() = default;

  kDELETE_UNUSED_CONSTRUCTOR(Coordinate);
  // explicit Coordinate(const Coordinate &coordinate)
  //     : _x(coordinate.first), _y(coordinate.second), _attribute(coordinate._attribute) {}
  // Coordinate(const Coordinate &&) = delete;
  // void operator=(const Coordinate &) = delete;

  Coordinate<Attribute> &operator=(const pair<int, int> coordinate) {
    _coordinate = coordinate;
    return *this;
  }
  bool operator==(const Coordinate<Attribute> &obj) const { return _coordinate == obj.get_pair(); }
  bool operator==(const pair<const int, const int> &obj) const { return _coordinate == obj; }

  // get
  int get_x(int num = 0) const { return _coordinate.first + num; }
  int get_y(int num = 0) const { return _coordinate.second + num; }

  pair<int, int> get_pair() const { return _coordinate; }

  Attribute &get_attribute() const { return _attribute; }

  void what_am_I() const { _attribute.displayAll(); }
  void where_am_I() const { printf("x,y:(%d, %d)", _coordinate.first, _coordinate.second); }

  // set
  void set_x(int x) { _coordinate.first = x; }
  void set_y(int y) { _coordinate.second = y; }

  // void move_up(int steps) { _y += steps; }
  // void move_down(int steps) { _y -= steps; }
  // void move_left(int steps) { _x -= steps; }
  // void move_right(int steps) { _x += steps; }

  /**
   * @brief reset by a pair of {x,y}
   */
  Coordinate reset_coordinate(pair<int, int> &coordinate) {
    _coordinate = coordinate;
    return *this;
  }

  /**
   * @brief reset by another Coordinate instance
   */
  Coordinate reset_coordinate(const Coordinate &coordinate) {
    _coordinate = coordinate.get_pair();
    return *this;
  }

 private:
  // private data:
  pair<int, int> _coordinate;  // 2D coordinate (x,y)
  Attribute      _attribute;   // coordinate's type/data/etc...
};

}  // namespace Assignment2

#endif