//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "find_number_of_matrix.h"

TEST(FindNumberOfMatrix, NormalCase) {
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
  int matrix1[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  EXPECT_TRUE(FindNumberOfMatrix((int*)matrix1, 4, 4, 7));
  EXPECT_FALSE(FindNumberOfMatrix((int*)matrix1, 4, 4, 5));
  EXPECT_TRUE(FindNumberOfMatrix((int*)matrix1, 4, 4, 1));
  EXPECT_TRUE(FindNumberOfMatrix((int*)matrix1, 4, 4, 15));
  EXPECT_FALSE(FindNumberOfMatrix((int*)matrix1, 4, 4, 0));
  EXPECT_FALSE(FindNumberOfMatrix((int*)matrix1, 4, 4, 16));
  EXPECT_FALSE(FindNumberOfMatrix(nullptr, 0, 0, 16));
}
