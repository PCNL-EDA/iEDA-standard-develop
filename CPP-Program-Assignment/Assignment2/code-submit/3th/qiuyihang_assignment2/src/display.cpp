/**
 * @file display.cpp
 * @brief Read and display the information of the input file.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "display.h"

#include <assert.h>
#include <fstream>

using std::ifstream;

namespace resource {

void Display::parseMapFile() {
  ifstream mapfile("../resource/map.txt");
  assert(mapfile.is_open());
  std::string line;
  vector<char> tmp;
  while (getline(mapfile, line)) {
    for (auto &word : line) {
      tmp.push_back(word);
    }
    mapdata_.push_back(tmp);
    tmp.clear();
  }
  max_row_ = mapdata_.size();
  max_column_ = mapdata_[0].size();
  mapfile.close();
#ifndef _GTEST
  printf("\e[0;32m[SUCCESS]\033[0m display->parseMapFile(): Read external "
         "files.\n");
#endif
}

void Display::printInitMap() {
  printf("\e[0;32m[SUCCESS]\033[0m display->printInitMap(): Print the status "
         "of each node, 1 means passable, 0 means obstacle.\n");
  for (int row = 0; row < max_row_; ++row) {
    for (int column = 0; column < max_column_; ++column) {
      printf("%c\t", mapdata_[row][column]);
    }
    printf("\n");
  }
}

} // namespace resource
