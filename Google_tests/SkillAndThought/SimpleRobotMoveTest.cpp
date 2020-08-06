//
// Created by Dan Jiang on 2020/8/6.
//

#include "gtest/gtest.h"

#include "simple_robot_move.h"

TEST(SimpleRobotMove, NormalCase) {
  EXPECT_EQ(SimpleRobotMove(10, 10, 5), 21);
  EXPECT_EQ(SimpleRobotMove(20, 20, 15), 359);
  EXPECT_EQ(SimpleRobotMove(1, 100, 10), 29);
  EXPECT_EQ(SimpleRobotMove(1, 10, 10), 10);
  EXPECT_EQ(SimpleRobotMove(100, 1, 15), 79);
  EXPECT_EQ(SimpleRobotMove(10, 1, 15), 10);
  EXPECT_EQ(SimpleRobotMove(1, 1, 15), 1);
  EXPECT_EQ(SimpleRobotMove(1, 1, 0), 1);
  EXPECT_THROW(SimpleRobotMove(10, 10, -10), invalid_input);
}