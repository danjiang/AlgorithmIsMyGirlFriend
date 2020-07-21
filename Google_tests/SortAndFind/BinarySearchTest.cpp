//
// Created by Dan Jiang on 2020/7/21.
//

#include "gtest/gtest.h"

#include "binary_search.h"

class BinarySearchArrayFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    sorted_array[0] = 8;
    sorted_array[1] = 11;
    sorted_array[2] = 19;
    sorted_array[3] = 23;
    sorted_array[4] = 27;
    sorted_array[5] = 33;
    sorted_array[6] = 45;
    sorted_array[7] = 55;
    sorted_array[8] = 67;
    sorted_array[9] = 98;
  }

  virtual void TearDown() {
  }

  int size = 10;
  int sorted_array[10];
};

TEST_F(BinarySearchArrayFixture, BinarySearchLoop) {
  int value = 19;
  int index = BinarySearchLoop(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 27;
  index = BinarySearchLoop(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 98;
  index = BinarySearchLoop(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 46;
  EXPECT_THROW(BinarySearchLoop(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchLoop(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchLoop(nullptr, 0, 0), invalid_input);
}

TEST_F(BinarySearchArrayFixture, BinarySearchRecursion) {
  int value = 19;
  int index = BinarySearchRecursion(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 27;
  index = BinarySearchRecursion(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 98;
  index = BinarySearchRecursion(sorted_array, size, value);
  EXPECT_EQ(sorted_array[index], value);

  value = 46;
  EXPECT_THROW(BinarySearchRecursion(sorted_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(BinarySearchRecursion(array, 1, 5), 0);

  EXPECT_THROW(BinarySearchRecursion(nullptr, 0, 0), invalid_input);
}