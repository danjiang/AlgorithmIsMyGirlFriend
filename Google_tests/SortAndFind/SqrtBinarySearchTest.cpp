//
// Created by Dan Jiang on 2020/7/21.
//

#include "gtest/gtest.h"

#include "sqrt_binary_search.h"

TEST(SqrtBinarySearch, NormalData) {
  std::cout << std::setprecision(6) << SqrtBinarySearch(0.09, 0.000001) << std::endl;
  std::cout << std::fixed << SqrtBinarySearch(64, 0.000001) << std::endl;
  std::cout << SqrtBinarySearch(0.8, 0.000001) << std::endl;
  std::cout << SqrtBinarySearch(7, 0.000001) << std::endl;
}