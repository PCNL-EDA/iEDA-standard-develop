/**
 * @file graph.h
 * @author congx
 * @brief This is a class for nodes location in the graph
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_LOCATION_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_LOCATION_H_

#include <iostream>

namespace pather {

enum : char { kBarrier = '#', kPassable = '*', kTrack = '@' };

class Location {
  friend std::ostream& operator<<(std::ostream& os, Location& location);

 public:
  Location() : _x(0), _y(0) {}
  Location(int x, int y) : _x(x), _y(y) {}

  int get_x() const { return _x; };
  int get_y() const { return _y; }
  void set_x(int x) { _x = x; }
  void set_y(int y) { _y = y; }

  Location operator+(const Location& right) const;
  bool operator==(const Location& right) const;
  bool operator!=(const Location& right) const;
  bool operator<(const Location& right) const;

 private:
  int _x;
  int _y;
};

std::ostream& operator<<(std::ostream& os, Location& location);

}  // namespace pather

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT2_CODE_SUBMIT_CONGX_LOCATION_H_
