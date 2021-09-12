#include <stdio.h>

#include "Flow.hpp"

int main(int argc, char** argv) {
  printf("\n----- Assignment2_pro -----\n");
  Flow& flow = Flow::getInstance();
  while (flow.getSetp() != FlowStepType::kEnd) {
    flow.doStepTask();
  }
  printf("\n----- Assignment2_pro END-----\n");
  return 0;
}