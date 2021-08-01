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

void Process::inviteNeighborByCur(std::vector<Node*>& neighborList) {
  int x = _curr_node->get_index_x();
  int y = _curr_node->get_index_y();
  std::vector<std::pair<int, int>> offsetList = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                                                  {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  for (int i = 0; i < offsetList.size(); i++) {
    int neigh_x = x + offsetList[i].first;
    int neigh_y = y + offsetList[i].second;
    if (isLegalNeighbor(neigh_x, neigh_y)) {
      neighborList.push_back(&_gridmap[neigh_x][neigh_y]);
    }
  }
}

void Process::updateNeighbor(Node* node) {    // no use now
  node->set_parent(_curr_node);
}

void Process::addNeighborToOpen() {
  std::vector<Node*> neighborList;
  inviteNeighborByCur(neighborList);
  for (Node* neighbor : neighborList) {
    ///< the neighbor node is obstacle or included in closelist
    if (isInCloseList(neighbor) || isObsNode(neighbor)) {
      continue;
    }


    if (!isInOpenlist(neighbor)) {
      neighbor->set_cost_start(_curr_node->get_start_cost() + 1);   //update cost from start to current
      double costToEnd = std::abs(_end_node->get_index_x() - neighbor->get_index_x()) +
                          std::abs(_end_node->get_index_y() - neighbor->get_index_y());
      neighbor->set_cost_end(costToEnd);
      double totalCost = neighbor->get_start_cost() + neighbor->get_end_cost();
      neighbor->set_total_cost(totalCost);
      neighbor->set_parent(_curr_node);

      _openlist.push_back(neighbor);
    }

  }
}

bool compare(Node* n1, Node* n2) { return n1->get_total_cost() < n2->get_total_cost(); }

bool Process::findPath() {
  _openlist.push_back(_start_node);
  bool findPath = false;
  while (!_openlist.empty()) {
    _curr_node = _openlist[0];
    if (isEndNode(_curr_node)) {  ///< if the cur_node is endNode,stop the loop
      findPath = true;
      break;
    }

    addNeighborToOpen();

    ///< closeList add, openlist.erase(cur_node)
    _curr_node->set_state(NodeState::kClose);
    _openlist.erase(_openlist.begin());

    std::sort(_openlist.begin(), _openlist.end(), astar::compare);  ///<
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

void Process::destoryProcess() {
  _start_node = nullptr;
  _end_node = nullptr;
  _curr_node = nullptr;
}

}  // namespace astar



