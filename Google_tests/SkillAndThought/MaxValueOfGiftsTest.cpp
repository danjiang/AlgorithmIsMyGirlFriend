//
// Created by Dan Jiang on 2020/8/9.
//

#include "gtest/gtest.h"

#include "max_value_of_gifts.h"

TEST(MaxValueOfGifts, NormalCase) {
  int matrix1[] = {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
  };
  EXPECT_EQ(MaxValueOfGifts(matrix1, 3, 3), 29);

  int matrix2[] = {
      1, 10, 3, 8,
      12, 2, 9, 6,
      5, 7, 4, 11,
      3, 7, 16, 5
  };
  EXPECT_EQ(MaxValueOfGifts(matrix2, 4, 4), 53);

  int matrix3[] = {
      1, 10, 3, 8
  };
  EXPECT_EQ(MaxValueOfGifts(matrix3, 1, 4), 22);

  int matrix4[] = {
      1,
      12,
      5,
      3
  };
  EXPECT_EQ(MaxValueOfGifts(matrix4, 4, 1), 21);

  int matrix5[] = {
      3
  };
  EXPECT_EQ(MaxValueOfGifts(matrix5, 1, 1), 3);

  EXPECT_EQ(MaxValueOfGifts(nullptr, 0, 0), -1);
}
