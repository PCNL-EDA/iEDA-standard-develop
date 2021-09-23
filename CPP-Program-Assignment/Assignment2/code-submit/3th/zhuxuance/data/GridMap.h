/**
 * @file          GridMap.h
 * @brief         The grid map class is composed of grids, which can modify map data and print information.
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_DATA_GRIDMAP_H_
#define _FINDOPTIMALPATH_DATA_GRIDMAP_H_

#include "../utils/MyUtils.h"
#include "Grid.h"

namespace findOptimalPath {

template <typename T>
using GridMapMatrix = std::vector<std::vector<T> >;
using OptimalPath   = std::vector<std::pair<int, int> >;

/**
 * @brief Record the basic information and optimal path of the graph
 */
template <typename T>
class GridMap {
 public:
  // ctor and dtor
  GridMap() = default;
  GridMap(const GridMap &other_grid_map) = delete;
  GridMap(GridMap &)  = delete;
  GridMap(GridMap &&) = delete;
  ~GridMap() = default;

  // operators overloading
  GridMap &operator=(GridMap &)  = delete;
  GridMap &operator=(GridMap &&) = delete;
  std::vector<T> &operator[](const size_t i) { return _grid_map_matrix[i]; }

  // setter
  void set_start_grid(int x, int y) {
    _start_grid.first  = x;
    _start_grid.second = y;
  }
  void set_end_grid(int x, int y) {
    _end_grid.first  = x;
    _end_grid.second = y;
  }
  void set_have_optimal_path(bool have_optimal_path) { _have_optimal_path = have_optimal_path; }

  // getter
  Coordinate get_start_grid() const  { return _start_grid; }
  Coordinate get_end_grid() const    { return _end_grid; }
  size_t get_grid_map_length() const { return _grid_map_length; }
  size_t get_grid_map_width() const  { return _grid_map_width; }
  bool get_have_optimal_path() const { return _have_optimal_path; }

  // function
  void initGridMap(const std::string &map_file_path);
  void updateStartGrid(int x, int y);
  void updateEndGrid(int x, int y);
  void insertToOptimalPath(Coordinate grid_coordinate);
  void printGridMap();
  void printOptimalPath();


 private:
  const std::vector<std::string> _building_material = {"▢", "▣", "★", "✢", "⊡"};
  size_t _grid_map_length = 0;
  size_t _grid_map_width  = 0;
  GridMapMatrix<T> _grid_map_matrix;
  Coordinate  _start_grid = std::make_pair(-1, -1);
  Coordinate  _end_grid   = std::make_pair(-1, -1);
  OptimalPath _optimal_path;
  bool    _have_optimal_path = false;
  MyUtils util;
};

/**
 * @brief Initialize the object with the grid map file path
 * @param map_file_path 
 */
template <typename T>
void GridMap<T>::initGridMap(const std::string &map_file_path) {
  std::vector<std::string> map_file_content = util.readFileContent(map_file_path);

  _grid_map_width = stoi(map_file_content[0]);
  _grid_map_length = stoi(map_file_content[1]);

  std::vector<T> insert_vec;

  for (int i = 0; i < _grid_map_width; ++i) {
    insert_vec.clear();
    for (int j = 0; j < _grid_map_length; ++j) {
      Grid grid(i, j);
      switch (stoi(map_file_content[i * _grid_map_length + 2 + j])) {
        case 0:
          grid.set_type(GridType::kPassable);
          break;
        case 1:
          grid.set_type(GridType::kObstacle);
          break;
        case 2:
          set_start_grid(i, j);
          grid.set_type(GridType::kStart);
          break;
        case 3:
          set_end_grid(i, j);
          grid.set_type(GridType::kEnd);
          break;

        default:
          break;
      }
      insert_vec.push_back(grid);
    }
    _grid_map_matrix.push_back(insert_vec);
  }
}

/**
 * @brief Modify the start grid of the grid map
 * @param x 
 * @param y 
 */
template <typename T>
inline void GridMap<T>::updateStartGrid(int x, int y) {
  // if already have a start grid. replace.
  if (_start_grid.first != -1) {
    _grid_map_matrix[_start_grid.first][_start_grid.second].set_type(GridType::kPassable);
  }
  _grid_map_matrix[x][y].set_type(GridType::kStart);
  _start_grid.first = x;
  _start_grid.second = y;
}

/**
 * @brief Modify the end grid of the grid map
 * @param x 
 * @param y 
 */
template <typename T>
inline void GridMap<T>::updateEndGrid(int x, int y) {
  // if already have a start grid. replace.
  if (_end_grid.first != -1) {
    _grid_map_matrix[_end_grid.first][_end_grid.second].set_type(GridType::kPassable);
  }
  _grid_map_matrix[x][y].set_type(GridType::kEnd);
  _end_grid.first = x;
  _end_grid.second = y;
}

/**
 * @brief Add grid coordinate to the vector of the optimal path
 * @param grid_coordinate 
 */
template <typename T>
void GridMap<T>::insertToOptimalPath(Coordinate grid_coordinate) {
  _optimal_path.push_back(grid_coordinate);
}

/**
 * @brief print grid map
 */
template <typename T>
void GridMap<T>::printGridMap() {
  printf("\n>>> print Grid Map <<<\n");
  printf("start: (%d, %d)\nend:   (%d, %d)\n", _start_grid.first, _start_grid.second, _end_grid.first,
         _end_grid.second);

  for (int i = 0; i < _grid_map_matrix.size(); ++i) {
    for (int j = 0; j < _grid_map_matrix[i].size(); ++j) {
      if (_grid_map_matrix[i][j].isStart() || _grid_map_matrix[i][j].isEnd()) {
        printf("\x1b[1;36m");
        printf("%s ", _building_material[static_cast<int>(_grid_map_matrix[i][j].get_type())].c_str());
        printf("\x1b[0m");
      } else if (_grid_map_matrix[i][j].isOnOptimalPath()) {
        printf("\x1b[1;31m");
        printf("%s ", _building_material[4].c_str());
        printf("\x1b[0m");
      } else {
        printf("%s ", _building_material[static_cast<int>(_grid_map_matrix[i][j].get_type())].c_str());
      }
    }
    printf("\n");
  }
}

/**
 * @brief print optimal path
 */
template <typename T>
void GridMap<T>::printOptimalPath() {
  if (!_have_optimal_path) {
    printf("\nsorry > <, no path from (%d, %d) -> (%d, %d)\n\n", _start_grid.first, _start_grid.second, _end_grid.first,
           _end_grid.second);
    return;
  }

  printf("\n>>> print optimal path <<<\n");
  for (int i = 0; i < _optimal_path.size() - 1; ++i) {
    printf("(%d, %d) -> ", _optimal_path[i].first, _optimal_path[i].second);
  }
  printf("(%d, %d)\n", _optimal_path[_optimal_path.size() - 1].first, _optimal_path[_optimal_path.size() - 1].second);
}

}  // namespace findOptimalPath

#endif