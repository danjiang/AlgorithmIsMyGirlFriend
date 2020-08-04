//
// Created by Dan Jiang on 2020/8/4.
//

#include "gtest/gtest.h"

#include "translate_number_to_string.h"

TEST(CountTranslatedNumberToString, NormalCase) {
  EXPECT_EQ(CountTranslatedNumberToString(0), 1);
  EXPECT_EQ(CountTranslatedNumberToString(10), 2);
  EXPECT_EQ(CountTranslatedNumberToString(125), 3);
  EXPECT_EQ(CountTranslatedNumberToString(126), 2);
  EXPECT_EQ(CountTranslatedNumberToString(426), 1);
  EXPECT_EQ(CountTranslatedNumberToString(100), 2);
  EXPECT_EQ(CountTranslatedNumberToString(101), 2);
  EXPECT_EQ(CountTranslatedNumberToString(12258), 5);
  EXPECT_EQ(CountTranslatedNumberToString(-100), 0);
}