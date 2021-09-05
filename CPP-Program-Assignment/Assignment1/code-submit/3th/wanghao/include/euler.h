/**
 * @file          euler.h
 * @brief         Class Euler provides Eulerian Path algorithm
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef EULER_H_
#define EULER_H_
#include <cstdio>

class Euler {
 public:
  Euler() = default;
  ~Euler();
  void operator=(const Euler &) = delete;

  void      printAll() const;
  unsigned  get_graph_size() const;
  unsigned &graph_edge(unsigned, unsigned) const;

  void read_file(FILE *);
  bool eulerianPath(unsigned *);
  void resetGraphSpace(unsigned);

 private:
  unsigned *_graph_matrix;
  unsigned  _size;
};

#endif