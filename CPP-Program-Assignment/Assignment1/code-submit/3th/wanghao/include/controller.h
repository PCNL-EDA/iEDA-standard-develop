/**
 * @file          controller.h
 * @brief         get and present data from person class and GraphMatrix class
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-03
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#ifndef EULERIAN_PATH_H_
#define EULERIAN_PATH_H_
#include <map>
#include <graph_matrix.h>
#include <people.h>

/**
 * @brief
 *
 * singleton
 * get and present data from person class and GraphMatrix class
 *
 */
class Controller {
 public:
  void operator=(const Controller &) = delete;
  ~Controller()                      = default;

  inline void printALL() const;
  inline void printHelpMessages() const;

  void printEulerianPath();
  void exitProgram(bool exit_code);
  void parseFilesInfo(int, const char **);

  static Controller *getInstance();

  Controller(Controller &)  = delete;
  Controller(Controller &&) = delete;

 private:
  explicit Controller() = default;
  void parsePath2Data(const char *, bool);

  static People *     _people;
  static GraphMatrix *_euler;
};

/**
 * @brief print help messages obviously
 */
void Controller::printHelpMessages() const {
  printf("The program will print Eulerian Path by given files path (people, relationships)\n");
}

/**
 * @brief print stored people and graph matrix for eulerian algorithm
 */
void Controller::printALL() const {
  _people->printAll();
  _euler->printAll();
}

#endif