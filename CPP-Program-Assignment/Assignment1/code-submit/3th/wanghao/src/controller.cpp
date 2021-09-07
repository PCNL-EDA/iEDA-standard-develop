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

People *     Controller::_people = nullptr;
GraphMatrix *Controller::_euler  = nullptr;

/**
 * @brief exit the program, but destroy _people and _euler firstly
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
  // loacl static ensure that thread safty (c++11)
  static Controller singleton;
  _people = _people ?: new People();
  _euler  = _euler ?: new GraphMatrix();
  return &singleton;
}

/**
 * @brief parse main function parameters, and collect files infomation to class People and class GraphMatrix
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
      "input path of \"people.txt\" and \"relationships.txt\", spilt with space\n");
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
    unsigned  path_length   = 0;
    unsigned *p_path_length = &path_length;
    unsigned  people_size   = _people->how_many_people();
    unsigned  edge_size     = people_size * people_size;
    unsigned *result        = new unsigned[edge_size];
    memset(result, 0, edge_size * sizeof(unsigned));

    // print eulerian path
    /// caculate the eulerian path
    if (_euler->eulerianPath(result, p_path_length)) {
      // print name one by one
      size_t i = 0;
      while (i < path_length) {
        _people->printNameById(result[i++]);
        printf(" -> ");
      }
      // meet the first node(people)
      _people->printNameById(result[0]);
      printf("\n");
    }

    delete[] result;
  }
}
