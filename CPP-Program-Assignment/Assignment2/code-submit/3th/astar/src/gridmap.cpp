/**
 * @file gridmap.cpp
 * @brief Create features for each point in the gridmap.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "gridmap.h"

namespace model {

void GridMap::createGridMap(Display &display) {
  for (int row = 0; row < display.get_max_row(); ++row) {
    vector<Point *> tmp;
    for (int column = 0; column < display.get_max_colunm(); ++column) {
      Point *point = new Point();
      point->_x = row;
      point->_y = column;
      if (display.get_mapdata()[row][column] == '0') {
        point->_type = Type::TYPE_BARRIER;
      }
      tmp.push_back(point);
    }
    _map.push_back(tmp);
  }
#ifndef _GTEST
  printf("\e[0;32m[SUCCESS]\033[0m gridmap->createGridMap(): Initialize the "
         "coordinates, _type, cost and _parent pointer of each node. \n");
#endif
}

void GridMap::printResultMap(Point *resultpoint, Display &display) {
  while (resultpoint) {
    resultpoint->_type = Type::TYPE_PATH;
    resultpoint = resultpoint->_parent;
  }
  printf("\e[0;32m[SUCCESS]\033[0m gridmap->printResultmap(): Print the "
         "result map.\n");
  for (int row = 0; row < display.get_max_row(); ++row) {
    for (int column = 0; column < display.get_max_colunm(); ++column) {
      if (_map[row][column]->_type == Type::TYPE_PATH) {
        printf("\e[1;31m*\t\033[0m");
      } else {
        printf("%c\t", display.get_mapdata()[row][column]);
      }
    }
    printf("\n");
  }
}

} // namespace model
