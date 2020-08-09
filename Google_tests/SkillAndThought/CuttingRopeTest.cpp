//
// Created by Dan Jiang on 2020/8/9.
//

#include "gtest/gtest.h"

#include "cutting_rope.h"

TEST(CuttingRope, DPStatesCase) {
  EXPECT_EQ(CuttingRopeDPStates(1), 0);
  EXPECT_EQ(CuttingRopeDPStates(2), 1);
  EXPECT_EQ(CuttingRopeDPStates(3), 2);
  EXPECT_EQ(CuttingRopeDPStates(4), 4);
  EXPECT_EQ(CuttingRopeDPStates(5), 6);
  EXPECT_EQ(CuttingRopeDPStates(6), 9);
  EXPECT_EQ(CuttingRopeDPStates(7), 12);
  EXPECT_EQ(CuttingRopeDPStates(8), 18);
  EXPECT_EQ(CuttingRopeDPStates(9), 27);
  EXPECT_EQ(CuttingRopeDPStates(10), 36);
  EXPECT_EQ(CuttingRopeDPStates(50), 86093442);
}

TEST(CuttingRope, GreedyCase) {
  EXPECT_EQ(CuttingRopeGreedy(1), 0);
  EXPECT_EQ(CuttingRopeGreedy(2), 1);
  EXPECT_EQ(CuttingRopeGreedy(3), 2);
  EXPECT_EQ(CuttingRopeGreedy(4), 4);
  EXPECT_EQ(CuttingRopeGreedy(5), 6);
  EXPECT_EQ(CuttingRopeGreedy(6), 9);
  EXPECT_EQ(CuttingRopeGreedy(7), 12);
  EXPECT_EQ(CuttingRopeGreedy(8), 18);
  EXPECT_EQ(CuttingRopeGreedy(9), 27);
  EXPECT_EQ(CuttingRopeGreedy(10), 36);
  EXPECT_EQ(CuttingRopeGreedy(50), 86093442);
}