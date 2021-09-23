/**
 * @file          controller.cpp
 * @brief         implementation of Controller
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-05
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <controller.h>

namespace Assignment1 {
/**
 * @brief get pointer of Controller singleton instance
 * @return Controller*
 */
Controller *Controller::get_instance() {
  // using loacl static to ensure thread safety (c++11)
  static Controller singleton;
  singleton._people = singleton._people ?: new People();
  singleton._euler  = singleton._euler ?: new GraphMatrix();
  return &singleton;
}

/**
 * @brief parse main function parameters, and collect files infomation to class
 * People and class GraphMatrix
 * @param argc
 * @param argv
 */
void Controller::parse_files_info(int argc, const char **argv) {
  if (argc == 3 && argv[1] && argv[2]) {
    parsePath2Data(argv[1], PEOPLE_INSTANCE);
    parsePath2Data(argv[2], EULER_INSTANCE);
  } else {
    printf(
      "invalid parameters\nprogram works with two parameters: "
      "input path of \"people.txt\" and \"relationships.txt\", spilt with "
      "space\n");
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
      // print name one by one, assert(path_length == num_of_edge)
      size_t i = 0;
      while (i < path_length) {
        _people->printNameById(result[i++]);
        printf(" -> ");
      }
      // meet the first node(people)
      _people->printNameById(result[0]);
      printf("\n");
    } else {
      printf("No Eular Path (Circuit)\n");
    }

    delete[] result;
  }
}

}  // namespace Assignment1
