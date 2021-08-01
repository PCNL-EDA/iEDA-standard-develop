/*
 * @Author: YangZongLin
 * @Date: 2021-07-31
 * @Description: Definition of member function of class model
 * @FilePath: /Topic3/src/Model.cpp
 * @copyright:
 */
#include "../include/project/Model.hpp"

namespace astar {
std::list<Point>& Model::findBestWay() {
  initOpenList();
  initCloseList();
  addNodeToOPenList(*_start_point);
  while (_open_list.empty() != 1) {
    setCurrentPoint(*_open_list.begin());
    if (_curr_point == *_end_point)
      return getCloseList();
    else
      continueFindWay();
  }
  _close_list.clear();
  return getCloseList();
}

bool Model::showTheWay() {
  findBestWay();
  if (_close_list.empty() == true) {
    std::cout << "There is no way to the end！！！" << std::endl;
    return false;
  }
  for (std::list<Point>::iterator it = _close_list.begin();
       it != _close_list.end(); it++) {
    std::cout << "(" << (*it).get_x() << "," << (*it).get_y() << ") -> ";
  }
  std::cout << "(" << (*_end_point).get_x() << "," << (*_end_point).get_y()
            << ")" << std::endl;
  return true;
}

void Model::visitNeighbor() {
  int curr_x = getCurrPoint().get_x();
  int curr_y = getCurrPoint().get_y();
  int x_rang_min = curr_x - 1 > 0 ? curr_x - 1 : 0;
  int x_rang_max =
      curr_x + 1 < getRowsNum() - 1 ? curr_x + 1 : getRowsNum() - 1;
  int y_rang_min = curr_y - 1 > 0 ? curr_y - 1 : 0;
  int y_rang_max =
      curr_y + 1 < getColumnsNum() - 1 ? curr_y + 1 : getColumnsNum() - 1;
  for (int i = x_rang_min; i <= x_rang_max; i++) {
    for (int j = y_rang_min; j <= y_rang_max; j++)
      if (canAddIntoOpenList(i, j) == true && (curr_x != i || curr_y != j)) {
        setCostForPoint(_a_map.getPoint(i, j));
        addNodeToOPenList(_a_map.getPoint(i, j));
      }
  }
}
}  // namespace astar
