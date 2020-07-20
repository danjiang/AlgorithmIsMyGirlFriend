//
// Created by Dan Jiang on 2020/7/17.
//

#include "gtest/gtest.h"

#include "check_palindromic_string_in_link_list.h"

TEST(OtherLinkList, ConstructBinaryTree) {
  std::string str1 {"abcccba"};
  EXPECT_TRUE(CheckPalindromicStringInLinkList(str1.c_str()));
  std::string str2 {"abcccbm"};
  EXPECT_FALSE(CheckPalindromicStringInLinkList(str2.c_str()));
  std::string str3 {"abccba"};
  EXPECT_TRUE(CheckPalindromicStringInLinkList(str3.c_str()));
  std::string str4 {"adccba"};
  EXPECT_FALSE(CheckPalindromicStringInLinkList(str4.c_str()));
  std::string str5 {"level"};
  EXPECT_TRUE(CheckPalindromicStringInLinkList(str5.c_str()));
  std::string str6 {"noon"};
  EXPECT_TRUE(CheckPalindromicStringInLinkList(str6.c_str()));
  std::string str7 {"ab"};
  EXPECT_FALSE(CheckPalindromicStringInLinkList(str7.c_str()));
  std::string str8 {"a"};
  EXPECT_TRUE(CheckPalindromicStringInLinkList(str8.c_str()));
  std::string str9 {""};
  EXPECT_FALSE(CheckPalindromicStringInLinkList(str9.c_str()));
  EXPECT_FALSE(CheckPalindromicStringInLinkList(nullptr));
}