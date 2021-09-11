/**
 * @file          Graph.cc
 * @brief         Implementation of class Graph
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "Graph.h"

namespace Euler {
const std::vector<std::string> Graph::kGraphTypeList = {"No Euler Path", "Euler circuit", "Euler path"};

/**
 * @brief Destroy the Graph:: Graph object
 */
Graph::~Graph() {
  if (_degree_diff != nullptr) {
    delete[] _degree_diff;
  }
  if (_visited != nullptr) {
    delete[] _visited;
  }
}

/**
 * @brief Read the information of the graph from the file and initialize it
 * @param relationship_file_path
 * @param people_file_path
 */
void Graph::initGraph(const std::string &relationship_file_path, const std::string &people_file_path) {
  printf("start to set graph...\n");
  std::vector<std::string> relationship_file_content;
  relationship_file_content = _util.readFileContent(relationship_file_path);
  printf("got graph file content\n\n");

  _people.initPeopleList(people_file_path);

  initGraphBasicInfo(sqrt(relationship_file_content.size()));
  printDegreediffAndVisited();
  setAdj(relationship_file_content);
  printAdj();
  setEdges(relationship_file_content);
  printEdges();
}

/**
 * @brief Initialize the node and degree information of the graph
 * @param node_count
 */
void Graph::initGraphBasicInfo(int node_count) {
  set_node_count(node_count);
  set_visited(node_count);
  set_degree_diff(node_count);
  set_start_node(0);
}

/**
 * @brief Set the adjacency matrix of the graph
 * @param relationship_file_content
 */
void Graph::setAdj(const std::vector<std::string> &relationship_file_content) {
  std::vector<int> insert_adj_vec;
  for (int i = 0; i < _node_count; ++i) {
    insert_adj_vec.clear();
    for (int j = 0; j < _node_count; ++j) {
      insert_adj_vec.push_back(stoi(relationship_file_content[i * _node_count + j]));
    }
    _adj.push_back(insert_adj_vec);
  }
}

/**
 * @brief Set the edges of the graph
 * @param relationship_file_content
 */
void Graph::setEdges(const std::vector<std::string> &relationship_file_content) {
  std::vector<int> insert_edge_vec;
  for (int i = 0; i < _node_count; ++i) {
    insert_edge_vec.clear();
    for (int j = 0; j < _node_count; ++j) {
      if (stoi(relationship_file_content[i * _node_count + j]) != 0) {
        insert_edge_vec.push_back(i);
        insert_edge_vec.push_back(j);
        ++_degree_diff[i];
        --_degree_diff[j];
        _visited[i] = true;
        _visited[j] = true;
        _edges.push_back(insert_edge_vec);
        insert_edge_vec.clear();
      }
    }
  }
  set_edge_count(_edges.size());
  printDegreediffAndVisited();
}

/**
 * @brief Determine the type of the graph according to the judgment method of the Euler graph
 */
void Graph::determineGraphType() {
  // If it is not a connected graph, it is not an Euler graph
  for (int i = 0; i < _node_count; ++i) {
    if (_visited[i] == 0) {
      set_graph_type(NON_EULERIAN);
      printf("No Eular Path > <\n");
      _util.exitProgram(EXIT_SUCCESS);
    }
  }
  // Count the number of odd-degree-diff nodes
  int odd_degree_diff_node_count = 0;
  for (int i = 0; i < _node_count; ++i) {
    if (_degree_diff[i] == 1) {
      odd_degree_diff_node_count += 2;
      set_start_node(i);
    } else if (_degree_diff[i] == -1) {
      odd_degree_diff_node_count -= 1;
    } else if (_degree_diff[i] != 0) {
      set_graph_type(NON_EULERIAN);
      printf("No Eular Path T T\n");
      _util.exitProgram(EXIT_SUCCESS);
    }
  }
  if (odd_degree_diff_node_count == 0) {
    // If the out degree of all nodes is equal to the in degree, it is an Euler graph
    set_graph_type(EULERIAN);
  } else if (odd_degree_diff_node_count == 1) {
    // If there is and only a pair of odd-degree-diff nodes, it is a semi-Euler graph
    set_graph_type(SEMI_EULERIAN);
  }
  printGraphType();
}

/**
 * @brief Calculate the Euler circuit or Euler path of the graph
 */
void Graph::findEulerPath() {
  Adjacent adj;
  for (auto &t : _edges) {
    ++adj[t[0]][t[1]];
  }
  _euler_path.clear();
  euler(adj, _start_node);
  // The calculated data is in reverse order, so it needs to be reversed
  reverse(_euler_path.begin(), _euler_path.end());
}

/**
 * @brief Algorithm for calculating Euler path
 * @param adj
 * @param now
 */
void Graph::euler(Adjacent &adj, int now) {
  // dfs, count-1 every time an edge is traversed.
  for (auto &[next, count] : adj[now]) {
    if (count >= 1) {
      --count;
      euler(adj, next);
    }
  }
  // Each edge of nodes that complete the dfs has been visited, and the nodes are added to the euler path
  _euler_path.push_back(now);
}

/**
 * @brief Print degreediff and visited
 */
void Graph::printDegreediffAndVisited() {
  printf("---------print _degree_diff & _visited\n");
  printf("node count: %d\ndegree_diff :  ", _node_count);
  for (int i = 0; i < _node_count; ++i) {
    printf("%d ", _degree_diff[i]);
  }
  printf("\nvisited :      ");
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
  printf("_graph_type = %s\n", kGraphTypeList[_graph_type].c_str());
  printf("_start_node = %d:%s\n", _start_node, _people.getName(_start_node).c_str());
  printf("\n");
}

/**
 * @brief Print euler path
 */
void Graph::printEulerPath() {
  printf("---------------------print _euler_path\n");
  printf("%s: \n", kGraphTypeList[_graph_type].c_str());

  for (int i = 0; i < _euler_path.size() - 1; ++i) {
    printf("%d:%s -> ", _euler_path[i], _people.getName(_euler_path[i]).c_str());
  }
  printf("%d:%s\n", _euler_path[_euler_path.size() - 1], _people.getName(_euler_path[_euler_path.size() - 1]).c_str());
  printf("\n");
}
}  // namespace Euler