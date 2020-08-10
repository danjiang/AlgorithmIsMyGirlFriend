//
// Created by Dan Jiang on 2020/8/10.
//

#include "gtest/gtest.h"

#include "josephuse_circle.h"

TEST(JosephuseCircle, NormalCase) {
  EXPECT_EQ(JosephuseCircle(5, 3), 3);
  EXPECT_EQ(JosephuseCircle(5, 2), 2);
  EXPECT_EQ(JosephuseCircle(6, 7), 4);
  EXPECT_EQ(JosephuseCircle(6, 6), 3);
  EXPECT_EQ(JosephuseCircle(4000, 997), 1027);
  EXPECT_THROW(JosephuseCircle(0, 0), invalid_input);
}