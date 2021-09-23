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
#include "error_code.h"

namespace Assignment2 {

/**
 * @brief
 * Class GraphMatrix stores 2D graph matrix
//  *
//  * @note
//  * class T requires implementation of T &operator[](int);
 */
template <class T>
class GraphMatrix {
 public:
  GraphMatrix()  = default;
  ~GraphMatrix() = default;

  kDELETE_UNUSED_CONSTRUCTOR(GraphMatrix);

  // get
  inline int get_graph_size() const { return _size_weight * _size_height; };
  inline int get_graph_weight() const { return _size_weight; };
  inline int get_graph_height() const { return _size_weight; };

  // set
  void clear_data();
  void resize(int, int);
  void import_data_from_file(const char *);

  // regular functions
  void displayAll() const;

 private:
  // get
  inline int &get_edge(int i, int j) { return _data[i * _size_weight + j]; };

  T * _data;
  int _size_weight;
  int _size_height;
};

}  // namespace Assignment2
#endif