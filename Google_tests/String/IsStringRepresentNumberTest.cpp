//
// Created by Dan Jiang on 2020/7/29.
//

#include "gtest/gtest.h"

#include "is_string_represent_number.h"

TEST(IsStringRepresentNumber, NormalCase) {
  std::string string = "100";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "123.45e+6";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "+500";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "5e2";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "3.1416";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "600";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "-.123";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "-1E-16";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));
  string = "1.79769313486232E+308";
  EXPECT_TRUE(IsStringRepresentNumber(string.c_str()));

  string = "12e";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "1a3.14";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "1+23";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "1.2.3";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "+-5";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "12e+5.4";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = ".";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = ".e1";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "e1";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "+.";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  string = "";
  EXPECT_FALSE(IsStringRepresentNumber(string.c_str()));
  EXPECT_FALSE(IsStringRepresentNumber(nullptr));
}