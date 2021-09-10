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

// dimension manipulation, eg: unsigned* -> unsigned**
#define visit(i, j) visited_edge[i * _size + j]  

namespace Assignment1{
/**
 * @brief
 *
 * Class GraphMatrix stores graph matrix
 * and provides Eulerian Path algorithm
 *
 */
class GraphMatrix {
 public:
  GraphMatrix()               = default;
  GraphMatrix(GraphMatrix &)  = delete;
  GraphMatrix(GraphMatrix &&) = delete;
  ~GraphMatrix() {
    delete[] _graph_matrix;
  }
  void operator=(const GraphMatrix &) = delete;

  // get
  inline unsigned get_graph_size() const { 
    return _size; 
  }

  inline unsigned &graph_edge(unsigned i, unsigned j) const { 
    return _graph_matrix[i * _size + j]; 
  }

  // set
  void read_file(FILE *);

  void printAll() const;
  bool isConnectedGraph() const;
  bool isDegreeInEqualsOut() const;
  bool eulerianPath(unsigned *, unsigned *) const;
  void resetGraphSpace(unsigned);

  inline bool isEulerianPathExist() const {
    return (isConnectedGraph() && isDegreeInEqualsOut()) ? true : false;
  }

 private:
  void dfsByNode(unsigned, unsigned *) const;
  void dfsOrder(unsigned, unsigned *, unsigned *, unsigned *) const;

  unsigned *_graph_matrix;
  unsigned  _size;
};

} // namespace Assignment1
#endif