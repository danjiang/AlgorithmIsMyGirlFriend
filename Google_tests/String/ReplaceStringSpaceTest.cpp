//
// Created by Dan Jiang on 2020/8/4.
//

#include "gtest/gtest.h"

#include "replace_string_space.h"

TEST(ReplaceStringSpace, NormalCase) {
  const int capacity = 100;
  char input1[capacity] = "hello world";
  char expected1[] = "hello%20world";
  ReplaceStringSpace(input1, capacity);
  EXPECT_STREQ(input1, expected1);

  char input2[capacity] = " helloworld";
  char expected2[] = "%20helloworld";
  ReplaceStringSpace(input2, capacity);
  EXPECT_STREQ(input2, expected2);

  char input3[capacity] = "helloworld ";
  char expected3[] = "helloworld%20";
  ReplaceStringSpace(input3, capacity);
  EXPECT_STREQ(input3, expected3);

  char input4[capacity] = "hello  world";
  char expected4[] = "hello%20%20world";
  ReplaceStringSpace(input4, capacity);
  EXPECT_STREQ(input4, expected4);

  EXPECT_THROW(ReplaceStringSpace(nullptr, 0), invalid_input);

  char input5[capacity] = "";
  char expected5[] = "";
  ReplaceStringSpace(input5, capacity);
  EXPECT_STREQ(input5, expected5);

  char input6[capacity] = " ";
  char expected6[] = "%20";
  ReplaceStringSpace(input6, capacity);
  EXPECT_STREQ(input6, expected6);

  char input7[capacity] = "helloworld";
  char expected7[] = "helloworld";
  ReplaceStringSpace(input7, capacity);
  EXPECT_STREQ(input7, expected7);

  char input8[capacity] = "   ";
  char expected8[] = "%20%20%20";
  ReplaceStringSpace(input8, capacity);
  EXPECT_STREQ(input8, expected8);
}