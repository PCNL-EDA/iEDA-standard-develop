#include <gtest/gtest.h>

#include "EulerGraph.h"
using namespace DROP_3th_ASSIGNMENT1;

TEST(Print_Euler_Circuit, Check_Result) {
  std::string result = EulerGraph::printEulerCircuit();
  std::string expect =
      "Eular Circuit: Bassel -> sam -> Farnes -> Baheye -> Bassel -> "
      "Sawsan -> Thuraya -> abes -> Farnes -> Thuraya -> Bassel ";
  EXPECT_EQ(result, expect) << "result:\n" << result;
}