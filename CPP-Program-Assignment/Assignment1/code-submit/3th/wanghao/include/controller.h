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

#define PEOPLE_INSTANCE 0
#define EULER_INSTANCE 1

namespace Assignment1{
/**
 * @brief
 *
 * singleton
 * get and present data from person class and GraphMatrix class
 *
 */
class Controller {
 public:
  Controller(Controller &)  = delete;
  Controller(Controller &&) = delete;
  ~Controller(){
    if (!_people) {
      delete _people;
    }

    if (!_euler) {
      delete _euler;
    }
  }
  void operator=(const Controller &) = delete;

  // get
  static Controller *get_instance();

  // set
  void parse_files_info(int, const char **);

  inline void printALL() const{
    _people->printAll();
    _euler->printAll();
  }
  
  inline void printHelpMessages() const{
    printf("The program will print Eulerian Path by given files path (people, relationships)\n");
  }

  inline void exitProgram(bool exit_code) {
    this->~People();
    exit(exit_code);
  }

  void printEulerianPath();

 private:
  explicit Controller() = default;
  void parsePath2Data(const char *, bool);

  static People      *_people;
  static GraphMatrix *_euler;
};

People      *Controller::_people = nullptr;
GraphMatrix *Controller::_euler  = nullptr;

} // namespace Assignment1

#endif