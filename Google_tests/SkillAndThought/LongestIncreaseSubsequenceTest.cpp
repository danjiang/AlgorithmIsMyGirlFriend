//
// Created by Dan Jiang on 2020/8/8.
//

#include "gtest/gtest.h"

#include "longest_increase_subsequence.h"

TEST(LongestIncreaseSubsequence, NormalCase) {
  int array1[] = { 2, 9, 3, 6, 5, 1, 7 };
  EXPECT_EQ(LongestIncreaseSubsequence(array1, 7), 4);

  int array2[] = { 5, 6, 7, 1, 2, 8 };
  EXPECT_EQ(LongestIncreaseSubsequence(array2, 6), 4);

  int array3[] = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
  EXPECT_EQ(LongestIncreaseSubsequence(array3, 9), 5);
}
