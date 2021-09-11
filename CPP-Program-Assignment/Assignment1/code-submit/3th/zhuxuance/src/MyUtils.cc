/**
 * @file          MyUtils.cc
 * @brief         Implementation of class MyUtils
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include "MyUtils.h"

namespace Euler {
/**
 * @brief Read the contents of the file according to the path
 * @param file_path
 * @return vector<string>
 */
std::vector<std::string> MyUtils::readFileContent(const std::string &file_path) {
  FILE *file;
  char str[20];
  std::string to_str;
  std::vector<std::string> file_content;
  file = fopen(file_path.c_str(), "r");
  while (fscanf(file, "%s", str) != EOF) {
    to_str = str;
    file_content.emplace_back(to_str);
  }
  fclose(file);
  return file_content;
}

/**
 * @brief Exit the program
 * @param exit_code 
 */
void MyUtils::exitProgram(bool exit_code) { exit(exit_code); }
}  // namespace Euler