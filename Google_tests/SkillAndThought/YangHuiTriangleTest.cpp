//
// Created by Dan Jiang on 2020/8/7.
//

#include "gtest/gtest.h"

#include "yang_hui_triangle.h"

TEST(YangHuiTriangle, NormalCase) {
  int triangle1[] = { 5, 8, 4, 1, 5,
                      7, 3, 6, 4, 0,
                      2, 9, 9, 0, 0,
                      4, 7, 0, 0, 0,
                      2, 0, 0, 0, 0};
  EXPECT_EQ(YangHuiTriangle(triangle1, 5), 20);
}