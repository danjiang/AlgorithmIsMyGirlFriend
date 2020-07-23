//
// Created by Dan Jiang on 2020/7/21.
//

#include "gtest/gtest.h"

#include "sqrt.h"

TEST(Sqrt, NormalCase) {
  std::cout << std::setprecision(6) << Sqrt(0.09, 0.000001) << std::endl;
  std::cout << std::fixed << Sqrt(64, 0.000001) << std::endl;
  std::cout << Sqrt(0.8, 0.000001) << std::endl;
  std::cout << Sqrt(7, 0.000001) << std::endl;
}