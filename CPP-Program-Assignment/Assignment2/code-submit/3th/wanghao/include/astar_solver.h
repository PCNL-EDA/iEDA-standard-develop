#ifndef ASTAR_SOLVER_H_
#define ASTAR_SOLVER_H_

#include "solver.h"
#include <cstdio>
#include <cassert>
#include <utility>
#include <string>

#include "astar_data.h"

using std::pair;
using std::string;

namespace Assignment2 {

class AstarSolver : public PathFindingSolver {
 public:
  AstarSolver(int (*heuristic)(const std::pair<int, int> &, const std::pair<int, int> &)) : _data(heuristic) {}
  ~AstarSolver() = default;

  // get
  int get_path_distance() const { return _path.size(); }
  int get_path_vector() const;

  // set
  void import_grid_map_from_file(const char *file) override final { _data.import_grid_map_from_file(file); };
  void save_path() { _data.get_path(); }
  void set_start_and_end(pair<int, int> &&start, pair<int, int> &&end) override final {
    _data.set_start(Node(start, 0));
    _data.set_end(Node(end, 0));
  }

  // solver
  void runSolver() override final;

  // display
  void displayPorblemToBeSolved() const override final { _data.displayMap(); }
  void displayResults() const override final { _data.displayPath(_path); }
  void displaySolverName() const override final { printf("%s\n", _solver_name.c_str()); }

 private:
  // run solver functions
  void initSolver() {
    _data.emptyOpenList();
    _data.pushStart2OpenList();
  }

  NodeVec &&get_neighbors(const Node &node) { _data.pack8Neighbors(node); }

  int get_new_cost_with_neighbor(const Node &current, const Node &neighbor) {
    return _data.get_cost(current) + _data.calculateNeighborCost(current, neighbor);
  }

  bool needUpdate(const Node &node, int cost) { return !_data.hasBeenCounted(node) || cost < _data.get_cost(node); }

  void updateNeighborsCost(Node &neighbor, int new_cost) {
    _data.set_cost(neighbor, new_cost);
    neighbor.second = new_cost + _data.heuristicCost2End(neighbor.first);
    _data.push2OpenList(neighbor);
  }

  void add_node_to_path(const Node &current, const Node &neighbor) { _data.add_node_to_path(current, neighbor); }

  bool isOpenListEmpty() { return _data.isOpenListEmpty(); }

  bool isEndNode(const Node &node) { _data.isEnd(node.first); }

  const Node &get_lowest_cost_from_open_list() { return _data.get_lowest_cost_from_open_list(); }

  string    _solver_name;
  Path      _path;
  AstarData _data;
};

static string _solver_name = "Astar PathFindingSolver";

}  // namespace Assignment2

#endif