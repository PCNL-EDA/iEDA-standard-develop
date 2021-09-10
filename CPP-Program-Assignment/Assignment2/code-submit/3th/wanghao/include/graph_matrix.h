/**
 * @file          graph_matrix.h
 * @brief         Class GraphMatrix provides Eulerian Path algorithm
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef GRAPH_MATRIX_H_
#define GRAPH_MATRIX_H_
#include <cstdio>
#include <cstring>

// dimension manipulation, eg: int* -> int**
#define edge(i, j) _data[i * _size_weight + j]

namespace Assignment2 {
/**
 * @brief
 *
 * Class GraphMatrix stores graph matrix
 * and provides Eulerian Path algorithm
 *
 */
class MapMatrix {
 public:
  MapMatrix()             = default;
  MapMatrix(MapMatrix &)  = delete;
  MapMatrix(MapMatrix &&) = delete;
  ~MapMatrix()            = default;
  void operator=(const MapMatrix &) = delete;

  // get
  inline int get_graph_size() const { return _size_weight * _size_height; };

  // set
  void import_data_from_file(const char *);

  // regular functions
  void printAll() const;
  void resetGraphSpace(int, int);

 private:
  // get
  inline int &get_edge(int i, int j) { return _data[i * _size_weight + j]; };

  int *_data;
  int  _size_weight;
  int  _size_height;
};

}  // namespace Assignment2
#endif