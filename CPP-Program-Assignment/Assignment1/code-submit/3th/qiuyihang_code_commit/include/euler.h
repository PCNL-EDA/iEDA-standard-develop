/**
 * @file Euler.h
 * @brief Declare an Euler class.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#ifndef INCLUDE_EULER_H_
#define INCLUDE_EULER_H_

#include "people.h"
#include <stack>

using std::stack;

class Euler {
public:
  Euler() = default;
  ~Euler() = default;
  void get_nodes_degree(People &);
  bool isEulerPath(People &);
  void findEulerPath(People &, const int &);
  void printEulerPath(People &);
  void printPeoplePath(People &);

private:
  stack<int> _result_ID_Index;
  stack<int> _result_name_index;
  vector<vector<int>> _nodes_degree;
};

#endif // INCLUDE_EULER_H_
