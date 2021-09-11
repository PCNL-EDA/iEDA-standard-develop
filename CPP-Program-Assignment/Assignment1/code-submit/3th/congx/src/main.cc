/**
 * @file main.cc
 * @author congx
 * @brief Tests whether the given graph is an Euler graph
 * @version 0.1
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021 PCL
 *
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "graph.h"
#include "graph_io.h"
#include "person.h"

int main() {
  MatrixGraph<Person> graph;
  GraphIO<Person> graph_io;

  // Read the information from the file into the graph
  graph_io.read(graph, "../data/people.txt", "../data/relationship.txt");

  int begin_vertex;
  int result;
  if ((result = graph.isEulerPath(&begin_vertex)) == NOT_EULER_PATH) {
    std::cout << "it isn't euler graph." << std::endl;
    return 0;
  }
  std::cout << "it is euler " << (result == EULER_GRAPH ? "graph" : "path")
            << std::endl;

  // Gets the sequence of vertices of the Euler path
  std::vector<Person> euler_path = graph.getEulerPath(begin_vertex);

  // print the Euler path
  graph_io.print(euler_path);

  return 0;
}
