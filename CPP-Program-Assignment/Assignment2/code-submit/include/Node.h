/**
 * @file        Node.h
 * @brief       store the information of node,as element of instance of class Map
 * @author      liujikang
 * @date        2021-07-31
 * @copyright   liujikang
 * 
 */ 

#ifndef CODE_SUBMIT_INCLUDE_NODE_H_
#define CODE_SUBMIT_INCLUDE_NODE_H_

namespace astar {

enum class NodeType {
  kObstacle = -1,
  kNormal = 0,
  kStart = 1,
  kEnd = 2
};

enum class NodeState {
  kNormal = 0,
  kOpen = 1,
  kClose = 2
};

class Node {
 public:
  Node() {}   ///< non-need param-constructor
  ~Node() { _parent = nullptr; }

  ///< get or set variables
  int get_index_x() const { return _index_x; }
  int get_index_y() const { return _index_y; }
  NodeType& get_type() { return _type; }
  NodeState& get_state() { return _state; }
  Node * get_parent() { return _parent; }
  double get_cost_start() const { return _curr_start_cost; }
  double get_cost_end() const { return _curr_end_cost; }
  double get_cost_path() const { return _total_cost; }

  void set_index_x(const int x) { _index_x = x; }
  void set_index_y(const int y) { _index_y = y; }
  void set_type(const NodeType &type) { _type = type; }
  void set_state(const NodeState &state) { _state = state; }
  void set_parent(Node* parent) { _parent = parent; }
  void set_cost_start(const double cost_start) { _curr_start_cost = cost_start; }
  void set_cost_end(const double cost_end) { _curr_end_cost = cost_end; }
  void set_cost_path(const double cost_path) { _total_cost = cost_path; }

  ///< function
  
 private:
  int _index_x = 0;
  int _index_y = 0;
  NodeType _type = NodeType::kNormal;
  NodeState _state = NodeState::kNormal;
  Node * _parent = nullptr;
  double _curr_start_cost = 0;
  double _curr_end_cost = 0;
  double _total_cost = 0;
};
}  // namespace astar
#endif  // CODE_SUBMIT_INCLUDE_NODE_H_
