/**
 * @file          MyUtils.h
 * @brief         Some common methods, such as file reading and program exit
 * @author        zhuxuance (zxuance@mail.ustc.edu.cn)
 * @date          2021-09-07
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef _EULER_INCLUDE_MYUTILS_H_
#define _EULER_INCLUDE_MYUTILS_H_

#include <string>
#include <vector>

namespace Euler {
/**
 * @brief Utils, used to process data and control programs
 */
class MyUtils {
 public:
  MyUtils()  = default;
  ~MyUtils() = default;
  void operator=(const MyUtils &) = delete;

  std::vector<std::string> readFileContent(const std::string &file_path);
  void exitProgram(bool exit_code);

  MyUtils(MyUtils &)  = delete;
  MyUtils(MyUtils &&) = delete;
};
}  // namespace Euler

#endif