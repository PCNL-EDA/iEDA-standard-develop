/**
 * @file          euler.cpp
 * @brief         implementation of Class Euler
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <euler.h>

/**
 * @brief delete old data space and then creat a new space of a given size
 * @param size
 */
void Euler::resetGraphSpace(unsigned size) {
  if (_graph_matrix != nullptr) {
    delete[] _graph_matrix;
  }
  _size         = size;
  _graph_matrix = new unsigned[size * size];
}

/**
 * @brief read graph matrix data from file fp
 * @param fp
 */
void Euler::read_file(FILE *fp) {
  unsigned size;
  fscanf(fp, "%u\n", &size);
  this->resetGraphSpace(size);

  size *= size;
  for (size_t i = 0; i < size; ++i) {
    fscanf(fp, " %u ", &_graph_matrix[i]);
  }
}

/**
 * @brief Destroy the Euler:: Euler object
 */
Euler::~Euler() {
  if (_graph_matrix != nullptr) {
    delete[] _graph_matrix;
  }
}

/**
 * @brief get graph matrix size obviously
 * @return unsigned
 */
unsigned Euler::get_graph_size() const { return _size; }

/**
 * @brief get graph edge
 * @param i
 * @param j
 * @return unsigned&
 */
unsigned &Euler::graph_edge(unsigned i, unsigned j) const { return _graph_matrix[i * _size + j]; }

/**
 * @brief print graph matirx
 */
void Euler::printAll() const {
  printf(">>> print graph matrix for Euler Algorithm\n");
  for (size_t i = 0; i < _size; ++i) {
    for (size_t j = 0; j < _size; ++j) {
      printf("%u ", graph_edge(i, j));
    }
    printf("\n");
  }
}

/**
 * @brief caculate the Eulerian Path of graph matrix,
 * @param result
 * @return true - if Eulerian Path exists
 * @return false - if Eulerian Path not exists
 */
bool Euler::eulerianPath(unsigned *result) {
  for (size_t i = 0; i < _size; ++i) {
    result[i] = i;
  }
  return 1;
}