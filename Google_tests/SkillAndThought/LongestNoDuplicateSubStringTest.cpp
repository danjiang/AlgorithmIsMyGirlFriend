//
// Created by Dan Jiang on 2020/8/9.
//


#include "gtest/gtest.h"

#include "longest_no_duplicate_substring.h"

TEST(LongestNoDuplicateSubString, NormalCase) {
  char string1[] = "abcacfrar";
  EXPECT_EQ(LongestNoDuplicateSubString(string1), 4);
  char string2[] = "acfrarabc";
  EXPECT_EQ(LongestNoDuplicateSubString(string2), 4);
  char string3[] = "arabcacfr";
  EXPECT_EQ(LongestNoDuplicateSubString(string3), 4);
  char string4[] = "aaaa";
  EXPECT_EQ(LongestNoDuplicateSubString(string4), 1);
  char string5[] = "abcdefg";
  EXPECT_EQ(LongestNoDuplicateSubString(string5), 7);
  char string6[] = "aaabbbccc";
  EXPECT_EQ(LongestNoDuplicateSubString(string6), 2);
  char string7[] = "abcdcba";
  EXPECT_EQ(LongestNoDuplicateSubString(string7), 4);
  char string8[] = "abcdaef";
  EXPECT_EQ(LongestNoDuplicateSubString(string8), 6);
  char string9[] = "a";
  EXPECT_EQ(LongestNoDuplicateSubString(string9), 1);
  char string10[] = "";
  EXPECT_EQ(LongestNoDuplicateSubString(string10), 0);
}