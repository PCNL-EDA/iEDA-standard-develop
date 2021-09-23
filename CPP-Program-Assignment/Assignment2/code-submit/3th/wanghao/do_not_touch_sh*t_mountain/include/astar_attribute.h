#ifndef NODE_ATTRIBUTE_H_
#define NODE_ATTRIBUTE_H_

#include <map>
#include "error_code.h"
using std::map;

namespace Assignment2 {

enum {
  kReachable,
  kStartNode,  // reachable but only one node that possess attribute(kStartNode) can exist in each map
  KEndNode,    // reachable but only one node that possess attribute(KEndNode) can exist in each map
  kClosed,     // reachable but in closed list
  kUnreachable,
};

static map<const int, const char *> attributes_map = {{kReachable, "Reachable"},
                                                      {kStartNode, "StartNode"},
                                                      {KEndNode, "EndNode"},
                                                      {kClosed, "Closed"},
                                                      {kUnreachable, "Unreachable"}};

class AstarAttribute {
 public:
  AstarAttribute()  = default;
  ~AstarAttribute() = default;

  kDELETE_UNUSED_CONSTRUCTOR(AstarAttribute);

  bool operator==(const AstarAttribute &obj) const { _attribute == obj._attribute; }

  // set
  void update_f(const pair<int, int> &start, const pair<int, int> &end, const pair<int, int> &curr) {
    _f_cost = _g_cost + _h_cost;
  }
  void update_g_with(const pair<int, int> &node, int node_g_cost, const pair<int, int> &curr) {
    int new_g_cost, step_cost;
    if ((node.first - curr.first) * (node.second - curr.second)) {
      step_cost = 1414;
    } else {
      step_cost = 1000;
    }
    new_g_cost = node_g_cost + step_cost;
    if (new_g_cost < _g_cost) {
      _g_cost     = new_g_cost;
      _last_visit = node;
    }
  }

  void update_g(const pair<int, int> &start, )

    void set_g(int cost) {
    _g_cost = cost;
  }
  void set_h(int cost) { _h_cost = cost; }
  void set_attribute(int attribute) { _attribute = attribute; }

  // get
  int get_node_status() const { return _attribute; }
  int get_f() const {
    paincCheck(kError_Logical_Impossible, (_f_cost == _g_cost + _h_cost));
    return _f_cost;
  }
  int get_g() const { return _g_cost; }
  int get_h() const { return _h_cost; }

  void displayAll() const {
    const char *node_attributes =
      (attributes_map.find(_attribute) == attributes_map.end()) ? "_status error" : attributes_map[_attribute];

    printf("%s\n", node_attributes);
  }

 private:
  int _attribute;
  int _f_cost;  // f=g+h
  int _g_cost;  // cost of start node to current node
  int _h_cost;  // cost of current node to end node

  pair<int, int> _last_visit;
};

}  // namespace Assignment2

#endif