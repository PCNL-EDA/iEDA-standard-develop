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
#include "../include/Process.h"    ///< ???


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
  setNode({index_x, index_y}, NodeType::kStart);
}

void Process::setEndNode(const int index_x, const int index_y) {
  setNode({index_x, index_y}, NodeType::kEnd);
}

void Process::setObstacleNode(const std::vector<std::pair<int, int>>& obstacleList) {
  for (int i = 0; i < obstacleList.size(); i++) {
    setNode(obstacleList[i], NodeType::kObstacle);
  }
}

void Process::printMap() {
  for (int i = 0; i < _gridmap.get_row_num(); i++) {
    for (int j = 0; j < _gridmap.get_col_num(); j++) {
      std::cout << "<" << _gridmap[i][j].get_index_x() << "," << _gridmap[i][j].get_index_y() << "> ";
    }
    std::cout << std::endl;
  } 
}

}  // namespace astar



