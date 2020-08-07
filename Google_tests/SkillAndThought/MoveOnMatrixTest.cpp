//
// Created by Dan Jiang on 2020/8/7.
//

#include "gtest/gtest.h"

#include "move_on_matrix.h"

TEST(MoveOnMatrix, StatesCase) {
  int matrix1[] = { 1, 3, 5, 9,
                    2, 1, 3, 4,
                    5, 2, 6, 7,
                    6, 8, 4, 3};
  EXPECT_EQ(MoveOnMatrix(matrix1, 4), 19);
}

TEST(MoveOnMatrix, MemoCase) {
  int matrix1[] = { 1, 3, 5, 9,
                    2, 1, 3, 4,
                    5, 2, 6, 7,
                    6, 8, 4, 3};
  EXPECT_EQ(MoveOnMatrixMemo(matrix1, 4), 19);
}