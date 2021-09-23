// #include "GridMap.h"
// #include "Grid.h"
#include "../flow/FindPath.h"
#include "gtest/gtest.h"

TEST(RoutingTest, havePath) {
  findOptimalPath::GridMap<findOptimalPath::Grid> grid_map;
  grid_map.initGridMap("./input/gridmap1.txt");
  grid_map.printGridMap();

  findOptimalPath::FindPath find_path;
  find_path.findPathBy("ASTAR", grid_map);

  grid_map.printOptimalPath();
  
  if (grid_map.get_have_optimal_path()) {
    grid_map.printGridMap();
  }

  EXPECT_TRUE( grid_map.get_have_optimal_path() );
}

TEST(RoutingTest,  haveNoPath) {
  findOptimalPath::GridMap<findOptimalPath::Grid> grid_map;
  grid_map.initGridMap("./input/gridmap2.txt");
  grid_map.printGridMap();

  findOptimalPath::FindPath find_path;
  find_path.findPathBy("A*", grid_map);

  grid_map.printOptimalPath();

  if (grid_map.get_have_optimal_path()) {
    grid_map.printGridMap();
  }

  EXPECT_FALSE( grid_map.get_have_optimal_path() );
}