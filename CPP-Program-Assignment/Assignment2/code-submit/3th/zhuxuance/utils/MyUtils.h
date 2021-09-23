/**
 * @file          MyUtils.h
 * @brief         Some common methods, such as file reading and program exit
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-16
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _FINDOPTIMALPATH_UTILS_MYUTILS_H_
#define _FINDOPTIMALPATH_UTILS_MYUTILS_H_

#include <vector>
#include <string>

namespace findOptimalPath {

/**
 * @brief Utils, used to process data and control programs
 */
class MyUtils {
 public:
  MyUtils()  = default;
  MyUtils(MyUtils &)  = delete;
  MyUtils(MyUtils &&) = delete;
  ~MyUtils() = default;
  void operator=(const MyUtils &) = delete;

  std::vector<std::string> readFileContent(const std::string &file_path);
  void exitProgram(bool exit_code);

};

}  // namespace findOptimalPath

#endif