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

namespace model {
class Display {

public:
  Display() = default;
  ~Display() = default;

  int get_max_row() const { return _max_row; }
  int get_max_colunm() const { return _max_column; }
  vector<vector<char>> get_mapdata() const { return _mapdata; }

  void parseMapFile();
  void printInitMap();

private:
  int _max_row = 0;
  int _max_column = 0;
  vector<vector<char>> _mapdata;
};

} // namespace model

#endif // INCLUDE_DISPLAY_H_
