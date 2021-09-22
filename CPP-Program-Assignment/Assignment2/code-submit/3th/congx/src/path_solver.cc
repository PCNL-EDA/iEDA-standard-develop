#include "path_solver.h"
#include "grid_graph.h"


namespace pather{

PathSolver::PathSolver(GraphSearch& path_search, Graph& graph,
                       GraphIO& graph_io) {
  _path_search = &path_search;
  _graph = &graph;
  _graph_io = &graph_io;
}

void PathSolver::findPath(Location start, Location goal,
                          std::vector<Location>& path) const {
  _path_search->findPath(*_graph, start, goal, path);
}

void PathSolver::initMap(const std::string& file) {
  assert(file != "");
  std::vector<std::vector<char>> map;
  _graph_io->read(file, map);
  this->writeDataToGraph(map);
}

void PathSolver::writeDataToGraph(const std::vector<std::vector<char>>& map) {
  int height = map.empty() ? 0 : map.size();
  int width = map.empty() ? 0 : map[0].size();
  _graph->set_height(height);
  _graph->set_width(width);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if (map[y][x] == kBarrier) {
        _graph->set_barrier(Location(x, y));
      }
    }
  }
}

void PathSolver::output(const std::vector<Location>& path) const {
  int width = _graph->get_width();
  int height = _graph->get_height();
  std::vector<std::vector<char>> path_map(height,
                                          std::vector<char>(width, '.'));

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      if (!_graph->passable(Location(x, y))) {
        path_map[y][x] = kBarrier;
      }
    }
  }
  for (auto location : path) {
    path_map[location.get_y()][location.get_x()] = kTrack;
  }
  _graph_io->write(path_map);
}

} // astar
