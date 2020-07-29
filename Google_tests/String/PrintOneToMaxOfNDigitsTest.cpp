//
// Created by Dan Jiang on 2020/7/29.
//

#include "gtest/gtest.h"

#include <iostream>
#include "print_one_to_max_of_n_digits.h"

TEST(PrintOneToMaxOfNDigits, IncrementCase) {
  PrintOneToMaxOfNDigitsIncrement(1);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsIncrement(2);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsIncrement(3);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsIncrement(0);
  PrintOneToMaxOfNDigitsIncrement(-1);
}

TEST(PrintOneToMaxOfNDigits, RecursionCase) {
  PrintOneToMaxOfNDigitsRecursion(1);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsRecursion(2);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsRecursion(3);
  std::cout << std::endl;
  PrintOneToMaxOfNDigitsRecursion(0);
  PrintOneToMaxOfNDigitsRecursion(-1);
}