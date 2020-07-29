//
// Created by Dan Jiang on 2020/7/29.
//

#include "gtest/gtest.h"

#include "find_min_kth_in_unsorted_array.h"
#include "array_util.h"

TEST(FindMinKthInUnsortedArray, NormalCase) {
  int k1 = 4;
  int data1[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int *output1 = new int[k1];
  int expected1[] = {1, 2, 3, 4};
  FindMinKthInUnsortedArray(k1, data1, sizeof(data1) / sizeof(int), output1);
  EXPECT_TRUE(IsSameArray(output1, expected1, k1));
  delete[] output1;

  int k2 = 8;
  int *output2 = new int[k2];
  int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8};
  FindMinKthInUnsortedArray(k2, data1, sizeof(data1) / sizeof(int), output2);
  EXPECT_TRUE(IsSameArray(output2, expected2, k2));
  delete[] output2;

  int k3 = 1;
  int *output3 = new int[k3];
  int expected3[] = {1};
  FindMinKthInUnsortedArray(k3, data1, sizeof(data1) / sizeof(int), output3);
  EXPECT_TRUE(IsSameArray(output3, expected3, k3));
  delete[] output3;

  int *output4 = new int[1];
  EXPECT_THROW(FindMinKthInUnsortedArray(10, data1, sizeof(data1) / sizeof(int), output4), invalid_input);
  EXPECT_THROW(FindMinKthInUnsortedArray(0, data1, sizeof(data1) / sizeof(int), output4), invalid_input);
  delete[] output4;

  int k5 = 2;
  int *output5 = new int[k5];
  int expected5[] = {1, 2};
  FindMinKthInUnsortedArray(k5, data1, sizeof(data1) / sizeof(int), output5);
  EXPECT_TRUE(IsSameArray(output5, expected5, k5));
  delete[] output5;

  EXPECT_THROW(FindMinKthInUnsortedArray(0, nullptr, 0, nullptr), invalid_input);
}