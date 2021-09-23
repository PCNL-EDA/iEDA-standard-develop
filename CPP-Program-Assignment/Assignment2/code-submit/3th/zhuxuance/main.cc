#include "./flow/FindPath.h"
int main(int argc, const char **argv) {
  if (argc != 2 || !argv[1]) {
    printf("invalid parameters\n");
    return 0;
  }
  std::string grid_map_path(argv[1]);

  findOptimalPath::GridMap<findOptimalPath::Grid> grid_map;
  grid_map.initGridMap(grid_map_path);

  findOptimalPath::FindPath find_path;

  find_path.findPathByAstar(grid_map);

  grid_map.printOptimalPath();

  if (grid_map.get_have_optimal_path()) {
    grid_map.printGridMap();
  }

  return 0;
}