//
// Created by Dan Jiang on 2020/7/20.
//

#include "gtest/gtest.h"

#include "array_util.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "find_max_kth_in_unsorted_array.h"

class SortArrayFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    unsorted_array[0] = 5;
    unsorted_array[1] = 1;
    unsorted_array[2] = 4;
    unsorted_array[3] = 2;
    unsorted_array[4] = 8;

    sorted_array[0] = 1;
    sorted_array[1] = 2;
    sorted_array[2] = 4;
    sorted_array[3] = 5;
    sorted_array[4] = 8;
  }

  virtual void TearDown() {
  }

  int size = 5;
  int unsorted_array[5];
  int sorted_array[5];
};

TEST_F(SortArrayFixture, BubbleSort) {
  BubbleSort(unsorted_array, size);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}

TEST_F(SortArrayFixture, InsertionSort) {
  InsertionSort(unsorted_array, size);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}

TEST_F(SortArrayFixture, SelectionSort) {
  SelectionSort(unsorted_array, size);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}

TEST_F(SortArrayFixture, MergeSort) {
  MergeSort(unsorted_array, size, 0, size - 1);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}

TEST_F(SortArrayFixture, QuickSort) {
  QuickSort(unsorted_array, size, 0, size - 1);
  EXPECT_TRUE(IsSameArray(unsorted_array, sorted_array, size));
}

TEST_F(SortArrayFixture, FindMaxKthInUnsortedArrayFirst) {
  int k = 1;
  EXPECT_EQ(FindMaxKthInUnsortedArray(k, unsorted_array, size), sorted_array[size - k]);
}

TEST_F(SortArrayFixture, FindMaxKthInUnsortedArrayMiddle) {
  int k = 3;
  EXPECT_EQ(FindMaxKthInUnsortedArray(k, unsorted_array, size), sorted_array[size - k]);
}

TEST_F(SortArrayFixture, FindMaxKthInUnsortedArrayLast) {
  int k = 5;
  EXPECT_EQ(FindMaxKthInUnsortedArray(k, unsorted_array, size), sorted_array[size - k]);
}
