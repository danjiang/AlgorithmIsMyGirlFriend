//
// Created by Dan Jiang on 2020/7/23.
//

#include "gtest/gtest.h"

#include "rotated_array.h"
#include "insertion_sort.h"

class DistinctRotatedArrayFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    rotated_array[0] = 4;
    rotated_array[1] = 5;
    rotated_array[2] = 6;
    rotated_array[3] = 1;
    rotated_array[4] = 2;
    rotated_array[5] = 3;
  }

  virtual void TearDown() {
  }

  int size = 6;
  int rotated_array[6];
};

TEST_F(DistinctRotatedArrayFixture, SearchRotatedArray) {
  int value = 0;
  for (int i = 0; i < size; i++) {
    int value = rotated_array[i];
    int index = SearchRotatedArray(rotated_array, size, value);
    EXPECT_EQ(index, i);
  }

  value = 46;
  EXPECT_THROW(SearchRotatedArray(rotated_array, size, value), not_found);

  int array[] = { 5 };
  EXPECT_EQ(SearchRotatedArray(array, 1, 5), 0);

  EXPECT_THROW(SearchRotatedArray(nullptr, 0, 0), invalid_input);
}

TEST_F(DistinctRotatedArrayFixture, SearchMinValueOfDistinctRotatedArray) {
  int value = SearchMinValueOfDistinctRotatedArray(rotated_array, size);
  EXPECT_EQ(value, 1);

  InsertionSort(rotated_array, size);
  value = SearchMinValueOfDistinctRotatedArray(rotated_array, size);
  EXPECT_EQ(value, 1);

  int array[] = { 5 };
  EXPECT_EQ(SearchMinValueOfDistinctRotatedArray(array, 1), 5);

  EXPECT_THROW(SearchMinValueOfDistinctRotatedArray(nullptr, 0), invalid_input);
}