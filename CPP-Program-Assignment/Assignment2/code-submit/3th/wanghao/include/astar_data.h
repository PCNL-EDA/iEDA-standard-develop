#ifndef ASTAR_DATA_H_
#define ASTAR_DATA_H_

#include <cstdio>
#include <cassert>
#include <utility>
#include <vector>
// #include <unordered_map>
#include <map>
#include <queue>

namespace Assignment2 {

using Node = std::pair<std::pair<int, int>, int>;
Node operator+(const Node &a, const Node &b);
bool operator==(const Node &a, const Node &b);

using Path    = std::vector<std::pair<int, int>>;
using NodeVec = std::vector<Node>;

struct cmpCost {
  bool operator()(const Node &a, const Node &b) { return a.second > b.second; }
};

using MinHeap = std::priority_queue<Node, NodeVec, cmpCost>;
using MapNN   = std::map<std::pair<int, int>, std::pair<int, int>>;
using MapNI   = std::map<Node, int>;

// will be transfered to simple pair
static const NodeVec neighbors_shift = {{{-1, -1}, 0}, {{0, -1}, 0}, {{1, -1}, 0}, {{-1, 0}, 0},
                                        {{1, 0}, 0},   {{-1, 1}, 0}, {{0, 1}, 0},  {{1, 1}, 0}};

class AstarData {
 public:
  explicit AstarData(int (*heuristic)(const std::pair<int, int> &, const std::pair<int, int> &))
      : _heuristic(heuristic), _grid_map(nullptr) {}
  ~AstarData() { delete[] _grid_map; }
  AstarData(const AstarData &)  = delete;
  AstarData(const AstarData &&) = delete;
  void operator=(const AstarData &) = delete;

  // set
  // map
  void import_grid_map_from_file(const char *file);
  void resize_grid_map(int weight, int height);
  // coordinate
  void set_start(Node &&node) { _start = node; }
  void set_end(Node &&node) { _end = node; }
  // container
  void set_cost(const Node &node, int cost) { _cost_so_far[node] = cost; }
  void add_node_to_path(const Node &from, const Node &to) { _came_from[to.first] = from.first; }
  void emptyOpenList() const { _open_list.empty(); }
  void push2OpenList(Node &node) { _open_list.emplace(node); }
  void pushStart2OpenList() {
    _cost_so_far[_start] = 0;
    push2OpenList(_start);
  }

  // get
  int get_cost(const Node &node) const { return _cost_so_far.at(node); }

  Path get_path() const {
    Path path;
    for (auto current = _end.first; current != _start.first; current = _came_from.at(current)) {
      path.emplace_back(current);
    }
    return path;
  }

  const Node &get_lowest_cost_from_open_list() {
    const Node &ret_val = _open_list.top();
    _open_list.pop();
    return ret_val;
  }

  // check
  bool isStart(const std::pair<int, int> &node) const { return node == _start.first; }
  bool isEnd(const std::pair<int, int> &node) const { return node == _end.first; }
  bool isOpenListEmpty() const { return _open_list.empty(); }
  bool hasBeenCounted(const Node &node) {
    auto iterator = _cost_so_far.find(node);
    return iterator != _cost_so_far.end();
  }

  // function
  int     calculateNeighborCost(const Node &current, const Node &next) const;
  NodeVec pack8Neighbors(const Node &);

  // display
  void displayMap() const;
  void displayPath(const Path &path) const {
    for (const auto &coordinate : path) {
      printf("{%d,%d} ", coordinate.first, coordinate.second);
    }
    putchar('\n');
  }

  // heuristic algrothm
  int heuristicCost2End(const std::pair<int, int> &node) { return _heuristic(node, _end.first); }

 private:
  // coordinate
  Node _start, _end;

  // container
  MinHeap _open_list;
  MapNN   _came_from;
  MapNI   _cost_so_far;

  // map
  int *p_grid_map_data(int x, int y) { return &_grid_map[y * _map_x_length + x]; }
  int  grid_map_data(int x, int y) const { return _grid_map[y * _map_x_length + x]; }
  int  _map_x_length, _map_y_length;
  int *_grid_map;

  // heuristic algrothm
  int (*_heuristic)(const std::pair<int, int> &, const std::pair<int, int> &);
};

}  // namespace Assignment2

#endif