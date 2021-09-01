/**
 * @file Map.h
 * @author lvyaxing
 * @brief 
 * @version 0.1
 * @date 2021-07-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _INCLUDE_MAP_H_
#define _INCLUDE_MAP_H_
#include"Coordinate.h"
#include <vector>
namespace MyAStar {
    /**
     * @brief Coordinates of obstacle points
     * @class Map
     */
    class Map 
    {
        public:
        Map(int x,int y):_x_size(x),_y_size(y){}
        ~Map(){}
        std::vector<std::vector<int>> getMap(std::vector<Coordinate>obstaclenode);
        private:
        std::vector<Coordinate>_obstacle_node_list;
        int _x_size;
        int _y_size;
    };
}// namespace MyAStar
#endif  // _INCLUDE_MAP_H_
