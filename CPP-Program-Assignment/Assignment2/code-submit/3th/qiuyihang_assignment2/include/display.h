/**
 * @file display.h
 * @brief Read and display the information of the input file.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-15
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#ifndef INCLUDE_DISPLAY_H_
#define INCLUDE_DISPLAY_H_

#include <stdio.h>
#include <vector>
using std::vector;

namespace resource {
class Display {

public:
  Display(){};
  ~Display(){};
  void parseMapFile();
  void printInitMap();
  int get_max_row_() const { return max_row_; }
  int get_max_colunm_() const { return max_column_; }
  vector<vector<char>> get_mapdata_() const { return mapdata_; }

private:
  int max_row_ = 0;
  int max_column_ = 0;
  vector<vector<char>> mapdata_;
};

} // namespace resource

#endif // INCLUDE_DISPLAY_H_
