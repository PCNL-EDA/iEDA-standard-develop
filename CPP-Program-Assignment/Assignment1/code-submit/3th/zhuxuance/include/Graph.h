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
using Adjacent = std::unordered_map<int, std::map<int, int> >;

enum kGraphType {
  NON_EULERIAN,   // No Euler Path
  EULERIAN,       // have Euler circuit
  SEMI_EULERIAN,  // have Euler Path
};

/**
 * @brief Graph class, save graph information, calculate Euler path
 */
class Graph {
 public:
  Graph() = default;
  ~Graph();
  void operator=(const Graph &) = delete;

  void initGraph(const std::string &relationship_file_path, const std::string &people_file_path);
  void initGraphBasicInfo(int node_count);
  void setAdj(const std::vector<std::string> &relationship_file_content);
  void setEdges(const std::vector<std::string> &relationship_file_content);

  void set_node_count(int node_count) { _node_count = node_count; };
  void set_edge_count(int edge_count) { _edge_count = edge_count; };
  void set_graph_type(int graph_type) { _graph_type = graph_type; };
  void set_start_node(int start_node) { _start_node = start_node; };
  void set_degree_diff(int node_count) { _degree_diff = new int[node_count](); };
  void set_visited(int node_count) { _visited = new bool[node_count]; };

  void determineGraphType();
  void findEulerPath();
  void euler(Adjacent &adj, int now);

  void printDegreediffAndVisited();
  void printAdj();
  void printEdges();
  void printGraphType();
  void printEulerPath();

  Graph(Graph &)  = delete;
  Graph(Graph &&) = delete;

 private:
  const static std::vector<std::string> kGraphTypeList;
  int   _node_count;
  int   _edge_count;
  int   _graph_type;
  int   _start_node;
  int *_degree_diff;
  bool    *_visited;
  MyUtils     _util;
  People    _people;
  std::vector<std::vector<int> >   _adj;
  std::vector<std::vector<int> > _edges;
  std::vector<int> _euler_path;
};
}  // namespace Euler

#endif