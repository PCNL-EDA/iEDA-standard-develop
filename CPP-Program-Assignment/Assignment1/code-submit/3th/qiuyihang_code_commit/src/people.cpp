/**
 * @file People.cpp
 * @brief Read and process people information from input files.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */

#include "people.h"
#include "euler.h"
#include <assert.h>
#include <fstream>

void People::get_info() {
  get_people_info();
  get_relation_info();
}

void People::get_people_info() {
  ifstream people_file;
  people_file.open("/home/yhqiu/pa1/testcase/people.txt");
  assert(people_file.is_open());
  string people_line;
  while (getline(people_file, people_line)) {
    _people_info.push_back(people_line);
  }
  people_file.close();
}

void People::get_relation_info() {
  ifstream relation_file;
  relation_file.open("/home/yhqiu/pa1/testcase/relationship.txt");
  assert(relation_file.is_open());
  string relation_line;
  vector<int> _relation_info;
  while (getline(relation_file, relation_line)) {
    for (auto &relation_word : relation_line) {
      if (relation_word == '0' || relation_word == '1') {
        // trans char to int ,the ASCII code 48 == '0'
        _relation_info.push_back(relation_word - 48);
      }
    }
    _relation_matrix_info.push_back(_relation_info);
    _relation_info.clear();
  }
  relation_file.close();
}

vector<string> People::splitInfo(string &words_before_split) {
  vector<string> words_after_split{};
  size_t pos = 0;
  const string space = " ";
  while ((pos = words_before_split.find(space)) != string::npos) {
    words_after_split.push_back(words_before_split.substr(0, pos));
    words_before_split.erase(0, pos + space.length());
  }
  return words_after_split;
}

void People::get_name_year() {
  for (int people_id = 0; people_id < _people_info.size(); ++people_id) {
    vector<string> temp{};
    // after splitting, the _people_info will be erased.
    temp = splitInfo(_people_info[people_id]);
    _all_name.push_back(temp[1]);
    _all_year.push_back(temp[2]);
  }
}
