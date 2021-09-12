enum class FlowStepType {
  kInit,
  kParseResources,
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
  FlowStepType _step;
};