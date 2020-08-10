//
// Created by Dan Jiang on 2020/8/10.
//

#include "gtest/gtest.h"

#include "sum_of_numbers.h"

TEST(SumOfNumbers, TwoNumbersCase) {
  int a = 0;
  int b = 0;

  int array1[] = {1, 2, 4, 7, 11, 15};
  SumTwoNumbersOfArray(array1, sizeof(array1) / sizeof(int), 15, &a, &b);
  EXPECT_EQ(a, 4);
  EXPECT_EQ(b, 11);

  int array2[] = {1, 2, 4, 7, 11, 16};
  SumTwoNumbersOfArray(array2, sizeof(array2) / sizeof(int), 17, &a, &b);
  EXPECT_EQ(a, 1);
  EXPECT_EQ(b, 16);

  EXPECT_THROW(SumTwoNumbersOfArray(array2, sizeof(array2) / sizeof(int), 10, &a, &b), not_found);

  EXPECT_THROW(SumTwoNumbersOfArray(nullptr, 0, 0, &a, &b), invalid_input);
}

TEST(SumOfNumbers, SequenceCase) {
  EXPECT_THROW(FindSumSequence(1), invalid_input);
  FindSumSequence(3);
  FindSumSequence(4);
  FindSumSequence(9);
  FindSumSequence(15);
  FindSumSequence(100);
}