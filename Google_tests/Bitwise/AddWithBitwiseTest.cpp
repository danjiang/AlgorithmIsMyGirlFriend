//
// Created by Dan Jiang on 2020/7/24.
//

#include "gtest/gtest.h"

#include "add_with_bitwise.h"

TEST(AddWithBitwise, NormalCase) {
  EXPECT_EQ(AddWithBitwise(1, 2), 3);
  EXPECT_EQ(AddWithBitwise(111, 899), 1010);
  EXPECT_EQ(AddWithBitwise(-1, 2), 1);
  EXPECT_EQ(AddWithBitwise(1, -2), -1);
  EXPECT_EQ(AddWithBitwise(3, 0), 3);
  EXPECT_EQ(AddWithBitwise(0, -4), -4);
  EXPECT_EQ(AddWithBitwise(-2, -8), -10);
}