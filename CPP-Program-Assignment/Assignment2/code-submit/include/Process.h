/**
 * @file        process
 * @brief       the
 * @author      liujikang    
 * @date        2021-07-30
 * @copyright   liujikang
 */ 
#include "GridMap.h"
#include "Node.h"

#include <vector>
#include <utility>

#ifndef CODE_SUBMIT_INCLUDE_PROCESS_H_
#define CODE_SUBMIT_INCLUDE_PROCESS_H_
namespace astar {
class Process {
 public:
  Process() {}
  ~Process() { destoryProcess(); }

  ///< getter
  std::vector<Node>& get_openlist() { return _openlist; }
  Node* get_start_node() { return _start_node; }
  Node* get_end_node() { return _end_node; }

  ///< function
  void setNode(const std::pair<int, int>& p, const NodeType& nodeType);
  void setMapSize(int row_num, int col_num);
  void setStartnode(const int index_x, const int index_y);
  void setEndNode(const int index_x, const int index_y);
  void setObstacleNode(const std::vector<std::pair<int, int>>& obstacleList);
  // void initGridMap(int row_size, int col_size,
  //                 std::vector<std::pair<int, int>> obstacleList);
  void initOpenlist();


  bool isInOpenlist(const Node& node);
  bool compare(const Node& n1, const Node& n2);
  void sortOpenlist();

  void findPath();
  void printPath();
  void printMap();
  void destoryProcess();
 private:
  GridMap<Node> _gridmap;
  std::vector<Node> _openlist;
  Node* _start_node = nullptr;
  Node* _end_node = nullptr;
  Node* _curr_node = nullptr;
};
}  // namespace astar

#endif  // CODE_SUBMIT_INCLUDE_PROCESS_H_
