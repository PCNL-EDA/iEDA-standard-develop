/**
 * @file          controller.h
 * @brief         get and present data from person class and Euler class
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-03
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef EULERIAN_PATH_H_
#define EULERIAN_PATH_H_
#include <map>
#include <euler.h>
#include <people.h>

/**
 * @brief
 *
 * singleton
 * get and present data from person class and Euler class
 *
 */
class Controller {
 public:
  void operator=(const Controller &) = delete;
  ~Controller()                      = default;

  void printALL() const;
  void printHelpMessages() const;

  void printEulerianPath();
  void exitProgram(bool exit_code);
  void parseFilesInfo(int, const char **);

  static Controller *getInstance();

  Controller(Controller &)  = delete;
  Controller(Controller &&) = delete;

 private:
  explicit Controller() = default;
  void parsePath2Data(const char *, bool);

  static People *_people;
  static Euler * _euler;
};

#endif