//
// Created by Dan Jiang on 2020/7/17.
//

#include "gtest/gtest.h"

#include "is_pop_order_of_stack.h"

TEST(IsPopOrderOfStack, Test1) {
  const int nLength = 5;
  int push[nLength] = { 1, 2, 3, 4, 5 };
  int pop[nLength] = { 4, 5, 3, 2, 1 };
  EXPECT_TRUE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test2) {
  const int nLength = 5;
  int push[nLength] = { 1, 2, 3, 4, 5 };
  int pop[nLength] = { 3, 5, 4, 2, 1 };
  EXPECT_TRUE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test3) {
  const int nLength = 5;
  int push[nLength] = { 1, 2, 3, 4, 5 };
  int pop[nLength] = { 4, 3, 5, 1, 2 };
  EXPECT_FALSE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test4) {
  const int nLength = 5;
  int push[nLength] = { 1, 2, 3, 4, 5 };
  int pop[nLength] = { 3, 5, 4, 1, 2 };
  EXPECT_FALSE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test5) {
  const int nLength = 1;
  int push[nLength] = { 1 };
  int pop[nLength] = { 2 };
  EXPECT_FALSE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test6) {
  const int nLength = 1;
  int push[nLength] = { 1 };
  int pop[nLength] = { 1 };
  EXPECT_TRUE(IsPopOrderOfStack(push, pop, nLength));
}

TEST(IsPopOrderOfStack, Test7) {
  EXPECT_FALSE(IsPopOrderOfStack(nullptr, nullptr, 0));
}