#include "a_star.h"

namespace pather{

void AStar::findPath(const Graph& graph, Location start, Location goal,
                     std::vector<Location>& path) const {
  /// open nodes
  PriorityQueue<Location, double> frontier;
  /// arrived node and its previous nodes. arrived node: open and close nodes
  std::map<Location, Location> reached_precursor;
  /// movement cost
  std::map<Location, double> movement_cost;

  /// add start to frontier
  frontier.push(start, heuristic(start, goal));
  reached_precursor[start] = start;
  movement_cost[start] = 0;

  /// if frontier if not empty, get element from frontier
  while (!frontier.empty()) {
    /// get element from priority queue
    Location current = frontier.top();
    frontier.pop();

    /// if current location is goal
    if (current == goal) {
      for (auto location : path) {
        std::cout << "(" << location.get_x() << "," << location.get_y() << ")" << std::endl;
      }
      buildPath(start, goal, reached_precursor, path);
      break;
    }

    /// get adjacent nodes of current element
    std::vector<Location> adjacents = graph.adjacentNodes(current);
    /// traverse all adjacent
    for (auto next : adjacents) {
      /// get next adjacent's movment cost
      double new_cost =
          movement_cost[current] + graph.edgeWeight(current, next);
      /// if next adjacent not reached or lower movement cost from current
      /// location
      if (movement_cost.find(next) == movement_cost.end() ||
          new_cost < movement_cost[next]) {
        /// update next vertex movement cost
        movement_cost[next] = new_cost;
        /// update next vertex
        frontier.push(next, new_cost + heuristic(next, goal));
        reached_precursor[next] = current;
      }
    }
  }
}

void AStar::buildPath(Location start, Location goal,
                      std::map<Location, Location>& reached_precursor,
                      std::vector<Location>& path) const {
  Location current = goal;
  while (current != start) {
    path.push_back(current);
    current = reached_precursor[current];
  }
  path.push_back(start);
  std::reverse(path.begin(), path.end());
}

double AStar::heuristic(Location begin, Location end) const {
  int x = std::abs(end.get_x() - begin.get_x());
  int y = std::abs(end.get_y() - begin.get_y());
  return (x + y) + (1.4 - 2) * std::min(x, y);
}

} // astar