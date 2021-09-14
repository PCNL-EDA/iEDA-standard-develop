#include "Algorithm.h"

#include <algorithm>

void AStarSearch(Grid grid, Point src, Point dst) {
  std::map<Point, int> frontier;
  std::map<Point, Point> came_from;
  std::map<Point, int> cost_so_far;
  frontier.insert({src, 0});

  came_from.insert({src, src});
  cost_so_far.insert({src, 0});

  while (!frontier.empty()) {
    auto current = popMinFrontierPoint(frontier);
    if (current == dst) {
      break;
    }
  }
}

Point popMinFrontierPoint(std::map<Point, int>& frontier) {
  auto target = std::min_element(frontier.begin(), frontier.end(), minCompare);
  frontier.erase(target);
  return target->first;
}
bool minCompare(std::pair<Point, int> e1, std::pair<Point, int> e2) {
  return e1.second < e2.second;
}
