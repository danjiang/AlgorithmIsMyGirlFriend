//
// Created by Dan Jiang on 2020/7/23.
//

#include "gtest/gtest.h"

#include "binary_search2.h"

TEST(BinarySearch2, CountValueInSortedArray) {
  int array1[] = {1, 2, 3, 3, 3, 3, 4, 5};
  int count = CountValueInSortedArray(array1, 8, 3);
  EXPECT_EQ(count, 4);

  int array2[] = {3, 3, 3, 3, 4, 5};
  count = CountValueInSortedArray(array2, 6, 3);
  EXPECT_EQ(count, 4);

  int array3[] = {1, 2, 3, 3, 3, 3};
  count = CountValueInSortedArray(array3, 6, 3);
  EXPECT_EQ(count, 4);

  int array4[] = {1, 3, 3, 3, 3, 4, 5};
  EXPECT_THROW(CountValueInSortedArray(array4, 7, 2), not_found);
  EXPECT_THROW(CountValueInSortedArray(array4, 7, 0), not_found);
  EXPECT_THROW(CountValueInSortedArray(array4, 7, 6), not_found);

  int array5[] = {3, 3, 3, 3};
  count = CountValueInSortedArray(array5, 4, 3);
  EXPECT_EQ(count, 4);
  EXPECT_THROW(CountValueInSortedArray(array5, 4, 4), not_found);

  int array6[] = {3};
  count = CountValueInSortedArray(array6, 1, 3);
  EXPECT_EQ(count, 1);
  EXPECT_THROW(CountValueInSortedArray(array6, 1, 4), not_found);

  EXPECT_THROW(CountValueInSortedArray(nullptr, 0, 0), invalid_input);
}

TEST(BinarySearch2, FindMissingValueInSortedArray) {
  int array1[] = { 1, 2, 3, 4, 5 };
  int value = FindMissingValueInSortedArray(array1, 5);
  EXPECT_EQ(value, 0);

  int array2[] = { 0, 1, 2, 3, 4 };
  value = FindMissingValueInSortedArray(array2, 5);
  EXPECT_EQ(value, 5);

  int array3[] = { 0, 1, 2, 4, 5 };
  value = FindMissingValueInSortedArray(array3, 5);
  EXPECT_EQ(value, 3);

  int array4[] = { 1 };
  value = FindMissingValueInSortedArray(array4, 1);
  EXPECT_EQ(value, 0);

  int array5[] = { 0 };
  value = FindMissingValueInSortedArray(array5, 1);
  EXPECT_EQ(value, 1);

  EXPECT_THROW(FindMissingValueInSortedArray(nullptr, 0), invalid_input);
}

TEST(BinarySearch2, FindValueEqualIndexInSortedArray) {
  int array1[] = { -3, -1, 1, 3, 5 };
  int value = FindValueEqualIndexInSortedArray(array1, 5);
  EXPECT_EQ(value, 3);

  int array2[] = { 0, 1, 3, 5, 6 };
  value = FindValueEqualIndexInSortedArray(array2, 5);
  EXPECT_EQ(value, 0);

  int array3[] = { -1, 0, 1, 2, 4 };
  value = FindValueEqualIndexInSortedArray(array3, 5);
  EXPECT_EQ(value, 4);

  int array4[] = { -1, 0, 1, 2, 5 };
  EXPECT_THROW(FindValueEqualIndexInSortedArray(array4, 5), not_found);

  int array5[] = { 0 };
  value = FindValueEqualIndexInSortedArray(array5, 1);
  EXPECT_EQ(value, 0);

  int array6[] = { 10 };
  EXPECT_THROW(FindValueEqualIndexInSortedArray(array6, 1), not_found);

  EXPECT_THROW(FindValueEqualIndexInSortedArray(nullptr, 0), invalid_input);
}