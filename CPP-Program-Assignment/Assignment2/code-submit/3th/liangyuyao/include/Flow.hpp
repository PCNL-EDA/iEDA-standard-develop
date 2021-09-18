/**
 * @file        Flow.hpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#ifndef __FLOW_HPP_
#define __FLOW_HPP_

#include "AStarSearch.hpp"
#include "Grid.hpp"

namespace DROP_3TH_ASSIGNMENT2 {

enum class FlowStepType {
  kInit,
  kParseResources,
  kFindPath,
  kEnd,
};

class Flow {
 public:
  Flow(Flow&) = delete;
  /**
   * @brief       singleton model
   *
   * @param       h choose which Heuristic function to apply to A_Star_Search
   * @return      Flow& 
   * @exception
   */
  static Flow& getInstance(HeuristicType h) {
    static Flow singleton;
    singleton.setStep(FlowStepType::kInit);
    singleton.setHeuristicType(h);
    return singleton;
  }

  const FlowStepType getSetp() const { return _step; }
  const HeuristicType getHeuristicType() const { return _heuristic; }

  void doStepTask();

 private:
  Flow() = default;
  ~Flow() = default;

  void setStep(FlowStepType step) { _step = step; }
  void setHeuristicType(HeuristicType h) { _heuristic = h; }

  void doTaskParseResourse();
  void doTaskFindPath();

  FlowStepType _step;
  Grid _grid;
  HeuristicType _heuristic;
};

}  // namespace DROP_3TH_ASSIGNMENT2
#endif