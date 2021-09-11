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

#define EULER_GRAPH 1
#define EULER_PATH 2
#define NOT_EULER_PATH 0

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
  MatrixGraph() = default;
  MatrixGraph(const MatrixGraph& graph) = default;
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
  std::vector<T> getEulerPath(int begin_vertex_index);

  void addVertex(T vertex) {
    _vertexs.push_back(vertex);
    _vertex_num = _vertexs.size();
  }
  void addEdge(bool edge);

 private:
  void isConnectedGraph_aux(int vertex_index,
                            std::vector<bool>* visited_ptr) const;
  void getEulerPath_aux(int vertex_index, std::vector<T>* euler_path_ptr);

 private:
  std::vector<T> _vertexs;
  std::vector<std::vector<bool>> _edges;
  int _vertex_num = 0;
};

template <typename T>
void MatrixGraph<T>::addEdge(bool edge) {
  if (_edges.empty() || _edges.back().size() == _vertex_num) {
    _edges.push_back(std::vector<bool>());
  }
  _edges.back().push_back(edge);
}

template <typename T>
void MatrixGraph<T>::isConnectedGraph_aux(
    int vertex_index, std::vector<bool>* visited_ptr) const {
  (*visited_ptr)[vertex_index] = true;
  // std::cout << "visit vertex " << vertex_index << std::endl;
  for (int adjacent_index = 0; adjacent_index < _vertex_num; adjacent_index++) {
    if (_edges[vertex_index][adjacent_index] == true &&
        (*visited_ptr)[adjacent_index] == false) {
      isConnectedGraph_aux(adjacent_index, visited_ptr);
    }
  }
  // std::cout << "arrive vertex " << vertex_index << " again" << std::endl;
}

template <typename T>
void MatrixGraph<T>::getEulerPath_aux(int vertex_index,
                                      std::vector<T>* euler_path_ptr) {
  assert(0 <= vertex_index && vertex_index <= _vertex_num);

  for (int adjacent_index = 0; adjacent_index < _vertex_num; adjacent_index++) {
    if (_edges[vertex_index][adjacent_index] == true) {
      _edges[vertex_index][adjacent_index] = false;
      getEulerPath_aux(adjacent_index, euler_path_ptr);
    }
  }
  euler_path_ptr->push_back(_vertexs[vertex_index]);
}

template <typename T>
bool MatrixGraph<T>::isConnectedGraph() const {
  for (int vertex_index = 0; vertex_index < _vertex_num; ++vertex_index) {
    std::vector<bool> visited(_vertex_num, false);
    isConnectedGraph_aux(vertex_index, &visited);
    for (auto iter = visited.begin(); iter != visited.end(); iter++) {
      if ((*iter) == false) {
        break;
      }
    }
    return true;
  }
  return false;
}

template <typename T>
int MatrixGraph<T>::isEulerPath(int* begin_vertex_index_ptr) const {
  // First judge the connectivity of the graph
  // The graph is not a Euler path, if the graph is not connected
  if (!isConnectedGraph()) return NOT_EULER_PATH;

  // get the difference between the out-degree and in-degrees of each node
  std::vector<int> degree_difference(_vertex_num, 0);
  for (int row = 0; row < _vertex_num; row++) {
    for (int col = 0; col < _vertex_num; col++) {
      if (_edges[row][col] == true) {
        degree_difference[row]++;
        degree_difference[col]--;
      }
    }
  }

  // Gets the starting vertex of the Euler path
  // Maintain a counter that inhe start node by 2 and decreases the count for
  // the end node by 1. If the difference between out-degree and in-degree is 0,
  // it will not change.
  int begin_vertex_index = 0;
  int count = 0;
  for (int vertex_idx = 0; vertex_idx < _vertex_num; ++vertex_idx) {
    if (degree_difference[vertex_idx] == 1) {
      count += 2;
      begin_vertex_index = vertex_idx;
    } else if (degree_difference[vertex_idx] == -1) {
      --count;
    } else if (degree_difference[vertex_idx] != 0) {
      return NOT_EULER_PATH;
    }
  }

  // Sets the index of the starting vertex
  *begin_vertex_index_ptr = begin_vertex_index;
  if (count != 0 && count != 1) {
    return NOT_EULER_PATH;
  }
  return count == 0 ? EULER_GRAPH : EULER_PATH;
}

template <typename T>
std::vector<T> MatrixGraph<T>::getEulerPath(int begin_vertex_index) {
  std::vector<T> euler_path = {};

  getEulerPath_aux(begin_vertex_index, &euler_path);
  reverse(euler_path.begin(), euler_path.end());
  return euler_path;
}

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_3TH_CONGX_GRAPH_H_
