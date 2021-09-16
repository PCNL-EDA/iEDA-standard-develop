#include <stdio.h>

#include "AStarSearch.hpp"
#include "Flow.hpp"

using namespace DROP_3TH_ASSIGNMENT2;

int main(int argc, char** argv) {
  printf("\n----- Assignment2_pro -----\n");
  Flow& flow = Flow::getInstance(HeuristicType::kDiagonal);
  while (flow.getSetp() != FlowStepType::kEnd) {
    flow.doStepTask();
  }
  printf("\n----- Assignment2_pro END-----\n");
  return 0;
}