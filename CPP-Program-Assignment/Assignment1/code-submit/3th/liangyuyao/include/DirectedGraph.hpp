/**
 * @file        DirectedGraph.hpp
 * @brief       
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include <vector>
#include <stdint.h>

#ifndef __DIRECTED_GRAPH_HPP_
#define __DIRECTED_GRAPH_HPP_

typedef uint32_t Node_ID;
typedef std::vector<std::vector<Node_ID>> AdjList;

/**
 * @brief       
 * Now supplys adjacency list as store data structure.
 * This class is related to relationship.txt
 * @exception   
 */
class DirectedGraph {
    private:
        AdjList _adj_list; // adjacency list   
    public:
        // constructor
        DirectedGraph() = default;
        ~DirectedGraph() = default;
        // get
        const AdjList getAdjList() const;
        Node_ID getVertexNum() const;
        // set
        DirectedGraph& setAdjList(AdjList);
        // copy
        DirectedGraph(DirectedGraph&) = delete;
};

inline const AdjList DirectedGraph::getAdjList() const { return _adj_list; }
inline DirectedGraph& DirectedGraph::setAdjList(AdjList list) { _adj_list = list; return *this; }
inline Node_ID DirectedGraph::getVertexNum() const { return _adj_list.size(); }



#endif // __DIRECTED_GRAPH_HPP_