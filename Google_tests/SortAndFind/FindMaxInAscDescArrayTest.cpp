//
// Created by Dan Jiang on 2020/9/8.
//

#include "gtest/gtest.h"

#include "find_max_in_asc_desc_array.h"

TEST(FindMaxInAscDescArray, NormalCase) {
  int array1[] = { 1, 2, 4, 5, 7, 9, 8, 6, 3 };
  EXPECT_EQ(FindMaxInAscDescArray(array1, sizeof(array1) / sizeof(int)), 5);

  int array2[] = { 4, 8, 2 };
  EXPECT_EQ(FindMaxInAscDescArray(array2, sizeof(array2) / sizeof(int)), 1);

  int array3[] = { 1, 4, 5 };
  EXPECT_EQ(FindMaxInAscDescArray(array3, sizeof(array3) / sizeof(int)), -1);

  int array4[] = { 4, 1 };
  EXPECT_EQ(FindMaxInAscDescArray(array4, sizeof(array4) / sizeof(int)), -1);

  int array5[] = { 1, 2, 9, 6 };
  EXPECT_EQ(FindMaxInAscDescArray(array5, sizeof(array5) / sizeof(int)), 2);
}