#include "location.h"

namespace pather{

Location Location::operator+(const Location& right) const {
  return Location(_x + right.get_x(), _y + right.get_y());
}
bool Location::operator==(const Location& right) const {
  return _x == right.get_x() && _y == right.get_y();
}
bool Location::operator!=(const Location& right) const {
  return _x != right.get_x() || _y != right.get_y();
}
bool Location::operator<(const Location& right) const {
  return _y < right.get_y() || (_y == right.get_y() && _x < right.get_x());
}

std::ostream& operator<<(std::ostream& os, Location& location) {
  os << location._x << " " << location._y;
  return os;
}

} // astar