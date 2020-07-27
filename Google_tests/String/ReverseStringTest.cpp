//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "reverse_string.h"

TEST(ReverseString, ReverseSentence) {
  char input1[] = "I am a student.";
  char expected1[] = "student. a am I";
  EXPECT_STREQ(ReverseSentence(input1), expected1);
  char input2[] = "Wonderful";
  char expected2[] = "Wonderful";
  EXPECT_STREQ(ReverseSentence(input2), expected2);
  EXPECT_STREQ(ReverseSentence(nullptr), nullptr);
  char input3[] = "";
  char expected3[] = "";
  EXPECT_STREQ(ReverseSentence(input3), expected3);
  char input4[] = "   ";
  char expected4[] = "   ";
  EXPECT_STREQ(ReverseSentence(input4), expected4);
}

TEST(ReverseString, LeftRotateString) {
  char input1[] = "abcdefg";
  char expected1[] = "cdefgab";
  LeftRotateString(input1, 2);
  EXPECT_STREQ(input1, expected1);
  char input2[] = "abcdefg";
  char expected2[] = "bcdefga";
  LeftRotateString(input2, 1);
  EXPECT_STREQ(input2, expected2);
  char input3[] = "abcdefg";
  char expected3[] = "gabcdef";
  LeftRotateString(input3, 6);
  EXPECT_STREQ(input3, expected3);
  char input4[] = "abcdefg";
  char expected4[] = "abcdefg";
  LeftRotateString(input4, 0);
  EXPECT_STREQ(input4, expected4);
  char input5[] = "abcdefg";
  char expected5[] = "abcdefg";
  LeftRotateString(input5, 7);
  EXPECT_STREQ(input5, expected5);
}
