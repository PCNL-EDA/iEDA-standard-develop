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

namespace data {

void GridMap::createGridMap(resource::Display &display) {
  for (int row = 0; row < display.get_max_row_(); ++row) {
    vector<Point *> tmp;
    for (int column = 0; column < display.get_max_colunm_(); ++column) {
      Point *point = new Point();
      point->x_ = row;
      point->y_ = column;
      if (display.get_mapdata_()[row][column] == '0') {
        point->type_ = Type::TYPE_BARRIER;
      }
      tmp.push_back(point);
    }
    map_.push_back(tmp);
  }
#ifndef _GTEST
  printf("\e[0;32m[SUCCESS]\033[0m gridmap->createGridMap(): Initialize the "
         "coordinates, type_, cost and parent_ pointer of each node. \n");
#endif
}

void GridMap::printResultMap(Point *resultpoint, resource::Display &display) {
  while (resultpoint) {
    resultpoint->type_ = Type::TYPE_PATH;
    resultpoint = resultpoint->parent_;
  }
  printf("\e[0;32m[SUCCESS]\033[0m gridmap->printResultmap(): Print the "
         "result map.\n");
  for (int row = 0; row < display.get_max_row_(); ++row) {
    for (int column = 0; column < display.get_max_colunm_(); ++column) {
      if (map_[row][column]->type_ == Type::TYPE_PATH) {
        printf("\e[1;31m*\t\033[0m");
      } else {
        printf("%c\t", display.get_mapdata_()[row][column]);
      }
    }
    printf("\n");
  }
}

} // namespace data
