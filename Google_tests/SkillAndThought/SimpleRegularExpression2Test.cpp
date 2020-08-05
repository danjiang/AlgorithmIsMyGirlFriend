//
// Created by Dan Jiang on 2020/8/5.
//

#include "gtest/gtest.h"

#include "simple_regular_expression2.h"

TEST(SimpleRegularExpression2, NormalCase) {
  char string1[] = "";
  char pattern1[] = "";
  EXPECT_TRUE(SimpleRegularExpression2(string1, pattern1));
  char string2[] = "";
  char pattern2[] = "*";
  EXPECT_TRUE(SimpleRegularExpression2(string2, pattern2));
  char string3[] = "a";
  char pattern3[] = "*";
  EXPECT_TRUE(SimpleRegularExpression2(string3, pattern3));
  char string4[] = "ab";
  char pattern4[] = "*";
  EXPECT_TRUE(SimpleRegularExpression2(string4, pattern4));
  char string5[] = "";
  char pattern5[] = "?";
  EXPECT_TRUE(SimpleRegularExpression2(string5, pattern5));
  char string6[] = "a";
  char pattern6[] = "?";
  EXPECT_TRUE(SimpleRegularExpression2(string6, pattern6));
  char string7[] = "a";
  char pattern7[] = "a*";
  EXPECT_TRUE(SimpleRegularExpression2(string7, pattern7));
  char string8[] = "ab";
  char pattern8[] = "a*";
  EXPECT_TRUE(SimpleRegularExpression2(string8, pattern8));
  char string9[] = "abc";
  char pattern9[] = "a*";
  EXPECT_TRUE(SimpleRegularExpression2(string9, pattern9));
  char string10[] = "a";
  char pattern10[] = "a?";
  EXPECT_TRUE(SimpleRegularExpression2(string10, pattern10));
  char string11[] = "ab";
  char pattern11[] = "a?";
  EXPECT_TRUE(SimpleRegularExpression2(string11, pattern11));
  char string12[] = "ab";
  char pattern12[] = "ab";
  EXPECT_TRUE(SimpleRegularExpression2(string12, pattern12));
  char string13[] = "abc";
  char pattern13[] = "abc";
  EXPECT_TRUE(SimpleRegularExpression2(string13, pattern13));
  char string14[] = "c";
  char pattern14[] = "*c";
  EXPECT_TRUE(SimpleRegularExpression2(string14, pattern14));
  char string15[] = "bc";
  char pattern15[] = "*c";
  EXPECT_TRUE(SimpleRegularExpression2(string15, pattern15));
  char string16[] = "b";
  char pattern16[] = "?b";
  EXPECT_TRUE(SimpleRegularExpression2(string16, pattern16));
  char string17[] = "ab";
  char pattern17[] = "?b";
  EXPECT_TRUE(SimpleRegularExpression2(string17, pattern17));
  char string18[] = "ab";
  char pattern18[] = "*c";
  EXPECT_FALSE(SimpleRegularExpression2(string18, pattern18));
  char string19[] = "a";
  char pattern19[] = "?c";
  EXPECT_FALSE(SimpleRegularExpression2(string19, pattern19));
  char string20[] = "abc";
  char pattern20[] = "abd";
  EXPECT_FALSE(SimpleRegularExpression2(string20, pattern20));
}
