//
// Created by Dan Jiang on 2020/8/20.
//

#include "gtest/gtest.h"

#include "simple_compress_string.h"

TEST(SimpleCompressString, NormalCase) {
  char output[10];

  char input1[] = "aabccccaaa";
  char expect1[] = "a2bc4a3";
  SimpleCompressString(input1, output);
  EXPECT_STREQ(output, expect1);

  char input2[] = "a";
  char expect2[] = "a";
  SimpleCompressString(input2, output);
  EXPECT_STREQ(output, expect2);

  char input3[] = "aa";
  char expect3[] = "a2";
  SimpleCompressString(input3, output);
  EXPECT_STREQ(output, expect3);

  char input4[] = "ab";
  char expect4[] = "ab";
  SimpleCompressString(input4, output);
  EXPECT_STREQ(output, expect4);

  char input5[] = "eeeeeaaaffeee";
  char expect5[] = "e5a3f2e3";
  SimpleCompressString(input5, output);
  EXPECT_STREQ(output, expect5);
}
