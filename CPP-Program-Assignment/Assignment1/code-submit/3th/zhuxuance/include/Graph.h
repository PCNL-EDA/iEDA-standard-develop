/**
 * @file          Graph.h
 * @brief         Graph definition, including initialization, finding Euler path, printing data
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _EULER_INCLUDE_GRAPH_H_
#define _EULER_INCLUDE_GRAPH_H_

#include <map>
#include <unordered_map>
#include "MyUtils.h"
#include "People.h"

namespace Euler {
// typedef unordered_map<int, map<int, int> > Adjacent;
using Adjacent = std::unordered_map<int, std::map<int, int> >;

#define NON_EULERIAN 0
#define EULERIAN 1
#define SEMI_EULERIAN 2

const std::vector<std::string> graph_type_list{"No Eular Path", "Euler circuit", "Euler path"};

/**
 * @brief Graph class, save graph information, calculate Euler path
 */
class Graph {
 public:
  Graph() = default;
  ~Graph();
  void operator=(const Graph &) = delete;

  void setGraph(int, const char **);
  void setGraphInfo(int node_count);
  void setAdj(const std::vector<std::string> &file_content);
  void setEdges(const std::vector<std::string> &file_content);

  void set_node_count(int node_count) { _node_count = node_count; };
  void set_edge_count(int edge_count) { _edge_count = edge_count; };
  void set_graph_type(int graph_type) { _graph_type = graph_type; };
  void set_start_node(int start_node) { _start_node = start_node; };
  void set_degree(int node_count) { _degree = new int[node_count](); };
  void set_visited(int node_count) { _visited = new bool[node_count]; };

  void getGraphType();
  void getEulerPath();
  void euler(Adjacent &adj, int now);

  void printDegreeAndVisited();
  void printAdj();
  void printEdges();
  void printGraphType();
  void printEulerPath();

  Graph(Graph &)  = delete;
  Graph(Graph &&) = delete;

 private:
  int _node_count;
  int _edge_count;
  int _graph_type;
  int _start_node;
  int    *_degree;
  bool  *_visited;
  MyUtils   _util;
  People  _people;
  std::vector<std::vector<int> >   _adj;
  std::vector<std::vector<int> > _edges;
  std::vector<int> _euler_path;
};
}  // namespace Euler

#endif