/**
 * @file        process
 * @brief       the content function of A-STAR algorithm
 * @author      liujikang    
 * @date        2021-07-31
 * @copyright   liujikang
 */ 
#include "GridMap.h"
#include "Node.h"

#include <vector>
#include <utility>

#ifndef CODE_SUBMIT_LIUJIKANG_INCLUDE_PROCESS_H_
#define CODE_SUBMIT_LIUJIKANG_INCLUDE_PROCESS_H_
namespace astar {

 /**
   * @class     Process
   * @brief     a Process instance stores all functions needed by A-start algorithm,\n
   *            including the function of initializing the grid Map and performing the optimal path finding function, 
   *            and the path output function.
  */
class Process {
 public:
  Process() = default;
  ~Process() = default;

  ///< getter
  std::vector<Node*>& get_openlist() { return _openlist; }
  Node* get_start_node() { return _start_node; }
  Node* get_end_node() { return _end_node; }
  Node* get_curr_node() { return _curr_node; }

  ///< initialization function of GridMap and nodes
  void setNode(const std::pair<int, int>& p, const NodeType& nodeType);
  void setMapSize(int row_num, int col_num);
  void setStartnode(const int index_x, const int index_y);
  void setEndNode(const int index_x, const int index_y);
  void setObstacleNode(const std::vector<std::pair<int, int>>& obstacleList);
  void initOpenlist();

  ///< Operation function of A-STAR algorithm
  bool isEndNode(Node* n);
  bool isObsNode(Node* n);
  bool isInOpenlist(Node* node);
  bool isInCloseList(Node* node);
  void sortOpenlist();
  bool isLegalNeighbor(int x, int y);
  double getCostCurrToNeighbor(Node* neighbor);
  bool isBetterParentByCurr(Node* neighbor);
  void inviteNeighborByCur(std::vector<Node*>& neighborList);
  void updateNeighborParent(Node* node);
  double calCostCurrToEnd(Node* node);
  void addNeighborToOpen();
  
  ///< Print function of the optimal path
  bool findPath();
  void printPath(Node* node);
  void printMap();
  void destoryProcess();
 private:
  GridMap<Node> _gridmap;
  std::vector<Node*> _openlist;
  Node* _start_node = nullptr;
  Node* _end_node = nullptr;
  Node* _curr_node = nullptr;
};

}  // namespace astar

#endif  // CODE_SUBMIT_LIUJIKANG_INCLUDE_PROCESS_H_
