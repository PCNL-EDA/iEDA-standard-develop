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
  Coordinate(int x, int y) : _x(x), _y(y) {}
  explicit Coordinate(pair<int, int> coordinate) : _x(coordinate.first), _y(coordinate.second) {}
  ~Coordinate() = default;

  Coordinate(const Coordinate &)  = delete;
  Coordinate(const Coordinate &&) = delete;

  // operator
  void operator=(const Coordinate &) = delete;
  // Coordinate &operator[](const int) { return *this; }

  // get
  inline int get_x() const { return _x; }
  inline int get_y() const { return _y; }

  inline void what_am_I() const { _attribute.displayAll(); }
  inline void where_am_I() const { printf("(%d, %d)", _x, _y); }

  // set
  inline void set_x(int x) { _x = x; }
  inline void set_y(int y) { _y = y; }

  inline void move_up(int steps) { _y += steps; }
  inline void move_down(int steps) { _y -= steps; }
  inline void move_left(int steps) { _x -= steps; }
  inline void move_right(int steps) { _x += steps; }

  /**
   * @brief reset by a pair of {x,y}
   */
  inline Coordinate &reset_coordinate(pair<int, int> coordinate) {
    _x = coordinate.first;
    _y = coordinate.second;
    return *this;
  }

  /**
   * @brief reset by another Coordinate instance
   */
  inline Coordinate &reset_coordinate(const Coordinate &coordinate) {
    _x = coordinate.get_x();
    _y = coordinate.get_y();
    return *this;
  }

 private:
  // private data:
  int       _x, _y;      // 2D coordinate (x,y)
  Attribute _attribute;  // coordinate's type/data/etc...
};

}  // namespace Assignment2

#endif