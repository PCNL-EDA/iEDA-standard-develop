#include "GridMap.h"
#include "Grid.h"
#include "FindPathAlgorithm.h"
#include "gtest/gtest.h"

TEST(RoutingTest, havePath) {
  findOptimalPath::GridMap<findOptimalPath::Grid> grid_map;
  grid_map.initGridMap("./data/gridmap1.txt");

  findOptimalPath::FindPathAlgorithm find_path_algorithm;
  find_path_algorithm.findPathByAstar(grid_map);

  grid_map.printOptimalPath();
  if (grid_map.get_have_optimal_path()) {
    grid_map.printGridMap();
  }

  EXPECT_TRUE( grid_map.get_have_optimal_path() );
}

TEST(RoutingTest,  haveNoPath) {
  findOptimalPath::GridMap<findOptimalPath::Grid> grid_map;
  grid_map.initGridMap("./data/gridmap2.txt");

  findOptimalPath::FindPathAlgorithm find_path_algorithm;
  find_path_algorithm.findPathByAstar(grid_map);

  grid_map.printOptimalPath();
  if (grid_map.get_have_optimal_path()) {
    grid_map.printGridMap();
  }

  EXPECT_FALSE( grid_map.get_have_optimal_path() );
}