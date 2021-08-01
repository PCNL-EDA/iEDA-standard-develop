/**
 * @file        main.cpp
 * @brief       
 * @author      liujikang
 * @date        2021/07/30
 * @copyright   liujikang
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "../include/Process.h"
#include  <utility>


int main() {
  astar::Process astar_proc;
  astar_proc.setMapSize(4, 8);
  astar_proc.setStartnode(0, 0);
  astar_proc.setEndNode(3, 7);
  astar_proc.setObstacleNode({ {0, 4}, {0, 5}, {0, 6}, {0, 7},
                               {1, 5}, {1, 6}, {1, 7}, {2, 0},
                               {2, 1}, {2, 3}, {2, 4}, {3, 0} });

  astar_proc.printMap();
  //astar_proc.findPath();
  //astar_proc.printPath();
    

  return 0;
}
