#ifndef GRID_MAP_H_
#define GRID_MAP_H_

#include <vector>
#include <unordered_map>
#include <queue>
#include "graph_matrix.h"
#include "coordinate.h"
#include "astar_attribute.h"

namespace Assignment2 {

using std::hash;
using std::pair;
using std::vector;

using Node    = Coordinate<AstarAttribute>;
using NodeVec = std::vector<Node>;

struct cmpFCost {
  bool operator()(const Node &a, const Node &b) { return a.get_attribute().get_f() > b.get_attribute().get_f(); }
};

struct hashNode {
  size_t operator()(const Node &n) { return hash<int>()(n.get_x() < 1) ^ hash<int>()(n.get_y() < 5); }
};

// modify queue, add queue an iterator
template <class T, class CONTAINER, class CMP>
class IteratablePriorityQueue : public std::priority_queue<T, CONTAINER, CMP> {
 public:
  auto begin() { return c.begin(); }
  auto end() { return c.end(); }
  auto find(const pair<const int, const int> &val) {
    for (const auto &node : c) {
      if (node.get_x() == val.first && node.get_y() == val.second) {
        return node;
      }
    }
    return c.end();
  }
};

using MinHeap = IteratablePriorityQueue<Node, std::vector<Node>, cmpFCost>;
using HashMap = std::unordered_map<pair<int, int>, Node, hashNode>;

static const vector<pair<int, int>> neighbors = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> b) {
  int first  = a.first + b.first;
  int second = a.second + b.second;
  return pair<int, int>(first, second);
}

/**
 * @brief 2D grid map with unaccessable point
 */
class AstarData {
 public:
  AstarData() = default;

  kDELETE_UNUSED_CONSTRUCTOR(AstarData);

  // set
  void import_obstacles_from_file(const char *);
  void add_obstacles(pair<int, int> &&node) { _obstacles.emplace(Node(node)); }
  void set_start(pair<int, int> start) { _start = start; }
  void set_end(pair<int, int> end) { _end = end; }
  void clear_obstacles() { _obstacles.clear(); }
  void clear_close_list() { _close_list.clear(); }
  void clear_open_list() {
    MinHeap clear;
    std::swap(clear, _open_list);
  }

  /**
   * @brief set node to open_list, and calculate f
   * @param node
   */
  void push2OpenList(pair<int, int> node) {
    Node new_node(node);
    new_node.get_attribute().update_f();
    _open_list.push(new_node);
  }
  void push2OpenList_start() { _open_list.push(_start); }

  void popLowestFCostFromOpenList() {
    _curr = &_open_list.top();
    _open_list.pop();
  }

  void pushCurrent2CloseList() { _close_list.emplace(_curr->get_pair(), *_curr); }

  void pushNeighbor2OpenList();

  bool inOpenList(const pair<const int, const int> &node) {
    // bad time efficiency
    auto iterator_open = _open_list.find(node);
    return iterator_open != _open_list.end();
  }
  bool inCloseList(const pair<const int, const int> &node) {
    auto iterator_closed = _close_list.find(node);
    return iterator_closed != _close_list.end();
  }

  vector<pair<int, int>> &packReachableNeighbor();

  bool isCurrentDestination() const { return isDestination(*_curr); }

  bool isOpenListEmpty() const { return _open_list.empty(); }
  bool isReachable(const pair<const int, const int> &) const;
  bool isReachable_Start() const { isReachable(std::make_pair<const int, const int>(_start.get_x(), _start.get_y())); }
  bool isDestination(const pair<const int, const int> &node) const { return _end == node; }
  bool isDestination(const Node &node) const { return _end == node; }

  // regular functions
  void displayAll();
  void displayGridMap();

 private:
  pair<int, int> _x_axis;  // _x_axis.first is the lowest bound of x axis, _x_axis.second is the highest bound
  pair<int, int> _y_axis;  // same as _x_axis

  Node _start;
  Node _end;

  const Node *_curr;

  HashMap _obstacles;

  MinHeap _open_list;
  HashMap _close_list;
};

}  // namespace Assignment2
#endif