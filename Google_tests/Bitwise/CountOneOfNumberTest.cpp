//
// Created by Dan Jiang on 2020/7/24.
//

#include "gtest/gtest.h"

#include "count_one_of_number.h"

TEST(CountOneOfNumber, Normal) {
  EXPECT_EQ(CountOneOfNumberNormal(0), 0);
  EXPECT_EQ(CountOneOfNumberNormal(1), 1);
  EXPECT_EQ(CountOneOfNumberNormal(10), 2);
  EXPECT_EQ(CountOneOfNumberNormal(0x7FFFFFFF), 31);
  EXPECT_EQ(CountOneOfNumberNormal(0xFFFFFFFF), 32);
  EXPECT_EQ(CountOneOfNumberNormal(0x80000000), 1);
}

TEST(CountOneOfNumber, Best) {
  EXPECT_EQ(CountOneOfNumberBest(0), 0);
  EXPECT_EQ(CountOneOfNumberBest(1), 1);
  EXPECT_EQ(CountOneOfNumberBest(10), 2);
  EXPECT_EQ(CountOneOfNumberBest(0x7FFFFFFF), 31);
  EXPECT_EQ(CountOneOfNumberBest(0xFFFFFFFF), 32);
  EXPECT_EQ(CountOneOfNumberBest(0x80000000), 1);
}