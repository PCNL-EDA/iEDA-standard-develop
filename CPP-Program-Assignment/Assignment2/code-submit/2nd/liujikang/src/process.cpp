/**
 * @file        Process.cpp
 * @brief       
 * @author      liujikang
 * @date        2021/07/30
 * @copyright   liujikang
 *
 */

#include <assert.h>
#include <iostream>
#include <algorithm>
#include "../include/Process.h"


namespace astar {

void Process::setNode(const std::pair<int, int>& p, const NodeType& nodeType) {
  int x = p.first;
  int y = p.second;
  int rowNum = _gridmap.get_row_num();
  int colNum = _gridmap.get_col_num();
  assert(x >= 0 && x < rowNum);
  assert(y >= 0 && y < colNum);
  _gridmap[x][y].set_index_x(x);
  _gridmap[x][y].set_index_y(y);
  _gridmap[x][y].set_type(nodeType);
}

void Process::setMapSize(int row_num, int col_num) {
  assert(row_num >= 0 && col_num >= 0);
  _gridmap.initArrNode(row_num, col_num);
  for (int i = 0; i < _gridmap.get_row_num(); i++) {
    for (int j = 0; j < _gridmap.get_col_num(); j++) {
        _gridmap[i][j].set_index_x(i);
        _gridmap[i][j].set_index_y(j);
    }
  }
}

void Process::setStartnode(const int index_x, const int index_y) {
  _start_node = &_gridmap[index_x][index_y];
  setNode({index_x, index_y}, NodeType::kStart);
}

void Process::setEndNode(const int index_x, const int index_y) {
  _end_node = &_gridmap[index_x][index_y];
  setNode({index_x, index_y}, NodeType::kEnd);
}

void Process::setObstacleNode(const std::vector<std::pair<int, int>>& obstacleList) {
  for (int i = 0; i < obstacleList.size(); i++) {
    setNode(obstacleList[i], NodeType::kObstacle);
  }
}

bool Process::isEndNode(Node* n) {
  return n->get_type() == NodeType::kEnd;
}

bool Process::isObsNode(Node* n) {
  return n->get_type() == NodeType::kObstacle;
}

bool Process::isInOpenlist(Node* node) {
  return node->get_state() == NodeState::kOpen;
}

bool Process::isInCloseList(Node* node) {
  return node->get_state() == NodeState::kClose;
}

bool Process::isLegalNeighbor(int x, int y) {
  return (0 <= x && x < _gridmap.get_row_num()) &&
             (0 <= y && y < _gridmap.get_col_num());
}

/**
 * @brief     The path cost of the movement in the diagonal direction is defined as 1.44, 
 *            and the cost of the movement in the horizontal and vertical directions is defined as 1.
 * @param     the pointer to neighbor node.
 * @return    the path cost.
 *            
 */ 
double Process::getCostCurrToNeighbor(Node* neighbor) {
  double x_offset = abs(neighbor->get_index_x() - _curr_node->get_index_x());
  double y_offset = abs(neighbor->get_index_y() - _curr_node->get_index_y());
  double cost_offset = x_offset + y_offset;
  if (cost_offset == static_cast<double>(1)) {
    return static_cast<double> (1);
  } else {
    return static_cast<double> (1.44);
  }
}

/**
 * @details     The path cost from the starting point to the neighboring node through the current node, 
 *              and the path cost saved by the neighboring node. 
 *              If the former is less than the latter, it returns true, otherwise it returns false.
 * @param       neighbor type Node *
 * @return      true or false     
 */ 
bool Process::isBetterParentByCurr(Node* neighbor) {
  double cost_Curr_Nei = getCostCurrToNeighbor(neighbor);
  if (_curr_node->get_start_cost() + cost_Curr_Nei <
      neighbor->get_start_cost()) {
    return true;
  }
  return false;
}

void Process::inviteNeighborByCur(std::vector<Node*>& neighborList) {
  int x = _curr_node->get_index_x();
  int y = _curr_node->get_index_y();
  std::vector<std::pair<int, int>> offsetList = {
                        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  for (int i = 0; i < offsetList.size(); i++) {
    int neigh_x = x + offsetList[i].first;
    int neigh_y = y + offsetList[i].second;
    if (isLegalNeighbor(neigh_x, neigh_y)) {
      neighborList.push_back(&_gridmap[neigh_x][neigh_y]);
    }
  }
}

void Process::updateNeighborParent(Node* node) {    // no use now
  node->set_parent(_curr_node);
}

/**
 * @brief     The estimating function used to estimate the path cost from the current node to the destination, 
 *            using Manhattan distance.
 */ 
double Process::calCostCurrToEnd(Node* node) {
  double costToEnd = std::abs(_end_node->get_index_x() - node->get_index_x()) +
                    std::abs(_end_node->get_index_y() - node->get_index_y());
  return costToEnd;
}

/**
 * @brief     push neighbor node of current-node in _openlist \n
 *            if the neighbor node meet the conditions.
 * @note      the call sort of other function in addNeighborToOPen.
 */ 
void Process::addNeighborToOpen() {
  std::vector<Node*> neighborList;
  inviteNeighborByCur(neighborList);
  for (Node* neighbor : neighborList) {
    ///< the neighbor node is obstacle or included in closelist
    if (isInCloseList(neighbor) || isObsNode(neighbor)) {
      continue;
    }
    ///< if the neighnor node included in openlist,
    ///< judge the cost from start to neighbor,modify the value
    if (isInOpenlist(neighbor)) {
      if (isBetterParentByCurr(neighbor)) {
        double curr_cost = getCostCurrToNeighbor(neighbor);
        double cost_start_to_curr = curr_cost + _curr_node->get_start_cost();
        neighbor->set_cost_start(cost_start_to_curr);
        neighbor->updateTotalCost();
        updateNeighborParent(_curr_node);
      }
    } else {
      ///< neighbor node out of openlist,
      ///< new instance and assign values,then push into openlist
      double costCurrToNei = getCostCurrToNeighbor(neighbor);
      double costToStart = _curr_node->get_start_cost() + costCurrToNei;
      double costToEnd = calCostCurrToEnd(neighbor);
      neighbor->set_cost_start(costToStart);
      neighbor->set_cost_end(costToEnd);
      neighbor->updateTotalCost();
      neighbor->set_parent(_curr_node);

      _openlist.push_back(neighbor);
    }
  }
}

bool compare(Node* n1, Node* n2) {
  return n1->get_total_cost() < n2->get_total_cost();
}

/**
 * @brief     find the optimal path by using a-star algorithm.
 * @details   in the step, push the _start_node in _openlist, the _start_node is the min-cost node,
 *            get its neighbor nodes in a vectoer container, then call the sort function operator _openlist.
 *            erase the _start_node from openlist, add _start_node to path.
 *            repeat the operation if _openlist is not empty, if find _end_node, return true, if not return false;
 * @return    true or false
 */ 
bool Process::findPath() {
  _openlist.push_back(_start_node);
  bool findPath = false;
  while (!_openlist.empty()) {
    _curr_node = _openlist[0];
    if (isEndNode(_curr_node)) {  ///< if the cur_node is endNode,stop the loop
      findPath = true;
      break;
    }
    ///< push neighbor node of current-node in _openlist
    addNeighborToOpen();
    ///< closeList add, openlist.erase(cur_node)
    _curr_node->set_state(NodeState::kClose);
    _openlist.erase(_openlist.begin());
    ///< using the lambda function instead of compare function
    std::sort(_openlist.begin(), _openlist.end(), [](Node* n1, Node* n2) {
      return n1->get_total_cost() < n2->get_total_cost();
    });
  }
  return findPath;
}

void Process::printPath(Node* node) {
  if (node->get_parent()) {
    printPath(node->get_parent());
  }
  std::cout << "<" << node->get_index_x() << ","<< node->get_index_y() << "> ";
  std::cout << std::endl;
}

void Process::printMap() {
  for (int i = 0; i < _gridmap.get_row_num(); i++) {
    for (int j = 0; j < _gridmap.get_col_num(); j++) {
      if (_gridmap[i][j].get_type() == NodeType::kNormal) {
        std::cout << " - ";
      } else if (_gridmap[i][j].get_type() == NodeType::kObstacle) {
        std::cout << " X ";
      } else if (_gridmap[i][j].get_type() == NodeType::kStart) {
        std::cout << " S ";
      } else if (_gridmap[i][j].get_type() == NodeType::kEnd) {
        std::cout << " E ";
      }
    }
    std::cout << std::endl;
  }
}

/**
 * @brief   According to the node object release rules I designed, 
 *          there is no need to release the node pointed to by the _cur_node/_start_node/_end_node pointer.
 */ 
void Process::destoryProcess() {
  _start_node = nullptr;
  _end_node = nullptr;
  _curr_node = nullptr;
}

}  // namespace astar



