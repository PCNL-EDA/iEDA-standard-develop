/**
 * @file        Flow.cpp
 * @brief
 * @author      liangyy (jerry9055@163.com)
 * @date        2021-09-16
 * @copyright   Copyright (c) 2021 PLAN-DROP_3th
 */
#include "Flow.hpp"

#include <assert.h>
#include <stdio.h>
#include <string.h>

namespace DROP_3TH_ASSIGNMENT2 {

void Flow::doStepTask() {
  switch (_step) {
    case FlowStepType::kInit:
      setStep(FlowStepType::kParseResources);
      break;
    case FlowStepType::kParseResources:
      doTaskParseResourse();
      setStep(FlowStepType::kFindPath);
      break;
    case FlowStepType::kFindPath:
      doTaskFindPath();
      setStep(FlowStepType::kEnd);
      break;
    default:
      assert(0);
  }
}

void Flow::doTaskParseResourse() {
  const char* file_path =
      "/home/liangyuyao/iEDA-standard-develop/CPP-Program-Assignment/"
      "Assignment2/code-submit/3th/liangyuyao/resources/grid.txt";
  FILE* fp = fopen(file_path, "r");
  if (fp) {
    const size_t buffer_size = 128;
    char buffer[buffer_size] = {0};

    // read the column size
    assert(fgets(buffer, sizeof(char) * buffer_size, fp) != nullptr);
    size_t col_num = 0;
    char* p = strtok(buffer, " ");
    while (p) {
      ++col_num;
      p = strtok(nullptr, " ");
    }
    fseek(fp, 0, SEEK_SET);
    _grid.releaseGrid();
    // build Grid2D
    std::vector<int> tmp;
    size_t row_col;
    while (!feof(fp)) {
      tmp.resize(0);
      row_col = 0;
      memset(buffer, 0, sizeof(char) * buffer_size);
      assert(fgets(buffer, sizeof(char) * buffer_size, fp) != nullptr);
      char* data = strtok(buffer, " ");
      while (data) {
        tmp.push_back(atoi(data));
        ++row_col;
        data = strtok(nullptr, " ");
      }
      assert(row_col == col_num);  // check grid whether a rectangle
      _grid.addRowData(tmp);
    }
  } else {
    printf("path invalid: %s\n", file_path);
  }
}

void Flow::doTaskFindPath() {
  if (_grid.isValid(_grid.getSrc().x, _grid.getSrc().y) == false) {
    printf("Source point is invalid\n");
    return;
  }

  if (_grid.isValid(_grid.getDst().x, _grid.getDst().y) == false) {
    printf("Destination  point is invalid\n");
    return;
  }

  if (_grid.isUnBlocked(_grid.getSrc().x, _grid.getSrc().y) == false ||
      _grid.isUnBlocked(_grid.getDst().x, _grid.getDst().y) == false) {
    printf("Source or the destination is blocked\n");
    return;
  }

  if (_grid.isDestination(_grid.getSrc())) {
    printf("We are already at the destination\n");
    return;
  }

  AStarSearch(_grid, _grid.getSrc(), _grid.getDst(), _heuristic);
}

}  // namespace DROP_3TH_ASSIGNMENT2
