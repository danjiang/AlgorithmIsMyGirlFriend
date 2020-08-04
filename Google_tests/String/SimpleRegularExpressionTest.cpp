//
// Created by Dan Jiang on 2020/8/4.
//

#include "gtest/gtest.h"

#include "simple_regular_expression.h"

TEST(SimpleRegularExpression, NormalCase) {
  char string1[] = "";
  char pattern1[] = "";
  EXPECT_TRUE(SimpleRegularExpression(string1, pattern1));
  char string2[] = "";
  char pattern2[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string2, pattern2));
  char string3[] = "";
  char pattern3[] = ".";
  EXPECT_FALSE(SimpleRegularExpression(string3, pattern3));
  char string4[] = "";
  char pattern4[] = "c*";
  EXPECT_TRUE(SimpleRegularExpression(string4, pattern4));
  char string5[] = "a";
  char pattern5[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string5, pattern5));
  char string6[] = "a";
  char pattern6[] = "a.";
  EXPECT_FALSE(SimpleRegularExpression(string6, pattern6));
  char string7[] = "a";
  char pattern7[] = "";
  EXPECT_FALSE(SimpleRegularExpression(string7, pattern7));
  char string8[] = "a";
  char pattern8[] = ".";
  EXPECT_TRUE(SimpleRegularExpression(string8, pattern8));
  char string9[] = "a";
  char pattern9[] = "ab*";
  EXPECT_TRUE(SimpleRegularExpression(string9, pattern9));
  char string10[] = "a";
  char pattern10[] = "ab*a";
  EXPECT_FALSE(SimpleRegularExpression(string10, pattern10));
  char string11[] = "aa";
  char pattern11[] = "aa";
  EXPECT_TRUE(SimpleRegularExpression(string11, pattern11));
  char string12[] = "aa";
  char pattern12[] = "a*";
  EXPECT_TRUE(SimpleRegularExpression(string12, pattern12));
  char string13[] = "aa";
  char pattern13[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string13, pattern13));
  char string14[] = "aa";
  char pattern14[] = ".";
  EXPECT_FALSE(SimpleRegularExpression(string14, pattern14));
  char string15[] = "aa";
  char pattern15[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string15, pattern15));
  char string16[] = "ab";
  char pattern16[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string16, pattern16));
  char string17[] = "aaa";
  char pattern17[] = "aa*";
  EXPECT_TRUE(SimpleRegularExpression(string17, pattern17));
  char string18[] = "aaa";
  char pattern18[] = "aa.a";
  EXPECT_FALSE(SimpleRegularExpression(string18, pattern18));
  char string19[] = "aaa";
  char pattern19[] = "a.a";
  EXPECT_TRUE(SimpleRegularExpression(string19, pattern19));
  char string20[] = "aaa";
  char pattern20[] = ".a";
  EXPECT_FALSE(SimpleRegularExpression(string20, pattern20));
  char string21[] = "aaa";
  char pattern21[] = "a*a";
  EXPECT_TRUE(SimpleRegularExpression(string21, pattern21));
  char string22[] = "aaa";
  char pattern22[] = "ab*a";
  EXPECT_FALSE(SimpleRegularExpression(string22, pattern22));
  char string23[] = "aaa";
  char pattern23[] = "ab*ac*a";
  EXPECT_TRUE(SimpleRegularExpression(string23, pattern23));
  char string24[] = "aaa";
  char pattern24[] = "ab*a*c*a";
  EXPECT_TRUE(SimpleRegularExpression(string24, pattern24));
  char string25[] = "aaa";
  char pattern25[] = ".*";
  EXPECT_TRUE(SimpleRegularExpression(string25, pattern25));
  char string26[] = "aab";
  char pattern26[] = "c*a*b";
  EXPECT_TRUE(SimpleRegularExpression(string26, pattern26));
  char string27[] = "aaca";
  char pattern27[] = "ab*a*c*a";
  EXPECT_TRUE(SimpleRegularExpression(string27, pattern27));
  char string28[] = "aaba";
  char pattern28[] = "ab*a*c*a";
  EXPECT_FALSE(SimpleRegularExpression(string28, pattern28));
  char string29[] = "bbbba";
  char pattern29[] = ".*a*a";
  EXPECT_TRUE(SimpleRegularExpression(string29, pattern29));
  char string30[] = "bcbbabab";
  char pattern30[] = ".*a*a";
  EXPECT_FALSE(SimpleRegularExpression(string30, pattern30));
}
