//
// Created by Dan Jiang on 2020/7/31.
//

#include "gtest/gtest.h"

#include "get_middle_number_of_stream.h"

TEST(GetMiddleNumberOfStream, DynamicArrayInHeapCase) {
  DynamicArrayInHeap numbers;

  EXPECT_THROW(numbers.Middle(), invalid_operation);

  numbers.Insert(5);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 5);

  numbers.Insert(2);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3.5);

  numbers.Insert(3);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3);

  numbers.Insert(4);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3.5);

  numbers.Insert(1);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3);

  numbers.Insert(6);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3.5);

  numbers.Insert(7);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 4);

  numbers.Insert(0);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 3.5);

  numbers.Insert(8);
  EXPECT_DOUBLE_EQ(numbers.Middle(), 4);
}