//
// Created by Dan Jiang on 2020/7/20.
//

#include "gtest/gtest.h"

#include "print_dice_probability.h"

TEST(PrintDiceProbability, Recursion) {
  PrintDiceProbabilityRecursion(1);
  std::cout << std::endl;
  PrintDiceProbabilityRecursion(2);
  std::cout << std::endl;
  PrintDiceProbabilityRecursion(3);
  std::cout << std::endl;
  PrintDiceProbabilityRecursion(4);
  std::cout << std::endl;
  PrintDiceProbabilityRecursion(11);
  std::cout << std::endl;
  PrintDiceProbabilityRecursion(0);
  std::cout << std::endl;
}

TEST(PrintDiceProbability, Loop) {
  PrintDiceProbabilityLoop(1);
  std::cout << std::endl;
  PrintDiceProbabilityLoop(2);
  std::cout << std::endl;
  PrintDiceProbabilityLoop(3);
  std::cout << std::endl;
  PrintDiceProbabilityLoop(4);
  std::cout << std::endl;
  PrintDiceProbabilityLoop(11);
  std::cout << std::endl;
  PrintDiceProbabilityLoop(0);
  std::cout << std::endl;
}