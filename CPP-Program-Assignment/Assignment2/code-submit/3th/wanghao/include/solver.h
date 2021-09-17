#ifndef SOLVER_H_
#define SOLVER_H_

#include <cstdio>
#include <cassert>
#include <utility>
#include <string>

using std::pair;
using std::string;

namespace Assignment2 {

class PathFindingSolver {
 public:
  PathFindingSolver() {}

  virtual ~PathFindingSolver() {}

  // set
  virtual void import_grid_map_from_file(const char *);
  virtual void set_start_and_end(pair<int, int> &&, pair<int, int> &&);

  // solver
  virtual void runSolver() = 0;

  // display
  virtual void displayResults() const           = 0;
  virtual void displaySolverName() const        = 0;
  virtual void displayPorblemToBeSolved() const = 0;

 protected:
  static string _solver_name;
  timeval       _exec_time;
};

}  // namespace Assignment2

#endif