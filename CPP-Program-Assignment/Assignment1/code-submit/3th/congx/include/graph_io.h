/**
 * @file graph_io.h
 * @author congx
 * @brief A GraphIO class contain read and print function of Graph.
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#ifndef CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_READER_H_
#define CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_READER_H_

#include "graph.h"

template <typename T>
class GraphIO {
 public:
  GraphIO() = default;
  GraphIO(const GraphIO& reader) = default;
  ~GraphIO() = default;

  void read(MatrixGraph<T>& graph, const std::string& vertexs_file,
            const std::string& edges_file);
  void print(const std::vector<T>& euler_path) const;
};

template <typename T>
void GraphIO<T>::print(const std::vector<T>& euler_path) const {
  for (auto iter = euler_path.begin(); iter != euler_path.end(); iter++) {
    std::cout << (*iter).get_name();
    std::cout << (iter + 1 != euler_path.end() ? " -> " : "\n");
  }
}

template <typename T>
void GraphIO<T>::read(MatrixGraph<T>& graph, const std::string& vertexs_file,
                   const std::string& edges_file) {
  // initial the _vertexs set
  std::ifstream input_vertexs(vertexs_file);
  std::istream_iterator<T> iter_vertexs(input_vertexs);
  std::istream_iterator<T> eof_vertexs;
  while (iter_vertexs != eof_vertexs) {
    graph.addVertex(*iter_vertexs++);
  }
  input_vertexs.close();

  // initial the _edges set
  std::ifstream input_edges(edges_file);
  std::istream_iterator<bool> iter_edges(input_edges);
  std::istream_iterator<bool> eof_edges;
  int element_index = 0;
  while (iter_edges != eof_edges) {
    graph.addEdge(*iter_edges++);
  }
  input_edges.close();
}

#endif  // CPP_PROGRAM_ASSIGNMENT_ASSIGNMENT1_CODE_SUBMIT_CONGX_READER_H_
