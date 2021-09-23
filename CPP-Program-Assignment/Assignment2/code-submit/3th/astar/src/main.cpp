/**
 * @file main.cpp
 * @brief The entry of this project.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "astar.h"
#include "display.h"
#include "gridmap.h"
#include "point.h"
using namespace model;

int main() {
  Display *display = new Display();
  GridMap *gridmap = new GridMap();
  AStar *star = new AStar();

  display->parseMapFile();
  display->printInitMap();
  gridmap->createGridMap(*display);
  Point *point = star->findWay(gridmap->get_start_point(0, 0),
                               gridmap->get_end_point(3, 7),
                               gridmap->get_map_(), *display);
  gridmap->printResultMap(point, *display);

  delete display;
  delete gridmap;
  delete star;
}
