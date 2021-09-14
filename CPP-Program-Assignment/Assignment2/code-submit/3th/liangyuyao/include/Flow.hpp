#include <unordered_map>

#include "Grid.hpp"

enum class FlowStepType {
  kInit,
  kParseResources,
  kFindPath,
  kEnd,
};

class Flow {
 public:
  Flow(Flow&) = delete;
  static Flow& getInstance() {
    static Flow singleton;
    singleton.setStep(FlowStepType::kInit);
    return singleton;
  }
  FlowStepType getSetp() { return _step; }
  void doStepTask();

 private:
  Flow() = default;
  ~Flow() = default;
  void setStep(FlowStepType step) { _step = step; }
  void doTaskParseResourse();
  void doTaskFindPath(void (*)(Grid, Point, Point));

  FlowStepType _step;
  Grid _grid;
};