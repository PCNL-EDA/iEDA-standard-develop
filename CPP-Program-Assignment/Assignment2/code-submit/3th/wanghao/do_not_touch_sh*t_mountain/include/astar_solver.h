#ifndef ASTAR_SOLVER_H_
#define ASTAR_SOLVER_H_

#include "solver.h"

namespace Assignment2 {

class AstarSolver : public PathFindingSolver {
 public:
  AstarSolver()  = default;
  ~AstarSolver() = default;

  kDELETE_UNUSED_CONSTRUCTOR(AstarSolver);

  // get
  int get_path_distance() const;
  int get_path_vector() const;

  // set
  void import_grid_map_from_file(const char *) override final;
  void set_start_and_end(pair<int, int> start, pair<int, int> end) override final {
    _data.set_start(start);
    _data.set_end(end);
  }

  // solver
  int runSolver() override final;

  // display
  void displaySolverName() const override final;
  void displayPorblemToBeSolved() const override final;
  void displayResults() const override final;
  void displayExecTimeMS() const override final;

  void displayAll() const override final {
    displaySolverName();
    displayPorblemToBeSolved();
    displayResults();
    displayExecTimeMS();
  }

  void displayExecTimeMS() const override final {
    int millisecond = _exec_time.tv_sec * 1000 + _exec_time.tv_usec / 1000;
    printf("Execution time: %d ms\n", millisecond);
  }

 private:
  // static string _solver_name;
  // timeval       _exec_time;
  bool isOpenListEmpty() const { return _data.isOpenListEmpty(); }
  bool isCurrentDestination() const { return _data.isCurrentDestination(); }
  void popLowestFCostFromOpenList() { _data.popLowestFCostFromOpenList(); }
  void pushCurrent2CloseList() { _data.pushCurrent2CloseList(); }

  void pushNeighbor2OpenList() { _data.pushNeighbor2OpenList(); }

  int saveAstarPath() {
    // find back from *_curr
    TODO();
  }

  void clearResultVector() { _result.clear(); }
  void clearCloseList() { _data.clear_close_list(); }
  void clearOpenList() { _data.clear_open_list(); }
  bool initStartPoint() {
    if (_data.isReachable_Start()) {
      _data.push2OpenList_start();
      return true;
    }
    return false;
  }
  bool initEndPoint() {
    if (isReachable_End()) {
      return true;
    }
    return false;
  }

  bool      _path_exist;
  NodeVec   _result;
  AstarData _data;
};
static string _solver_name("Astar PathFindingSolver\n");
}  // namespace Assignment2

#endif