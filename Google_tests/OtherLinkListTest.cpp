//
// Created by Dan Jiang on 2020/7/17.
//

#include "gtest/gtest.h"

#include "check_palindromic_string_in_link_list.h"

TEST(OtherLinkList, ConstructBinaryTree) {
  EXPECT_TRUE(CheckPalindromicStringInLinkList("abcccba"));
  EXPECT_FALSE(CheckPalindromicStringInLinkList("abcccbm"));
  EXPECT_TRUE(CheckPalindromicStringInLinkList("abccba"));
  EXPECT_FALSE(CheckPalindromicStringInLinkList("adccba"));
  EXPECT_TRUE(CheckPalindromicStringInLinkList("level"));
  EXPECT_TRUE(CheckPalindromicStringInLinkList("noon"));
  EXPECT_FALSE(CheckPalindromicStringInLinkList("ab"));
  EXPECT_TRUE(CheckPalindromicStringInLinkList("a"));
  EXPECT_FALSE(CheckPalindromicStringInLinkList(""));
  EXPECT_FALSE(CheckPalindromicStringInLinkList(nullptr));
}