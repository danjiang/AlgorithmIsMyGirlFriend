//
// Created by Dan Jiang on 2020/8/8.
//

#include "gtest/gtest.h"

#include "find_longest_add_one_subsequence.h"

TEST(FindLongestAddOneSubsequence, NormalCase) {
  int offset = 0;
  int length = 0;

  int array1[] = { 1, 5, 3, 4, 10, 7, 8, 9, 20, 21, 11, 12, 13, 14, 15, 22 };
  int size1 = int(sizeof(array1) / sizeof(array1[0]));
  FindLongestAddOneSubsequence(array1, size1, &offset, &length);
  EXPECT_EQ(offset, 10);
  EXPECT_EQ(length, 5);

  int array2[] = { 1, 3, 4, 6, 7, 8, 9, 20, 21, 10, 11, 12, 13, 14, 15 };
  int size2 = int(sizeof(array2) / sizeof(array2[0]));
  FindLongestAddOneSubsequence(array2, size2, &offset, &length);
  EXPECT_EQ(offset, 9);
  EXPECT_EQ(length, 6);

  int array3[] = { 2 };
  FindLongestAddOneSubsequence(array3, 1, &offset, &length);
  EXPECT_EQ(offset, 0);
  EXPECT_EQ(length, 1);

  EXPECT_THROW(FindLongestAddOneSubsequence(nullptr, 0, &offset, &length), invalid_input);
}