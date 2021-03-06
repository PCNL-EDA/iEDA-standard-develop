/**
 * @file        main.cpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-03
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */

#include <stdio.h>

#include <vector>

#include "DirectedGraph.hpp"
#include "EulerGraph.h"
#include "Resources.hpp"

using namespace DROP_3th_ASSIGNMENT1;

int main(int argc, char** argv) {
  printf("\n----- Assignment1_pro -----\n");
  EulerGraph::printEulerCircuit();
  printf("\n----- Assignment1_pro END-----\n");
  return 0;
}