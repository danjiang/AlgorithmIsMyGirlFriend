//
// Created by Dan Jiang on 2020/7/21.
//

#include "gtest/gtest.h"

#include "array_util.h"
#include "counting_sort.h"

TEST(CountingSort, NormalData) {
  int unsorted_array[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
  int sorted_array[] = { 0, 0, 2, 2, 3, 3, 3, 5 };
  int size = 8;
  CountingSort(unsorted_array, size);
  IsSameArray(unsorted_array, sorted_array, size);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}