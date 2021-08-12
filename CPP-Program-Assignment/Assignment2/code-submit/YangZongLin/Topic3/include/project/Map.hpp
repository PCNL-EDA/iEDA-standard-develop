/*
 * @Author: YangZongLin
 * @Date: 2021-07-30
 * @Description: Abstraction of a graph
 * @FilePath: /Topic3/include/project/Map.hpp
 * @copyright:
 */

#ifndef PROJECT_MAP_HPP_
#define PROJECT_MAP_HPP_

#include <vector>

#include "Point.hpp"

namespace astar {
/**
 * @class Map
 * @brief This class is an abstraction of the Grid diagram
 */
class Map {
 public:
  Map() = default;
  explicit Map(int same) { initMap(same, same); }
  Map(int rows, int columns) { initMap(rows, columns); }
  explicit Map(const int** p) {
    int columns = sizeof(**p) / sizeof(int);
    int rows = sizeof(*p) / sizeof(**p);
    initMap(rows, columns);
  }
  ~Map() = default;

  void initMap(const int& rows, const int& columns) {
    _map.resize(rows);
    for (int i = 0; i < rows; i++) {
      _map[i].resize(columns);
      for (int j = 0; j < columns; j++) {
        _map[i][j].set_x(i);
        _map[i][j].set_y(j);
      }
    }
  }
  Point& getPoint(const int& row, const int& colums) {
    return _map[row][colums];
  }
  int getColumnsRang() { return _map[0].size(); }
  int getRowsRang() { return _map.size(); }

 private:
  std::vector<std::vector<Point>> _map; /**< The graph composed of points is
                                           represented by nested templates */
};
}  // namespace astar

#endif  // PROJECT_MAP_HPP_
