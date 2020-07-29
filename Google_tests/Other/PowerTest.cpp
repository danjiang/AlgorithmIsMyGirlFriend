//
// Created by Dan Jiang on 2020/7/29.
//

#include "gtest/gtest.h"

#include "power.h"

TEST(Power, NormalCase) {
  EXPECT_DOUBLE_EQ(Power(2, 3), 8);
  EXPECT_DOUBLE_EQ(Power(-2, 3), -8);
  EXPECT_DOUBLE_EQ(Power(2, -3), 0.125);
  EXPECT_DOUBLE_EQ(Power(2, 0), 1);
  EXPECT_DOUBLE_EQ(Power(0, 4), 0);
  EXPECT_THROW(Power(0, 0), invalid_input);
  EXPECT_THROW(Power(0, -4), invalid_input);
}