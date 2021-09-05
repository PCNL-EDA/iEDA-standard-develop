/**
 * @file          main.cpp
 * @brief         execution of Eulerian Path printing program.
 * @author        wanghao (harry0789@qq.com)
 * @date          2021-09-03
 * @copyright     Copyright (c) 2021 PCL IEDA
 */
#include <controller.h>

int main(int argc, const char **argv) {
  Controller *step = Controller::getInstance();

  step->printHelpMessages();
  step->parseFilesInfo(argc, argv);
  step->printALL();
  step->printEulerianPath();
  step->exitProgram(EXIT_SUCCESS);
}