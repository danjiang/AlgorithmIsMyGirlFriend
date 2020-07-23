//
// Created by Dan Jiang on 2020/7/23.
//

#include "gtest/gtest.h"

#include "rotated_array.h"

class RepeatRotatedArrayFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    rotated_array[0] = 3;
    rotated_array[1] = 4;
    rotated_array[2] = 5;
    rotated_array[3] = 1;
    rotated_array[4] = 1;
    rotated_array[5] = 2;
  }

  virtual void TearDown() {
  }

  int size = 6;
  int rotated_array[6];
};

TEST_F(RepeatRotatedArrayFixture, SearchMinValueOfRepeatRotatedArray) {
  int value = SearchMinValueOfRepeatRotatedArray(rotated_array, size);
  EXPECT_EQ(value, 1);

  int array1[] = { 3, 4, 5, 1, 2, 2 };
  EXPECT_EQ(SearchMinValueOfRepeatRotatedArray(array1, 6), 1);

  int array2[] = { 1, 0, 1, 1, 1 };
  EXPECT_EQ(SearchMinValueOfRepeatRotatedArray(array2, 5), 0);

  int array3[] = { 5 };
  EXPECT_EQ(SearchMinValueOfRepeatRotatedArray(array3, 1), 5);

  EXPECT_THROW(SearchMinValueOfRepeatRotatedArray(nullptr, 0), invalid_input);
}