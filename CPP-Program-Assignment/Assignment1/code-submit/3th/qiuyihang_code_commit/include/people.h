/**
 * @file People.h
 * @brief Declare a People class.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 * */
#ifndef INCLUDE_PEOPLE_H_
#define INCLUDE_PEOPLE_H_

#include <assert.h>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class People {
public:
  People() = default;
  ~People() = default;
  void get_info();
  void get_people_info();
  void get_relation_info();
  vector<string> splitInfo(string &);
  void get_name_year();
  inline int get_relation_2D(int x, int y) {
    return _relation_matrix_info[x][y];
  }
  inline int set_relation_2D(int x, int y) {
    return _relation_matrix_info[x][y] = 0;
  }
  inline int get_relation_size() { return _relation_matrix_info.size(); }
  inline int get_people_size() { return _people_info.size(); }
  inline vector<string> get_all_name() { return _all_name; }
  inline vector<string> get_all_year() { return _all_year; }

private:
  vector<vector<int>> _relation_matrix_info;
  vector<string> _people_info;
  vector<string> _all_name;
  vector<string> _all_year;
};

#endif // INCLUDE_PEOPLE_H_
