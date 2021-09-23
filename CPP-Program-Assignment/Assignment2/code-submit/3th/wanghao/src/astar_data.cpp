#include "astar_data.h"
namespace Assignment2 {

Node operator+(const Node &a, const Node &b) {
  Node result;
  result.first.first  = a.first.first + b.first.first;
  result.first.second = a.first.second + b.first.second;
  result.second       = 0;
  return result;
}

bool operator==(const Node &a, const Node &b) { return a.first == b.first; }

void AstarData::resize_grid_map(int x, int y) {
  assert(x > 0 && y > 0);
  delete _grid_map;
  _grid_map     = new int[x * y];
  _map_x_length = x;
  _map_y_length = y;
}

void AstarData::import_grid_map_from_file(const char *file) {
  FILE *fp = fopen(file, "r");

  int x, y;

  fscanf(fp, "%d %d\n", &x, &y);
  resize_grid_map(x, y);

  for (int j = 0; j < y; ++j) {
    for (int i = 0; i < x; ++i) {
      fscanf(fp, " %d ", p_grid_map_data(i, j));
    }
  }

  fclose(fp);
}

int AstarData::calculateNeighborCost(const Node &current, const Node &neighbor) const {
  // if (x-x)*(y-y) is 0,
  // then neighbor is right in the top/below/right/left (cost is 1.000)
  // otherwise in one of the four corners (cost is 1.414)
  return ((current.first.first - neighbor.first.first) * (current.first.second - neighbor.first.second)) ? 1000 : 1414;
}

NodeVec AstarData::pack8Neighbors(const Node &node) {
  NodeVec neighbors_package;
  for (const Node &node_shift : neighbors_shift) {
    Node neighbor;
    neighbor = node + node_shift;

    // border check
    if (((neighbor.first.first >= 0) && (neighbor.first.first < _map_x_length)) &&
        ((neighbor.first.second >= 0) && (neighbor.first.second < _map_y_length))) {
      neighbors_package.emplace_back(neighbor);
    }
  }
  return neighbors_package;
}

void AstarData::displayMap() const {
  for (int j = 0; j < _map_y_length; ++j) {
    for (int i = 0; i < _map_x_length; ++i) {
      if (isStart({i, j})) {
        printf("\033[47;31m%s\033[0m", "😅 ");
      } else if (isEnd({i, j})) {
        printf("\033[47;34m%s\033[0m", "🚾 ");
      } else {
        if (grid_map_data(i, j)) {
          printf("\033[47;30m%s\033[0m", " · ");
        } else {
          printf("\033[47;30m%s\033[0m", "🔞 ");
        }
      }
    }
    putchar('\n');
  }
}
}  // namespace Assignment2