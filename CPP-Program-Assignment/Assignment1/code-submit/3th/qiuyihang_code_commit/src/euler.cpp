/**
 * @file Euler.cpp
 * @brief Determine whether the Euler path exists and print the Euler path.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "euler.h"

/**
 * @brief  Compute in_degree and out_degree of every node
 * @param  &P: People instance
 * @retval None
 */
void Euler::get_nodes_degree(People &P) {
  vector<int> node_degree;
  int in_degree = 0;
  int out_degree = 0;
  int row = 0;
  while (row != P.get_relation_size()) {
    for (int column = 0; column != P.get_relation_size(); ++column) {
      if (P.get_relation_2D(row, column) == 1) {
        ++out_degree;
      }
      if (P.get_relation_2D(column, row) == 1) {
        ++in_degree;
      }
    }
    node_degree.push_back(in_degree);
    node_degree.push_back(out_degree);
    in_degree = 0, out_degree = 0;
    _nodes_degree.push_back(node_degree);
    node_degree.clear();
    ++row;
  }
}
/**
 * @brief  Determine whether it is an Euler graph.
 * * Based on the degree of in and out of all nodes.
 * @param  &P: People instance
 * @retval bool
 */
bool Euler::isEulerPath(People &P) {
  get_nodes_degree(P);
  int in_label = 0;
  int out_label = 0;
  for (auto &node_degree : _nodes_degree) {
    if (in_label != 2 && out_label != 2) {
      if (node_degree[0] == node_degree[1]) {
        continue;
      }
      if (node_degree[0] == node_degree[1] + 1) {
        ++in_label;
      } else if (node_degree[0] == node_degree[1] - 1) {
        ++out_label;
      } else if (node_degree[0] != node_degree[1]) {
        ++out_label;
        ++in_label;
      }
    }
  }
  if (in_label == 0 && out_label == 0) {
    printf("Can find an Euler cycle \n");
    return true;
  } else if (in_label == 1 && out_label == 1) {
    printf("Can find an Euler path but not an Euler cycle \n");
    return true;
  } else {
    printf("No Eular Path\n");
    return false;
  }
}
/**
 * @brief  Hierholzer algorithm
 * @link   https://blog.csdn.net/STILLxjy/article/details/51956183 @endlink
 * @param  &P: People instance
 * @param  &start_point: The start point of Euler path
 * @retval None
 */
void Euler::findEulerPath(People &P, const int &start_point) {
  for (int point = 0; point != P.get_people_size(); ++point) {
    if (P.get_relation_2D(start_point, point)) {
      P.set_relation_2D(start_point, point);
      P.set_relation_2D(point, start_point);
      findEulerPath(P, point);
    }
  }
  _result_ID_Index.push(start_point);
}
/**
 * @brief  Print Euler path about ID
 * @param  &P: People instance
 * @retval None
 */
void Euler::printEulerPath(People &P) {
  _result_name_index = _result_ID_Index;
  printf("The Euler path is: ");
  while (!_result_ID_Index.empty()) {
    if (_result_ID_Index.size() != 1) {
      printf("%d -> ", _result_ID_Index.top());
    } else {
      printf("%d \n", _result_ID_Index.top());
    }
    _result_ID_Index.pop();
  }
}
/**
 * @brief  Print Euler path about people name and year
 * @param  &P: People instance
 * @retval None
 */
void Euler::printPeoplePath(People &P) {
  P.get_name_year();
  printf("The Corresponding People Info is: ");
  while (!_result_name_index.empty()) {
    if (_result_name_index.size() != 1) {
      printf("%s(%s) ->", P.get_all_name()[_result_name_index.top()].c_str(),
             P.get_all_year()[_result_name_index.top()].c_str());
    } else {
      printf("%s(%s) \n", P.get_all_name()[_result_name_index.top()].c_str(),
             P.get_all_year()[_result_name_index.top()].c_str());
    }
    _result_name_index.pop();
  }
}
