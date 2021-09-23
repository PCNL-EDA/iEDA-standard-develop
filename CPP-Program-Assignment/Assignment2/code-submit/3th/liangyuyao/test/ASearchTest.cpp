#include <time.h>

#include "AStarSearch.hpp"
#include "Flow.hpp"
#include "gtest/gtest.h"

using namespace DROP_3TH_ASSIGNMENT2;
TEST(AStarSearchTest, Diagonal) {
  time_t start = time(0);
  Flow& f_diagonal = Flow::getInstance(HeuristicType::kDiagonal);
  while (f_diagonal.getSetp() != FlowStepType::kEnd) {
    f_diagonal.doStepTask();
  }
  time_t end = time(0);
  printf("HeuristicType::kDiagonal, time = %lf\n", difftime(end, start));
}

TEST(AStarSearchTest, Manhattan) {
  time_t start = time(0);
  Flow& f_diagonal = Flow::getInstance(HeuristicType::kManhattan);
  while (f_diagonal.getSetp() != FlowStepType::kEnd) {
    f_diagonal.doStepTask();
  }
  time_t end = time(0);
  printf("HeuristicType::kManhattan, time = %lf\n", difftime(end, start));
}

TEST(AStarSearchTest, Euclidean) {
  time_t start = time(0);
  Flow& f_diagonal = Flow::getInstance(HeuristicType::kEuclidean);
  while (f_diagonal.getSetp() != FlowStepType::kEnd) {
    f_diagonal.doStepTask();
  }
  // sleep(3);
  time_t end = time(0);
  printf("HeuristicType::kEuclidean, time = %lf\n", difftime(end, start));
}