/**
 * @file        DirectedGraph.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __DIRECTED_GRAPH_HPP_
#define __DIRECTED_GRAPH_HPP_

#include <stdint.h>

#include <vector>

namespace DROP_3th_ASSIGNMENT1 {

typedef uint32_t Node_ID;
typedef std::vector<std::vector<Node_ID>> AdjList;

/**
 * @brief
 * Now supplys adjacency list as store data structure.
 * This class is related to relationship.txt
 * @exception
 */
class DirectedGraph {
 public:
  // constructor
  DirectedGraph() = default;
  ~DirectedGraph() = default;
  DirectedGraph(DirectedGraph&) = delete;

  // get
  const AdjList getAdjList() const { return _adj_list; };
  Node_ID getVertexNum() const { return _adj_list.size(); }
  // set
  void setAdjList(AdjList list) { _adj_list = list; }

 private:
  AdjList _adj_list;  // adjacency list
};

}  // namespace DROP_3th_ASSIGNMENT1
#endif  // __DIRECTED_GRAPH_HPP_