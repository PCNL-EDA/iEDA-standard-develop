#include "Flow.hpp"

#include <assert.h>

void Flow::doStepTask() {
  switch (_step) {
    case FlowStepType::kInit:
      setStep(FlowStepType::kParseResources);
      break;
    case FlowStepType::kParseResources:
      doTaskParseResourse();
      break;
    default:
      assert(0);
  }
}

void Flow::doTaskParseResourse() {}