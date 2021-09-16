/**
 * @file        AStarSearch.cpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#include "AStarSearch.hpp"

#include <assert.h>
#include <stdio.h>

#include <algorithm>

namespace DROP_3TH_ASSIGNMENT2 {

enum ShowType { kBlock = 0, kSrc, kDst, kPath };

/**
 * @brief
 *
 * @param       grid
 * @param       src
 * @param       dst
 * @param       heuristic_type
 * //A Star Search
 * @link https://www.redblobgames.com/pathfinding/a-star/introduction.html
 * //heuristic
 * @link https://zhuanlan.zhihu.com/p/54510444
 * @exception
 */
AStarSearch::AStarSearch(Grid grid, Point src, Point dst,
                         HeuristicType heuristic_type) {
  std::map<Point, double> frontier;
  std::map<Point, Point> came_from;
  std::map<Point, double> cost_so_far;
  frontier[src] = 0;
  came_from[src] = src;
  cost_so_far[src] = 0;

  while (!frontier.empty()) {
    auto current = popMinFrontierPoint(frontier);
    if (current == dst) {
      break;
    }

    //
    auto neighbours = grid.getNeighbours(current);
    for (auto next : neighbours) {
      double new_cost = cost_so_far[current] + grid.calNeigCost(current, next);
      if (cost_so_far.find(next) == cost_so_far.end() ||
          new_cost < cost_so_far[next]) {
        //
        cost_so_far[next] = new_cost;
        double priority = new_cost + heuristic(heuristic_type, next, dst);
        frontier[next] = priority;
        came_from[next] = current;
      }
    }  // end for
  }    // end while

  printPath(grid, src, dst, came_from);
}

/**
 * @brief
 *
 * @param       frontier
 * @return      Point / This predicted point should pay least cost
 * @exception
 */
Point AStarSearch::popMinFrontierPoint(std::map<Point, double>& frontier) {
  Point min_cost_point;
  double min_cost = -1;
  for (auto p : frontier) {
    if (min_cost == -1 || p.second < min_cost) {
      min_cost_point = p.first;
      min_cost = p.second;
    }
  }
  frontier.erase(min_cost_point);
  return min_cost_point;
}

double AStarSearch::heuristic(HeuristicType type, Point src, Point dst) {
  switch (type) {
    case HeuristicType::kDiagonal:
      return heuristicDiagonal(src, dst);
    case HeuristicType::kManhattan:
      return heuristicManhattan(src, dst);
    case HeuristicType::kEuclidean:
      return heuristicEuclidean(src, dst);
    default:
      assert(0);
  }
}

/**
 * @brief
 * if
 *   is_show_print = false ,
 *   then it print 2D Path.
 * else
 *   print core information.
 * @param       grid
 * @param       src
 * @param       dst
 * @param       came_from
 * @exception
 */
void AStarSearch::printPath(Grid grid, Point src, Point dst,
                            std::map<Point, Point> came_from) {
  static const bool is_show_print = false;
  if (came_from.find(dst) == came_from.end()) {
    printf("No path between src(%d,%d) to dst(%d,%d)\n", src.x, src.y, dst.x,
           dst.y);
  } else {
    Grid2D show;
    show.resize(grid.getGrid().size());
    for (size_t row = 0; row < show.size(); ++row) {
      show[row].resize(grid.getGrid()[0].size());
    }

    auto from = came_from[dst];
    is_show_print&& printf("%d,%d\n", dst.x, dst.y);
    show[dst.y][dst.x] = ShowType::kDst;
    while (from != src) {
      show[from.y][from.x] = ShowType::kPath;
      is_show_print&& printf("%d,%d\n", from.x, from.y);
      from = came_from[from];
    }
    is_show_print&& printf("%d,%d\n", src.x, src.y);
    show[src.y][src.x] = ShowType::kSrc;

    if (!is_show_print) {
      printf("\n");
      for (auto row_vec : show) {
        for (auto p : row_vec) {
          switch (p) {
            case ShowType::kBlock:
              printf("# ");
              break;
            case ShowType::kDst:
              printf("\e[1;31mD \e[0m");
              break;
            case ShowType::kPath:
              printf("\e[1;31m* \e[0m");
              break;
            case ShowType::kSrc:
              printf("\e[1;31mS \e[0m");
              break;
            default:
              assert(0);
          }
        }
        printf("\n");
      }
    }
  }
}

}  // namespace DROP_3TH_ASSIGNMENT2
