//
// Created by Dan Jiang on 2020/7/20.
//

#include "gtest/gtest.h"

#include "fibonacci.h"

TEST(Fibonacci, Recursion) {
  EXPECT_EQ(FibonacciRecursion(0), 0);
  EXPECT_EQ(FibonacciRecursion(1), 1);
  EXPECT_EQ(FibonacciRecursion(2), 1);
  EXPECT_EQ(FibonacciRecursion(3), 2);
  EXPECT_EQ(FibonacciRecursion(4), 3);
  EXPECT_EQ(FibonacciRecursion(5), 5);
  EXPECT_EQ(FibonacciRecursion(6), 8);
  EXPECT_EQ(FibonacciRecursion(7), 13);
  EXPECT_EQ(FibonacciRecursion(8), 21);
  EXPECT_EQ(FibonacciRecursion(9), 34);
  EXPECT_EQ(FibonacciRecursion(10), 55);
  EXPECT_EQ(FibonacciRecursion(40), 102334155);
}

TEST(Fibonacci, Loop) {
  EXPECT_EQ(FibonacciLoop(0), 0);
  EXPECT_EQ(FibonacciLoop(1), 1);
  EXPECT_EQ(FibonacciLoop(2), 1);
  EXPECT_EQ(FibonacciLoop(3), 2);
  EXPECT_EQ(FibonacciLoop(4), 3);
  EXPECT_EQ(FibonacciLoop(5), 5);
  EXPECT_EQ(FibonacciLoop(6), 8);
  EXPECT_EQ(FibonacciLoop(7), 13);
  EXPECT_EQ(FibonacciLoop(8), 21);
  EXPECT_EQ(FibonacciLoop(9), 34);
  EXPECT_EQ(FibonacciLoop(10), 55);
  EXPECT_EQ(FibonacciLoop(40), 102334155);
}