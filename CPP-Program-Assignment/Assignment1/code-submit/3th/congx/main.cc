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

#include "graph.h"
#include "person.h"

int main() {
  MatrixGraph<Person> graph(std::string("people.txt"),
                            std::string("relationship.txt"));

  int begin_vertex;
  int result = graph.isEulerPath(&begin_vertex);
  if (result == 0) {
    std::cout << "it isn't euler graph." << std::endl;
  } else {
    std::cout << (result == 1 ? "it is euler graph" : "it is euler path")
              << std::endl;
    std::vector<Person> euler_path = graph.printEulerPath(begin_vertex);
    for (auto iter = euler_path.begin(); iter != euler_path.end(); iter++) {
      std::cout << (*iter).get_name();
      std::cout << (iter + 1 != euler_path.end() ? " -> " : "\n");
    }
  }

  return 0;
}