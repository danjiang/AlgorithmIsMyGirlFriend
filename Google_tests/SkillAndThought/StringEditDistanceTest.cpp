//
// Created by Dan Jiang on 2020/8/8.
//

#include "gtest/gtest.h"

#include "string_edit_distance.h"

TEST(StringEditDistance, LevenshteinDistanceCase) {
  char string11[] = "kitten";
  char string12[] = "sitting";
  EXPECT_EQ(LevenshteinDistance(string11, string12), 3);

  char string21[] = "Saturday";
  char string22[] = "Sunday";
  EXPECT_EQ(LevenshteinDistance(string21, string22), 3);

  char string31[] = "benyam";
  char string32[] = "ephrem";
  EXPECT_EQ(LevenshteinDistance(string31, string32), 5);

  char string41[] = "mtacnu";
  char string42[] = "mitcmu";
  EXPECT_EQ(LevenshteinDistance(string41, string42), 3);
}

TEST(StringEditDistance, LongestCommonSubsequenceCase) {
  char string11[] = "AGCAT";
  char string12[] = "GAC";
  EXPECT_EQ(LongestCommonSubsequence(string11, string12), 2);

  char string21[] = "MZJAWXU";
  char string22[] = "XMJYAUZ";
  EXPECT_EQ(LongestCommonSubsequence(string21, string22), 4);

  char string31[] = "AGGTAB";
  char string32[] = "GXTXAYB";
  EXPECT_EQ(LongestCommonSubsequence(string31, string32), 4);

  char string41[] = "mtacnu";
  char string42[] = "mitcmu";
  EXPECT_EQ(LongestCommonSubsequence(string41, string42), 4);
}