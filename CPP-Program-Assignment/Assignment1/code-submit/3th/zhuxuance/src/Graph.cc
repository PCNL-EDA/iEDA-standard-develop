/**
 * @file          Graph.cc
 * @brief         Implementation of class Graph
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "Graph.h"

namespace Euler {
/**
 * @brief Destroy the Graph:: Graph object
 */
Graph::~Graph() {
  if (_degree != nullptr) {
    delete[] _degree;
  }
  if (_visited != nullptr) {
    delete[] _visited;
  }
}

/**
 * @brief Read the information of the graph from the file and initialize it
 * @param argc
 * @param argv
 */
void Graph::setGraph(int argc, const char **argv) {
  printf("start to set graph...\n");
  if (argc != 3 && !argv[1] && !argv[2]) {
    printf("invalid parameters\n");
    _util.exitProgram(EXIT_FAILURE);
  }
  std::vector<std::string> file_content;
  file_content = _util.readFileContent(argv[1]);
  printf("got graph file content\n\n");

  _people.setPeopleList(argv[2]);

  setGraphInfo(sqrt(file_content.size()));
  printDegreeAndVisited();
  setAdj(file_content);
  printAdj();
  setEdges(file_content);
  printEdges();
}

/**
 * @brief Initialize the node and degree information of the graph
 * @param node_count
 */
void Graph::setGraphInfo(int node_count) {
  set_node_count(node_count);
  set_visited(node_count);
  set_degree(node_count);
  set_start_node(0);
}

/**
 * @brief Set the adjacency matrix of the graph
 * @param file_content
 */
void Graph::setAdj(const std::vector<std::string> &file_content) {
  std::vector<int> insert_adj_vec;
  for (int i = 0; i < _node_count; ++i) {
    insert_adj_vec.clear();
    for (int j = 0; j < _node_count; ++j) {
      insert_adj_vec.push_back(stoi(file_content[i * _node_count + j]));
    }
    _adj.push_back(insert_adj_vec);
  }
}

/**
 * @brief Set the edges of the graph
 * @param file_content
 */
void Graph::setEdges(const std::vector<std::string> &file_content) {
  std::vector<int> insert_edge_vec;
  for (int i = 0; i < _node_count; ++i) {
    insert_edge_vec.clear();
    for (int j = 0; j < _node_count; ++j) {
      if (stoi(file_content[i * _node_count + j]) != 0) {
        insert_edge_vec.push_back(i);
        insert_edge_vec.push_back(j);
        ++_degree[i];
        --_degree[j];
        _visited[i] = true;
        _visited[j] = true;
        _edges.push_back(insert_edge_vec);
        insert_edge_vec.clear();
      }
    }
  }
  set_edge_count(_edges.size());
  printDegreeAndVisited();
}

/**
 * @brief Determine the type of graph
 */
void Graph::getGraphType() {
  for (int i = 0; i < _node_count; ++i) {
    if (_visited[i] == 0) {
      _graph_type = NON_EULERIAN;
      printf("No Eular Path > <\n");
      _util.exitProgram(EXIT_SUCCESS);
    }
  }
  int odd_degree_node_count = 0;
  for (int i = 0; i < _node_count; ++i) {
    if (_degree[i] == 1) {
      odd_degree_node_count += 2;
      set_start_node(i);
    } else if (_degree[i] == -1) {
      odd_degree_node_count -= 1;
    } else if (_degree != 0) {
      set_graph_type(NON_EULERIAN);
    }
  }
  if (odd_degree_node_count == 0) {
    set_graph_type(EULERIAN);
  } else if (odd_degree_node_count == 1) {
    set_graph_type(SEMI_EULERIAN);
  }
  printGraphType();
}

/**
 * @brief Calculate the Euler circuit or Euler path of the graph
 */
void Graph::getEulerPath() {
  Adjacent adj;
  for (auto &t : _edges) {
    ++adj[t[0]][t[1]];
  }
  _euler_path.clear();
  euler(adj, _start_node);
  reverse(_euler_path.begin(), _euler_path.end());
}

/**
 * @brief Algorithm for calculating Euler path
 * @param adj
 * @param now
 */
void Graph::euler(Adjacent &adj, int now) {
  for (auto &[next, count] : adj[now]) {
    if (count >= 1) {
      --count;
      euler(adj, next);
    }
  }
  _euler_path.push_back(now);
}

/**
 * @brief Print degree and Visited
 */
void Graph::printDegreeAndVisited() {
  printf("--------------print _degree & _visited\n");
  printf("node count: %d\ndegree :  ", _node_count);
  for (int i = 0; i < _node_count; ++i) {
    printf("%d ", _degree[i]);
  }
  printf("\nvisited:  ");
  for (int i = 0; i < _node_count; ++i) {
    printf("%d ", _visited[i]);
  }
  printf("\n\n");
}

/**
 * @brief Print adjacency matrix
 */
void Graph::printAdj() {
  printf("----------------------------print _adj\n");
  for (int i = 0; i < _adj.size(); ++i) {
    for (int j = 0; j < _adj[0].size(); ++j) {
      printf("%d ", _adj[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
 * @brief Print edges
 */
void Graph::printEdges() {
  printf("--------------------------print _edges\n");
  for (int i = 0; i < _edges.size(); ++i) {
    printf("%d -> %d\n", _edges[i][0], _edges[i][1]);
  }
  printf("\n");
}

/**
 * @brief Print graph type
 */
void Graph::printGraphType() {
  printf("---------------------print _graph_type\n");
  printf("_graph_type = %s\n", graph_type_list[_graph_type].c_str());
  printf("_start_node = %d:%s\n", _start_node, _people.getName(_start_node).c_str());
  printf("\n");
}

/**
 * @brief Print euler path
 */
void Graph::printEulerPath() {
  printf("---------------------print _euler_path\n");
  printf("%s: \n", graph_type_list[_graph_type].c_str());

  for (int i = 0; i < _euler_path.size() - 1; ++i) {
    printf("%d:%s -> ", _euler_path[i], _people.getName(_euler_path[i]).c_str());
  }
  printf("%d:%s\n", _euler_path[_euler_path.size() - 1], _people.getName(_euler_path[_euler_path.size() - 1]).c_str());
  printf("\n");
}
}  // namespace Euler