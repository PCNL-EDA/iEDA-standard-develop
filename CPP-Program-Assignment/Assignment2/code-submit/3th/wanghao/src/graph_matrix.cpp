/**
 * @file          graph_matrix.cpp
 * @brief         implementation of Class MapMatrix and MapMatrix
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "graph_matrix.h"

namespace Assignment2 {
/**
 * @brief delete old data space and then creat a new space of a given size
 * @param size
 */
void MapMatrix::resetGraphSpace(int weight, int height) {
  if (height <= 0 || weight <= 0) {
    // assertion is better, but let's assume this would never happen
    return;
  }

  delete[] _data;
  _size_weight = weight;
  _size_height = height;
  _data        = new int[weight * height];
}

/**
 * @brief read graph matrix data from file fp
 * @param fp
 */
void MapMatrix::import_data_from_file(const char *file_path) {
  FILE *fp = fopen(file_path, "r");
  int   weight, height;
  int   discard;  // we will use this to collect data that will never be used

  discard = fscanf(fp, "%d %d\n", &weight, &height);
  resetGraphSpace(weight, height);

  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < weight; ++j) {
      discard = fscanf(fp, " %d ", &get_edge(i, j));
    }
  }
}

/**
 * @brief print graph matirx
 */
void MapMatrix::printAll() const {
  printf(
    ">>> print graph matrix for MapMatrix Algorithm\n"
    "weight %d\theight %d\n",
    _size_weight, _size_height);

  for (size_t i = 0; i < _size_height; ++i) {
    for (size_t j = 0; j < _size_weight; ++j) {
      printf("%d ", edge(i, j));
    }
    putchar('\n');
  }
  putchar('\n');
}

}  // namespace Assignment2