//
// Created by Dan Jiang on 2020/8/4.
//

#include "gtest/gtest.h"

#include "string_permutation.h"

TEST(StringPermutation, NormalCase) {
  char string1[] = "";
  std::cout << std::endl;
  StringPermutation(string1);
  std::cout << std::endl;

  char string2[] = "a";
  std::cout << std::endl;
  StringPermutation(string2);
  std::cout << std::endl;

  char string3[] = "ab";
  std::cout << std::endl;
  StringPermutation(string3);
  std::cout << std::endl;

  char string4[] = "abc";
  std::cout << std::endl;
  StringPermutation(string4);
  std::cout << std::endl;
}