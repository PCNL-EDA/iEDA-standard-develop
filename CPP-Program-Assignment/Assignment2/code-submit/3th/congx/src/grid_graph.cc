#include "grid_graph.h"

namespace pather {

std::vector<Location> GridGraph::adjacentNodes(const Location& current) const {
  std::vector<Location> adjacents;

  for (auto direction : _directions) {
    Location next = current + direction;
    if (inBounds(next) && passable(next)) {
      adjacents.push_back(next);
    }
  }
  return adjacents;
}

bool GridGraph::inBounds(const Location& current) const {
  auto x = current.get_x();
  auto y = current.get_y();
  return (0 <= x) && (x < _width) && (0 <= y) && (y < _height);
}

bool GridGraph::passable(const Location& current) const {
  return _barriers.find(current) == _barriers.end();
}

double GridGraph::edgeWeight(const Location& begin, const Location& end) const {
  return (begin.get_x() == end.get_x() || begin.get_y() == end.get_y()) ? 1
                                                                        : 1.4;
}

std::array<Location, 8> GridGraph::_directions = {
    /// east west south north  northeast southeast southwest northwest
    Location(1, 0),  Location(-1, 0), Location(0, 1),  Location(0, -1),
    Location(1, -1), Location(1, 1),  Location(-1, 1), Location(-1, -1)};

}  // namespace pather