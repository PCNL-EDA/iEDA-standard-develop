/**
 * @file          People.cc
 * @brief         Implementation of class People
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "People.h"

namespace Euler {
/**
 * @brief Read the person’s information from the file and store it in the member variable _people_list
 * @param people_file_path
 */
void People::setPeopleList(const std::string &people_file_path) {
  printf("start to set people...\n");
  std::vector<std::string> file_content;
  file_content = _util.readFileContent(people_file_path);

  std::vector<std::string>::const_iterator i;
  for (i = file_content.begin(); i < file_content.end(); i += 3) {
    _people_list[stoi(*i)].push_back(*(i + 1));
    _people_list[stoi(*i)].push_back(*(i + 2));
  }
  printf("got people file content\n\n");
  printPeopleList();
}

/**
 * @brief Get the name with person_id
 * @param person_id
 * @return string
 */
std::string People::getName(int person_id) { return _people_list[person_id][0]; }

/**
 * @brief Get the birth with person_id
 * @param person_id
 * @return string
 */
std::string People::getBirth(int person_id) { return _people_list[person_id][1]; }

/**
 * @brief Get name and birth with person_id
 * @param person_id
 * @return vector<string>
 */
std::vector<std::string> People::getInfo(int person_id) {
  std::vector<std::string> people_info(2);
  people_info.push_back(_people_list[person_id][0]);
  people_info.push_back(_people_list[person_id][1]);
  return people_info;
}

/**
 * @brief print people list
 */
void People::printPeopleList() {
  printf("--------------------print _people_type\n");
  for (int i = 0; i < _people_list.size(); ++i) {
    printf("%d: %s, \t%s\n", i, _people_list[i][0].c_str(), _people_list[i][1].c_str());
  }
  printf("\n");
}
}  // namespace Euler