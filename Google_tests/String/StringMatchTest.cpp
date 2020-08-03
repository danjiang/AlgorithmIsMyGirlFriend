//
// Created by Dan Jiang on 2020/8/3.
//

#include "gtest/gtest.h"

#include "string_match.h"

TEST(StringMatch, BMCase) {
  char string1[] = "A new proof of the linearity of the Boyer-Moore string searching algorithm";
  char match1[] = "proof";
  EXPECT_EQ(StringMatchBM(string1, match1), 6);
  char match2[] = "the";
  EXPECT_EQ(StringMatchBM(string1, match2), 15);
  char match3[] = "good";
  EXPECT_THROW(StringMatchBM(string1, match3), not_found);

  char string2[] = "are designed to be efficient";
  char match4[] = "efficient";
  EXPECT_EQ(StringMatchBM(string2, match4), 19);
  char match5[] = "to";
  EXPECT_EQ(StringMatchBM(string2, match5), 13);
  char match6[] = "are";
  EXPECT_EQ(StringMatchBM(string2, match6), 0);
  char match7[] = "yes";
  EXPECT_THROW(StringMatchBM(string2, match7), not_found);
}

TEST(StringMatch, KMPCase) {
  char string1[] = "A new proof of the linearity of the Boyer-Moore string searching algorithm";
  char match1[] = "proof";
  EXPECT_EQ(StringMatchKMP(string1, match1), 6);
  char match2[] = "the";
  EXPECT_EQ(StringMatchKMP(string1, match2), 15);
  char match3[] = "good";
  EXPECT_THROW(StringMatchKMP(string1, match3), not_found);

  char string2[] = "are designed to be efficient";
  char match4[] = "efficient";
  EXPECT_EQ(StringMatchKMP(string2, match4), 19);
  char match5[] = "to";
  EXPECT_EQ(StringMatchKMP(string2, match5), 13);
  char match6[] = "are";
  EXPECT_EQ(StringMatchKMP(string2, match6), 0);
  char match7[] = "yes";
  EXPECT_THROW(StringMatchKMP(string2, match7), not_found);
}