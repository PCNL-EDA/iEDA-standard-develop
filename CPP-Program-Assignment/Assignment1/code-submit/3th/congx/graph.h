/**
 * @file graph.h
 * @author congx
 * @brief This is a graph implemented with an adjacency matrix.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_GRAPH_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_GRAPH_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief This is a class that stores graph information with an adjacency
 * matrix.
 *
 * @tparam T The type of vertex information stored in the graph
 */
template <typename T>
class MatrixGraph {
 public:
  /**
   * @brief Construct a new Matrix Graph object
   *
   */
  MatrixGraph()
      : _vertexs(std::make_shared<std::vector<T>>()),
        _edges(std::make_shared<std::vector<std::vector<bool>>>()) {}

  /**
   * @brief Construct a new Matrix Graph object
   *
   * @param vertexs_file The file path to save vertexs information
   * @param edges_file The file path to save edges information
   */
  MatrixGraph(const std::string& vertexs_file, const std::string& edges_file);

  ~MatrixGraph() = default;

  /**
   * @brief Determine the connectivity of the graph
   *
   * @return true or false
   */
  bool isConnectedGraph() const;

  /**
   * @brief Determine if it's a Euler path
   *
   * @param begin_vertex_index_ptr A pointer that point to a return vertex index
   * @return int 0:it is't euler path, 1:it is euler graph 2:it is euler path
   */
  int isEulerPath(int* begin_vertex_index_ptr) const;

  /**
   * @brief Prints the euler path or euler graph found
   *
   * @param begin_vertex_index The starting point index of the Euler diagram
   * printed
   * @return std::vector<T> The sequence of vertices to the eulerian graph
   * searched
   */
  std::vector<T> printEulerPath(int begin_vertex_index);

  /**
   * @brief Prints the structure information of the saved graph
   *
   */
  void print() const;

 private:
  void dfs(int vertex_index, std::vector<bool>* visited_ptr) const;
  void dfs(int vertex_index, std::vector<T>* euler_path_ptr);

 private:
  std::shared_ptr<std::vector<T>> _vertexs;
  std::shared_ptr<std::vector<std::vector<bool>>> _edges;
  int _vertex_num = 0;
};

// constructor function  according the file name
template <typename T>
MatrixGraph<T>::MatrixGraph(const std::string& vertexs_file,
                            const std::string& edges_file)
    : MatrixGraph() {
  // initial the _vertexs set
  std::ifstream input_vertexs(vertexs_file);
  std::istream_iterator<T> iter_vertexs(input_vertexs);
  std::istream_iterator<T> eof_vertexs;
  while (iter_vertexs != eof_vertexs) {
    _vertexs->push_back(*iter_vertexs++);
  }
  input_vertexs.close();

  // set the number of element of vertex set
  _vertex_num = _vertexs->size();

  // initial the _edges set
  std::ifstream input_edges(edges_file);
  std::istream_iterator<bool> iter_edges(input_edges);
  std::istream_iterator<bool> eof_edges;
  int element_index = 0;
  while (iter_edges != eof_edges) {
    if (element_index++ % _vertex_num == 0) {
      _edges->push_back(std::vector<bool>());
    }
    _edges->back().push_back(*iter_edges++);
  }
  input_edges.close();
}

template <typename T>
void MatrixGraph<T>::dfs(int vertex_index,
                         std::vector<bool>* visited_ptr) const {
  (*visited_ptr)[vertex_index] = true;
  // std::cout << "visit vertex " << vertex_index << std::endl;
  for (int index_adjacent = 0; index_adjacent < _vertex_num; index_adjacent++) {
    if ((*_edges)[vertex_index][index_adjacent] == true &&
        (*visited_ptr)[index_adjacent] == false) {
      dfs(index_adjacent, visited_ptr);
    }
  }
  // std::cout << "arrive vertex " << vertex_index << " again" << std::endl;
}

template <typename T>
void MatrixGraph<T>::dfs(int vertex_index, std::vector<T>* euler_path_ptr) {
  assert(0 <= vertex_index && vertex_index <= _vertex_num);

  for (int adjacent_index = 0; adjacent_index < _vertex_num; adjacent_index++) {
    if ((*_edges)[vertex_index][adjacent_index] == true) {
      (*_edges)[vertex_index][adjacent_index] = false;
      dfs(adjacent_index, euler_path_ptr);
    }
  }
  euler_path_ptr->push_back((*_vertexs)[vertex_index]);
}

template <typename T>
bool MatrixGraph<T>::isConnectedGraph() const {
  std::vector<bool> visited(_vertex_num, false);
  dfs(0, &visited);
  for (auto iter = visited.begin(); iter != visited.end(); iter++) {
    if ((*iter) == false) {
      return false;
    }
  }
  return true;
}

template <typename T>
int MatrixGraph<T>::isEulerPath(int* begin_vertex_index_ptr) const {
  if (!isConnectedGraph()) return 0;

  std::vector<int> in_degree(_vertex_num, 0);
  std::vector<int> out_degree(_vertex_num, 0);

  for (int row = 0; row < _vertex_num; row++) {
    for (int col = 0; col < _vertex_num; col++) {
      if ((*_edges)[row][col] == true) {
        out_degree[row]++;
        in_degree[col]++;
      }
    }
  }

  int begin_vertex_index = 0;
  int begin_count = 0;
  int end_count = 0;
  for (int vertex_index = 0; vertex_index < _vertex_num; vertex_index++) {
    int degree_difference = out_degree[vertex_index] - in_degree[vertex_index];
    switch (degree_difference) {
      case -1:
        ++end_count;
        break;
      case 1:
        begin_vertex_index = vertex_index;
        ++begin_count;
        break;
      case 0:
        continue;
        break;
      default:
        return 0;
        break;
    }
  }
  *begin_vertex_index_ptr = begin_vertex_index;
  if (begin_count == end_count && (begin_count == 0 || begin_count == 1)) {
    return begin_count == 0 ? 1 : 2;
  } else {
    return 0;
  }
}

template <typename T>
std::vector<T> MatrixGraph<T>::printEulerPath(int begin_vertex_index) {
  std::vector<T> euler_path = {};

  dfs(begin_vertex_index, &euler_path);
  reverse(euler_path.begin(), euler_path.end());
  return euler_path;
}

template <typename T>
void MatrixGraph<T>::print() const {
  for (int i = 0; i < _vertex_num; i++) {
    std::cout << (*_vertexs)[i] << std::endl;
  }
  std::cout << std::endl;

  // can be change
  for (int i = 0; i < _vertex_num; i++) {
    auto relation_group = (*_edges)[i];
    for_each(relation_group.begin(), relation_group.end(),
             [](bool relation) { std::cout << relation << " "; });
    std::cout << std::endl;
  }
}

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_GRAPH_H_
