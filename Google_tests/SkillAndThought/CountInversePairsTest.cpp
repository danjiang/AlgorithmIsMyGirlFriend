//
// Created by Dan Jiang on 2020/8/5.
//

#include "gtest/gtest.h"

#include "count_inverse_pairs.h"

TEST(CountInversePairs, NormalCase) {
  int array1[] = {1, 2, 3, 4, 7, 6, 5};
  EXPECT_EQ(CountInversePairs(array1, 7), 3);
  int array2[] = {6, 5, 4, 3, 2, 1};
  EXPECT_EQ(CountInversePairs(array2, 6), 15);
  int array3[] = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(CountInversePairs(array3, 6), 0);
  int array4[] = {1};
  EXPECT_EQ(CountInversePairs(array4, 1), 0);
  int array5[] = {1, 2};
  EXPECT_EQ(CountInversePairs(array5, 2), 0);
  int array6[] = {2, 1};
  EXPECT_EQ(CountInversePairs(array6, 2), 1);
  int array7[] = {1, 2, 1, 2, 1};
  EXPECT_EQ(CountInversePairs(array7, 5), 3);
  EXPECT_EQ(CountInversePairs(nullptr, 0), 0);
}