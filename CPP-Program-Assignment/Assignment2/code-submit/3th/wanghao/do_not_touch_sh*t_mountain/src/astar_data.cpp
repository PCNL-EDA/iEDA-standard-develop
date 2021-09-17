#include "astar_data.h"

namespace Assignment2 {
void AstarData::import_obstacles_from_file(const char *file) {
  FILE *fp = fopen(file, "r");

  int weight, height;
  int discard;  // we will use this to collect data that will never be used
  int node;

  discard = fscanf(fp, "%d %d\n", &weight, &height);

  // save obstacles point only
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < weight; ++j) {
      discard = fscanf(fp, " %d ", &node);
      if (!node) {
        add_obstacles({i, j});
      }
    }
  }
}

bool AstarData::isReachable(const pair<const int, const int> &node) const {
  if ((_x_axis.first < node.first) && (node.first < _x_axis.second) && (_y_axis.first < node.second) &&
      (node.second < _y_axis.second)) {
    auto unreachable_iterator = _obstacles.find(node);
    return unreachable_iterator != _obstacles.end();
  }
}

vector<pair<int, int>> &AstarData::packReachableNeighbor() {
  vector<pair<int, int>> neighbors_package;

  pair<int, int> base(_curr->get_pair());
  for (auto coord : neighbors) {
    auto neighbor = base + coord;
    if (isReachable(neighbor) && !inCloseList(neighbor)) {
      neighbors_package.push_back(neighbor);
    }
  }
}

void AstarData::pushNeighbor2OpenList() {
  const vector<pair<int, int>> &neighbors_package = packReachableNeighbor();
  for (const auto &node : neighbors_package) {
    if (inOpenList(node)) {
      updateG(node);
    } else {
      push2OpenList(node);
    }
  }
}

}  // namespace Assignment2