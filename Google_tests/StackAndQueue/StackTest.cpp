//
// Created by Dan Jiang on 2020/7/17.
//

#include "gtest/gtest.h"

#include "stack.h"

TEST(Stack, StackWithMin) {
  StackWithMin stack;

  stack.Push(3);
  EXPECT_EQ(stack.Min(), 3);

  stack.Push(4);
  EXPECT_EQ(stack.Min(), 3);

  stack.Push(2);
  EXPECT_EQ(stack.Min(), 2);

  stack.Push(3);
  EXPECT_EQ(stack.Min(), 2);

  stack.Pop();
  EXPECT_EQ(stack.Min(), 2);

  stack.Pop();
  EXPECT_EQ(stack.Min(), 3);

  stack.Pop();
  EXPECT_EQ(stack.Min(), 3);

  stack.Push(0);
  EXPECT_EQ(stack.Min(), 0);
}

TEST(Stack, StackInArray) {
  StackInArray stack(3);

  stack.Push(3);
  EXPECT_EQ(stack.Top(), 3);

  stack.Push(4);
  EXPECT_EQ(stack.Top(), 4);

  stack.Pop();
  EXPECT_EQ(stack.Top(), 3);

  stack.Pop();
  EXPECT_THROW(stack.Top(), invalid_operation);
  EXPECT_THROW(stack.Pop(), invalid_operation);

  stack.Push(5);
  stack.Push(6);
  stack.Push(7);
  EXPECT_THROW(stack.Push(8), invalid_operation);
}

TEST(Stack, StackInLinkList) {
  StackInLinkList stack;

  stack.Push(3);
  EXPECT_EQ(stack.Top(), 3);

  stack.Push(4);
  EXPECT_EQ(stack.Top(), 4);

  stack.Pop();
  EXPECT_EQ(stack.Top(), 3);

  stack.Pop();
  EXPECT_THROW(stack.Top(), invalid_operation);
  EXPECT_THROW(stack.Pop(), invalid_operation);
}