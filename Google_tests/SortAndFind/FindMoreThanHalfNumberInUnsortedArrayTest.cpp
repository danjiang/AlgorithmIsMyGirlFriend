//
// Created by Dan Jiang on 2020/7/29.
//

#include "gtest/gtest.h"

#include "find_more_than_half_number_in_unsorted_array.h"

TEST(FindMoreThanHalfNumberInUnsortedArray, PartitionCase) {
  int array1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayPartition(array1, 9), 2);
  int array2[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
  EXPECT_THROW(FindMoreThanHalfNumberInUnsortedArrayPartition(array2, 9), invalid_input);
  int array3[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayPartition(array3, 9), 2);
  int array4[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayPartition(array4, 9), 2);
  int array5[] = {1};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayPartition(array5, 1), 1);
  EXPECT_THROW(FindMoreThanHalfNumberInUnsortedArrayPartition(nullptr, 0), invalid_input);
}

TEST(FindMoreThanHalfNumberInUnsortedArray, CountCase) {
  int array1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayCount(array1, 9), 2);
  int array2[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
  EXPECT_THROW(FindMoreThanHalfNumberInUnsortedArrayCount(array2, 9), invalid_input);
  int array3[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayCount(array3, 9), 2);
  int array4[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayCount(array4, 9), 2);
  int array5[] = {1};
  EXPECT_EQ(FindMoreThanHalfNumberInUnsortedArrayCount(array5, 1), 1);
  EXPECT_THROW(FindMoreThanHalfNumberInUnsortedArrayCount(nullptr, 0), invalid_input);
}