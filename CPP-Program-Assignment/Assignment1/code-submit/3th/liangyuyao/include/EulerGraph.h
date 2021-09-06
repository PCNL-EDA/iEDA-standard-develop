/**
 * @file        EulerGraph.h
 * @brief       
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-06
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include "DirectedGraph.hpp"
#include "Person.hpp"

#ifndef __EULER_GRAPH_H_
#define __EULER_GRAPH_H_

/**
 * @brief       
 * A tool class with algorithm which is designed to solve Euler Graph problem
 * @exception   
 */
class EulerGraph {
    private:
        EulerGraph() = default; // a tool may not need instance
        static bool isExistEulerPath(const AdjList);
        static bool isExistEulerCircuit(const AdjList, std::vector<Node_ID>&, const Node_ID start = 0);
    public:
        static void printEulerCircuit(const AdjList, const std::vector<Person>);
};



#endif // __EULER_GRAPH_H_