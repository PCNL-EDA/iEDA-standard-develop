#ifndef ASTAR_SOLVER_H_
#define ASTAR_SOLVER_H_

#include <cstdio>
#include <utility>
#include "graph_matrix.h"

using coordinate = std::pair<unsigned, unsigned>;

namespace Assignment2 {

template <class T>
class Solver {
 public:
  Solver()  = default;
  ~Solver() = default;

  // solver
  virtual int  problemSolver(const T &, void *) = 0;
  virtual void printAlgorithmName() const       = 0;
};

template <class T>
class AstarSolver : public Solver<T> {
 public:
  AstarSolver()  = default;
  ~AstarSolver() = default;

  // solver
  int problemSolver(const T &, coordinate &, coordinate &, void *);

  void printAlgorithmName() const { printf("Astar solver\n"); }

  //  private:
  //   void dfs();
};

}  // namespace Assignment2

#endif