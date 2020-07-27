//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "char_hash_table.h"

TEST(CharHashTable, FindFirstNotRepeatChar) {
  std::string string = "google";
  EXPECT_EQ(FindFirstNotRepeatChar(string.c_str()), 'l');
  string = "aabccdbd";
  EXPECT_EQ(FindFirstNotRepeatChar(string.c_str()), '\0');
  string = "abcdefg";
  EXPECT_EQ(FindFirstNotRepeatChar(string.c_str()), 'a');
  EXPECT_EQ(FindFirstNotRepeatChar(nullptr), '\0');
}

TEST(CharHashTable, CharStatistics) {
  CharStatistics chars;

  EXPECT_EQ(chars.FirstAppearingOnce(), '\0');
  chars.Insert('g');
  EXPECT_EQ(chars.FirstAppearingOnce(), 'g');
  chars.Insert('o');
  EXPECT_EQ(chars.FirstAppearingOnce(), 'g');
  chars.Insert('o');
  EXPECT_EQ(chars.FirstAppearingOnce(), 'g');
  chars.Insert('g');
  EXPECT_EQ(chars.FirstAppearingOnce(), '\0');
  chars.Insert('l');
  EXPECT_EQ(chars.FirstAppearingOnce(), 'l');
  chars.Insert('e');
  EXPECT_EQ(chars.FirstAppearingOnce(), 'l');
}