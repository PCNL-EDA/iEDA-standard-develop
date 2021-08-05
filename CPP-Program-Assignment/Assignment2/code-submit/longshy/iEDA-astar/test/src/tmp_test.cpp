#include "gtest/gtest.h"
#include "project/astar.h"

TEST(PathSolverTest, IsReached) {
  std::vector<std::vector<char>> rawmap = {
      {'s', ' ', ' ', ' ', 'x', 'x', 'x', 'x'},
      {' ', ' ', ' ', ' ', ' ', 'x', 'x', 'x'},
      {'x', 'x', ' ', 'x', 'x', ' ', ' ', ' '},
      {'x', ' ', ' ', ' ', ' ', ' ', ' ', 'e'}};
  std::vector<location2d> move = {
      location2d(-1, 0), location2d(-1, -1), location2d(0, -1),
      location2d(1, -1), location2d(1, 0),   location2d(1, 1),
      location2d(0, 1),  location2d(-1, 1),
  };
  map2d amap(rawmap, move, location2d(0, 0), location2d(7, 3));
  pathsolver* abc_solver = new astar();

  EXPECT_TRUE(abc_solver->solve(amap));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
