//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "string_to_int.h"

TEST(StringToInt, DigitToInt) {
  EXPECT_THROW(DigitToInt(nullptr), invalid_input);
  EXPECT_THROW(DigitToInt(""), invalid_input);
  EXPECT_EQ(DigitToInt("123"), 123);
  EXPECT_EQ(DigitToInt("+123"), 123);
  EXPECT_EQ(DigitToInt("-123"), -123);
  EXPECT_THROW(DigitToInt("1a33"), invalid_input);
  EXPECT_EQ(DigitToInt("+0"), 0);
  EXPECT_EQ(DigitToInt("-0"), 0);
  EXPECT_EQ(DigitToInt("+2147483647"), 2147483647);
  EXPECT_EQ(DigitToInt("-2147483647"), -2147483647);
  EXPECT_THROW(DigitToInt("+2147483648"), invalid_input);
  EXPECT_EQ(DigitToInt("-2147483648"), -2147483648);
  EXPECT_THROW(DigitToInt("+2147483649"), invalid_input);
  EXPECT_THROW(DigitToInt("-2147483649"), invalid_input);
  EXPECT_THROW(DigitToInt("+"), invalid_input);
  EXPECT_THROW(DigitToInt("-"), invalid_input);
}

TEST(StringToInt, AlphaToInt) {
  EXPECT_EQ(AlphaToInt("A"), 1);
  EXPECT_EQ(AlphaToInt("B"), 2);
  EXPECT_EQ(AlphaToInt("Z"), 26);
  EXPECT_EQ(AlphaToInt("AA"), 27);
  EXPECT_EQ(AlphaToInt("AB"), 28);
  EXPECT_EQ(AlphaToInt("AAA"), 703);
  EXPECT_THROW(AlphaToInt("A1A"), invalid_input);
}