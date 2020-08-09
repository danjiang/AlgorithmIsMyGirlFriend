//
// Created by Dan Jiang on 2020/8/9.
//

#include "gtest/gtest.h"

#include "max_sum_sub_array.h"

TEST(MaxSumSubArray, NormalCase) {
  int array1[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
  EXPECT_EQ(MaxSumSubArray(array1, sizeof(array1) / sizeof(int)), 18);

  int array2[] = { -2, -8, -1, -5, -9 };
  EXPECT_EQ(MaxSumSubArray(array2, sizeof(array2) / sizeof(int)), -1);

  int array3[] = { 2, 8, 1, 5, 9 };
  EXPECT_EQ(MaxSumSubArray(array3, sizeof(array3) / sizeof(int)), 25);

  EXPECT_THROW(MaxSumSubArray(nullptr, 0), invalid_input);
}
