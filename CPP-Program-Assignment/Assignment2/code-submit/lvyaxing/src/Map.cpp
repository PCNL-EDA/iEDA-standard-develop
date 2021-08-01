/**
 * @file Map.cpp
 * @author lvyaxing
 * @version 0.1
 * @date 2021-08-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<vector>
#include"../include/Map.h"
namespace MyAStar{
    /**
     * @brief Draw a map using the coordinates of obstacle nodes,1 stands for obstacle, and 0 stands for passing
     * @fn getMap
     * @return std::vector<std::vector<int>> 
     */
    std::vector<std::vector<int>> Map::getMap(std::vector<Coordinate>obstacle)
    {
        std::vector<std::vector<int>>map(_x_size,std::vector<int>(_y_size,0));
        if(!obstacle.empty())
        {
            for(int k=1;k<=obstacle.size();k++)
            {
                map[obstacle[k-1].get_y()][obstacle[k-1].get_x()]=1;
            }
            return map;
        }
    }
}//namespace MyAStar
