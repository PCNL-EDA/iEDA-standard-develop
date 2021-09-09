/**
 * @file          People.h
 * @brief         Definition of person
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _EULER_INCLUDE_PEOPLE_H_
#define _EULER_INCLUDE_PEOPLE_H_

#include <unordered_map>
#include "MyUtils.h"

namespace Euler {
// typedef unordered_map<int, vector<string> > PeopleList;
using PeopleList = std::unordered_map<int, std::vector<std::string> >;

/**
 * @brief People class, save people‘s information
 */
class People {
 public:
  People()  = default;
  ~People() = default;
  void operator=(const People &) = delete;

  void setPeopleList(const std::string &people_file_path);

  std::string getName(int person_id);
  std::string getBirth(int person_id);
  std::vector<std::string> getInfo(int person_id);

  void printPeopleList();

  People(People &)  = delete;
  People(People &&) = delete;

 private:
  PeopleList _people_list;
  MyUtils    _util;
};
}  // namespace Euler

#endif