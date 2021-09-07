/**
 * @file          graph_matrix.cpp
 * @brief         implementation of Class GraphMatrix
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <graph_matrix.h>

namespace Assignment1{
/**
 * @brief delete old data space and then creat a new space of a given size
 * @param size
 */
void GraphMatrix::resetGraphSpace(unsigned size) {
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
void GraphMatrix::read_file(FILE *fp) {
  unsigned size;
  int      discard;
  discard = fscanf(fp, "%u\n", &size);
  this->resetGraphSpace(size);

  size *= size;
  for (size_t i = 0; i < size; ++i) {
    discard = fscanf(fp, " %u ", &_graph_matrix[i]);
  }
}

/**
 * @brief print graph matirx
 */
void GraphMatrix::printAll() const {
  printf(">>> print graph matrix for GraphMatrix Algorithm\n");
  for (size_t i = 0; i < _size; ++i) {
    for (size_t j = 0; j < _size; ++j) {
      printf("%u ", graph_edge(i, j));
    }
    printf("\n");
  }
  putchar('\n');
}

/**
 * @brief caculate the Eulerian Path of graph matrix,
 * @param result
 * @return true - if Eulerian Path exists
 * @return false - if Eulerian Path not exists
 */
bool GraphMatrix::eulerianPath(unsigned *result, unsigned *path_length) const {
  if (!isEulerianPathExist()) {
    return false;
  }

  // new visited_edge array to help dfs
  const unsigned graph_size   = _size * _size;
  unsigned *     visited_edge = new unsigned[graph_size];
  memset(visited_edge, 0, graph_size * sizeof(unsigned));

  // call dfs to solve eulerian path problem
  dfs_order(0, result, visited_edge, path_length);
  *path_length -= 1;  // due to ```path_length++``` in dfs, clean up for the tail
  delete[] visited_edge;
  return true;
}

/**
 * @brief check if graph is connected
 * @return true if connected
 * @return false if not
 */
bool GraphMatrix::isConnectedGraph() const {
  bool      connected = 1;
  unsigned *visited   = new unsigned[_size];
  memset(visited, 0, sizeof(unsigned) * _size);
  dfs_visit(0, visited);
  for (size_t i = 0; i < _size; ++i) {
    if (visited[i] == 0) {
      connected = 0;
    }
  }
  delete[] visited;
  return connected;
}

/**
 * @brief check if the in-degree == out-degree ?
 * @return true if in-degree == out-degree
 * @return false if in-degree != out-degree
 */
bool GraphMatrix::isDegreeInEqualsOut() const {
  bool equal  = 1;
  int *degree = new int[_size];
  memset(degree, 0, sizeof(int) * _size);
  for (size_t i = 0; i < _size; ++i) {
    for (size_t j = 0; j < _size; ++j) {
      if (graph_edge(i, j) == 1) {
        ++degree[i];
        --degree[j];
      }
    }
  }
  for (size_t i = 0; i < _size; ++i) {
    if (degree[i] != 0) {
      equal = 0;
    }
  }
  delete[] degree;
  return equal;
}

/**
 * @brief helper for GraphMatrix::isConnectedGraph, return visited array
 * @param node
 * @param visited
 */
void GraphMatrix::dfs_visit(unsigned node, unsigned *visited) const {
  visited[node] = 1;
  for (size_t i = 0; i < _size; ++i) {
    if ((graph_edge(node, i) == 1) && (visited[i] == 0)) {
      dfs_visit(i, visited);
    }
  }
}

/**
 * @brief helper for GraphMatrix::eulerianPath, return visited order and path length
 * @param curr_node
 * @param order
 * @param visited_edge
 * @param path_length
 */
void GraphMatrix::dfs_order(unsigned curr_node, unsigned *order, unsigned *visited_edge, unsigned *path_length) const {
  order[(*path_length)++] = curr_node;
  for (size_t new_node = 0; new_node < _size; ++new_node) {
    // if edge does exit and never be visited, dfs
    if (graph_edge(curr_node, new_node) == 1 && visit(curr_node, new_node) == 0) {
      visit(curr_node, new_node) = 1;
      dfs_order(new_node, order, visited_edge, path_length);
    }
  }
}

} // namespace Assignment1