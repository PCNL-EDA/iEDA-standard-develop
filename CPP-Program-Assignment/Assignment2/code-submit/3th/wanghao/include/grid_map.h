#ifndef GRID_MAP_H_
#define GRID_MAP_H_

#include <set>
#include <map>
#include "graph_matrix.h"
#include "coordinate.h"

using std::map;

namespace Assignment2 {

enum {
  kReachable   = 0,
  kLastVisit   = 1,  // reachable but only one node that possess attribute(kLastVisit) can exist in each map
  kStartNode   = 2,  // reachable but only one node that possess attribute(kStartNode) can exist in each map
  KEndNode     = 3,  // reachable but only one node that possess attribute(KEndNode) can exist in each map
  kUnreachable = 4,
};

static map<const int, const char *> info_map = {{kReachable, "Reachable"},
                                                {kLastVisit, "LastVisit"},
                                                {kStartNode, "StartNode"},
                                                {KEndNode, "EndNode"},
                                                {kUnreachable, "Unreachable"}};

class NodeAttribute {
 public:
  NodeAttribute();
  ~NodeAttribute();

  void displayAll() {
    printf("%s\n", (info_map.find(_status) == info_map.end() ? "_status error" : info_map[_status]));
  }

 private:
  int _status;
};

using std::set;
using Node = Coordinate<NodeAttribute>;

auto cmp = [](const Node &a, const Node &b) { return (a.get_x() > b.get_x()); };

/**
 * @brief 2D grid map with obstacles
 */
class GridMap {
 public:
  GridMap() : _obstacles(cmp) {}
  ~GridMap() = default;

  GridMap(const GridMap &)  = delete;
  GridMap(const GridMap &&) = delete;

  void operator=(const GridMap &) = delete;

  // set
  void import_data_from_file(const char *);
  void add_obstacles(const set<Node> &);
  void resize(int, int);
  void clear_all();
  void clear_obstacles();

  // regular functions
  void displayAll();
  void displayMapInfo();
  void displayGridMap();

 private:
  GraphMatrix<Node>        _map;
  set<Node, decltype(cmp)> _obstacles;
};

}  // namespace Assignment2
#endif