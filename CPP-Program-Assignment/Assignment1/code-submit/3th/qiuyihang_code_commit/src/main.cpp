/**
 * @file main.cpp
 * @brief The entry of this project.
 * @author YihangQiu (qiuyihang131@gmail.com)
 * @version 1.0
 * @date 2021-09-05
 *
 * @copyright Copyright (c) 2021  yhqiu
 *
 */
#include "euler.h"

int main(int argc, char *argv[]) {

  People people;
  Euler euler;
  int path_start_point;

  people.get_info();
  if (argc == 1) {
    printf("The default startpoint is: 0\n");
    path_start_point = 0;
  } else if (argc == 2 && 0 <= atoi(argv[1]) &&
             atoi(argv[1]) < people.get_people_size()) {
    path_start_point = atoi(argv[1]);
    printf("The startpoint is: %d\n", path_start_point);
  } else {
    printf("**********Input Error**********\n");
    printf("The correct input format is: ./solution [0-%d]\n",
           people.get_people_size() - 1);
    return 1;
  }

  if (euler.isEulerPath(people) == false) {
    printf("No Eular Path.\n");
  } else {
    euler.findEulerPath(people, path_start_point);
    euler.printEulerPath(people);
    euler.printPeoplePath(people);
  }
}
