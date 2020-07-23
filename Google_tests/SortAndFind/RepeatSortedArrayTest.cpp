//
// Created by Dan Jiang on 2020/7/23.
//

#include "gtest/gtest.h"

#include "binary_search.h"

class RepeatSortedArrayFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    sorted_array[0] = 1;
    sorted_array[1] = 3;
    sorted_array[2] = 4;
    sorted_array[3] = 5;
    sorted_array[4] = 6;
    sorted_array[5] = 8;
    sorted_array[6] = 8;
    sorted_array[7] = 8;
    sorted_array[8] = 11;
    sorted_array[9] = 18;
  }

  virtual void TearDown() {
  }

  int size = 10;
  int sorted_array[10];
};

TEST_F(RepeatSortedArrayFixture, BinarySearchFirstEQ) {
  int value = 8;
  int index = BinarySearchFirstEQ(sorted_array, size, value);
  EXPECT_EQ(index, 5);

  value = 1;
  index = BinarySearchFirstEQ(sorted_array, size, value);
  EXPECT_EQ(index, 0);

  value = 18;
  index = BinarySearchFirstEQ(sorted_array, size, value);
  EXPECT_EQ(index, 9);

  value = 46;
  EXPECT_THROW(BinarySearchFirstEQ(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchFirstEQ(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchFirstEQ(nullptr, 0, 0), invalid_input);
}

TEST_F(RepeatSortedArrayFixture, BinarySearchLastEQ) {
  int value = 8;
  int index = BinarySearchLastEQ(sorted_array, size, value);
  EXPECT_EQ(index, 7);

  value = 1;
  index = BinarySearchLastEQ(sorted_array, size, value);
  EXPECT_EQ(index, 0);

  value = 18;
  index = BinarySearchLastEQ(sorted_array, size, value);
  EXPECT_EQ(index, 9);

  value = 46;
  EXPECT_THROW(BinarySearchLastEQ(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchLastEQ(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchLastEQ(nullptr, 0, 0), invalid_input);
}

TEST_F(RepeatSortedArrayFixture, BinarySearchFirstGE) {
  int value = 8;
  int index = BinarySearchFirstGE(sorted_array, size, value);
  EXPECT_EQ(index, 5);

  value = 7;
  index = BinarySearchFirstGE(sorted_array, size, value);
  EXPECT_EQ(index, 5);

  value = 2;
  index = BinarySearchFirstGE(sorted_array, size, value);
  EXPECT_EQ(index, 1);

  value = 9;
  index = BinarySearchFirstGE(sorted_array, size, value);
  EXPECT_EQ(index, 8);

  value = 46;
  EXPECT_THROW(BinarySearchFirstGE(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchFirstGE(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchFirstGE(nullptr, 0, 0), invalid_input);
}

TEST_F(RepeatSortedArrayFixture, BinarySearchLastLE) {
  int value = 8;
  int index = BinarySearchLastLE(sorted_array, size, value);
  EXPECT_EQ(index, 7);

  value = 9;
  index = BinarySearchLastLE(sorted_array, size, value);
  EXPECT_EQ(index, 7);

  value = 2;
  index = BinarySearchLastLE(sorted_array, size, value);
  EXPECT_EQ(index, 0);

  value = 12;
  index = BinarySearchLastLE(sorted_array, size, value);
  EXPECT_EQ(index, 8);

  value = 0;
  EXPECT_THROW(BinarySearchLastLE(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchLastLE(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchLastLE(nullptr, 0, 0), invalid_input);
}