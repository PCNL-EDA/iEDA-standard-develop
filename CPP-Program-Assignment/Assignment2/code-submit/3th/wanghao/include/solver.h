#ifndef ASTAR_SOLVER_H_
#define ASTAR_SOLVER_H_

#include <cstdio>
#include <utility>
#include "grid_map.h"

namespace Assignment2 {

template <class T>
class Solver {
 public:
  Solver()  = default;
  ~Solver() = default;

  // solver
  virtual int  problemSolver(const T &, void *) = 0;
  virtual void displaySolverName() const        = 0;
};

template <class T>
class AstarSolver : public Solver<T> {
 public:
  AstarSolver()  = default;
  ~AstarSolver() = default;

  // solver
  int problemSolver(const T &, void *);

  void displaySolverName() const { printf("Astar solver\n"); }

  void displayAll() const { displaySolverName(); }

  // specific routine (print pretty map)

  // Manhattan distance of path

  // get path return array of coordinate

  // time of execution
};

}  // namespace Assignment2

#endif