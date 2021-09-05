/**
 * @file          controller.cpp
 * @brief         implementation of Controller
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <controller.h>

#define PEOPLE_INSTANCE 0
#define EULER_INSTANCE 1

People *Controller::_people = nullptr;
Euler * Controller::_euler  = nullptr;

/**
 * @brief print stored people and graph matrix for eulerian algorithm
 */
void Controller::printALL() const {
  _people->printAll();
  _euler->printAll();
}

/**
 * @brief exit the program obviously
 * @param exit_code
 */
void Controller::exitProgram(bool exit_code) {
  if (!_people) {
    delete _people;
  }

  if (!_euler) {
    delete _euler;
  }

  exit(exit_code);
}

/**
 * @brief get pointer of Controller singleton instance
 * @return Controller*
 */
Controller *Controller::getInstance() {
  static Controller singleton;
  _people = _people ?: new People();
  _euler  = _euler ?: new Euler();
  return &singleton;
}

/**
 * @brief parse main function parameters, and collect files infomation to class People and class Euler
 * @param argc
 * @param argv
 */
void Controller::parseFilesInfo(int argc, const char **argv) {
  if (argc == 3 && argv[1] && argv[2]) {
    parsePath2Data(argv[1], PEOPLE_INSTANCE);
    parsePath2Data(argv[2], EULER_INSTANCE);
  } else {
    printf(
      "invalid parameters\nprogram works with two parameters: "
      "absolute path of \"people.txt\" and \"relationships.txt\", spilt with space\n");
    exitProgram(EXIT_FAILURE);
  }
}

/**
 * @brief read and store people.txt and relationships.txt from given path
 * @param path
 * @param instance
 */
void Controller::parsePath2Data(const char *path, bool instance) {
  FILE *fp = fopen(path, "r");
  if (fp == nullptr) {
    printf("file opening failed, file path: %s\n", path);
    exitProgram(EXIT_FAILURE);
  }

  if (instance == PEOPLE_INSTANCE) {
    _people->read_file(fp);
  }
  if (instance == EULER_INSTANCE) {
    _euler->read_file(fp);
  }

  fclose(fp);
}

/**
 * @brief print Eulerian Path if exists
 */
void Controller::printEulerianPath() {
  if (_people && _euler) {
    unsigned  people_size = _people->how_many_people();
    unsigned *result      = new unsigned[people_size];

    // print eulerian path
    if (_euler->eulerianPath(result)) {
      // print name one by one
      size_t i = 0;
      while (i < people_size) {
        _people->printNameById(result[i]);
        printf("%s", ++i == people_size ? "\n" : " -> ");
      }
    }

    delete[] result;
  }
}

/**
 * @brief print help messages obviously
 */
void Controller::printHelpMessages() const {
  printf("The program will print Eulerian Path by given files path (people, relationships)\n");
}