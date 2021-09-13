#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "astar_solver.h"
#include "graph_matrix.h"
#include <cstdio>
#include <cstdlib>

namespace Assignment2 {

class Controller {
  Controller(Controller &)  = delete;
  Controller(Controller &&) = delete;
  ~Controller()             = default;
  void operator=(const Controller &) = delete;

  // get
  static Controller *get_instance() {
    // using loacl static to ensure thread safety (c++11)
    static Controller singleton;
    return &singleton;
  }

  // set
  inline void parse_files_from_main(int argc, const char **argv) {
    if (argc != 2) {
      printf("main args: path(map.txt) required\n");
      exitProgram(EXIT_FAILURE);
    }
    _map.import_data_from_file(argv[1]);
  }

  inline void printALL() const {
    _map.printAll();
    // _astar.printSolverName();
  }

  inline void printHelpMessages() const {
    printf(
      "The program will print Path A to B by"
      "given parameters and files path (map.txt)\n");
  }

  inline void exitProgram(bool exit_code) {
    this->~Controller();
    exit(exit_code);
  }

  // inline void printResult() { _astar.problemSolver(_map); }

 private:
  explicit Controller() = default;

  // AstarSolver<MapMatrix> _astar;
  // MapMatrix _map;
};

}  // namespace Assignment2

#endif