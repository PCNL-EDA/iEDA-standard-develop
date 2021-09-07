/**
 * @file          graph_matrix.h
 * @brief         Class GraphMatrix provides Eulerian Path algorithm
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef EULER_H_
#define EULER_H_
#include <cstdio>
#include <cstring>

class GraphMatrix {
 public:
  GraphMatrix() = default;
  ~GraphMatrix();
  void operator=(const GraphMatrix &) = delete;

  inline unsigned  get_graph_size() const;
  inline unsigned &graph_edge(unsigned, unsigned) const;
  inline bool      isEulerianPathExist() const;

  void printAll() const;
  bool isConnectedGraph() const;
  bool isDegreeInEqualsOut() const;
  bool eulerianPath(unsigned *, unsigned *) const;

  void read_file(FILE *);
  void resetGraphSpace(unsigned);

  GraphMatrix(GraphMatrix &)  = delete;
  GraphMatrix(GraphMatrix &&) = delete;

 private:
  void dfs_visit(unsigned, unsigned *) const;
  void dfs_order(unsigned, unsigned *, unsigned *, unsigned *) const;

  unsigned *_graph_matrix;
  unsigned  _size;
};

// inline function:

/**
 * @brief get graph matrix size obviously
 * @return unsigned
 */
unsigned GraphMatrix::get_graph_size() const { return _size; }

/**
 * @brief get graph edge
 * @param i
 * @param j
 * @return unsigned&
 */
unsigned &GraphMatrix::graph_edge(unsigned i, unsigned j) const { return _graph_matrix[i * _size + j]; }

/**
 * @brief check the existance of Eulerian Path
 * @return true - if graph is connected and in/out degrees of each vertex are equal
 * @return false - if not
 */
bool GraphMatrix::isEulerianPathExist() const {
  if (isConnectedGraph() && isDegreeInEqualsOut()) {
    return true;
  }
  return false;
}

#endif