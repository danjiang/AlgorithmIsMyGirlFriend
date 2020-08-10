//
// Created by Dan Jiang on 2020/8/10.
//

#include "gtest/gtest.h"

#include "queue_with_max.h"

TEST(QueueWithMax, WindowCase) {
  int array1[] = {2, 3, 4, 2, 6, 2, 5, 1};
  std::vector<int> expected1{4, 4, 6, 6, 6, 5};
  auto max1 = MaxInSlidingWindow(array1, sizeof(array1) / sizeof(int), 3);
  EXPECT_EQ(max1, expected1);

  int array2[] = {1, 3, -1, -3, 5, 3, 6, 7};
  std::vector<int> expected2{3, 3, 5, 5, 6, 7};
  auto max2 = MaxInSlidingWindow(array2, sizeof(array2) / sizeof(int), 3);
  EXPECT_EQ(max2, expected2);

  int array3[] = {1, 3, 5, 7, 9, 11, 13, 15};
  std::vector<int> expected3{7, 9, 11, 13, 15};
  auto max3 = MaxInSlidingWindow(array3, sizeof(array3) / sizeof(int), 4);
  EXPECT_EQ(max3, expected3);

  int array4[] = {16, 14, 12, 10, 8, 6, 4};
  std::vector<int> expected4{16, 14, 12};
  auto max4 = MaxInSlidingWindow(array4, sizeof(array4) / sizeof(int), 5);
  EXPECT_EQ(max4, expected4);

  int array5[] = {10, 14, 12, 11};
  std::vector<int> expected5{10, 14, 12, 11};
  auto max5 = MaxInSlidingWindow(array5, sizeof(array5) / sizeof(int), 1);
  EXPECT_EQ(max5, expected5);

  std::vector<int> expected6{14};
  auto max6 = MaxInSlidingWindow(array5, sizeof(array5) / sizeof(int), 4);
  EXPECT_EQ(max6, expected6);

  EXPECT_THROW(MaxInSlidingWindow(array5, sizeof(array5) / sizeof(int), 0), invalid_input);
  EXPECT_THROW(MaxInSlidingWindow(array5, sizeof(array5) / sizeof(int), 5), invalid_input);
  EXPECT_THROW(MaxInSlidingWindow(nullptr, 0, 5), invalid_input);
}

TEST(QueueWithMax, QueueCase) {
  QueueWithMax queue;
  queue.Push(2);
  EXPECT_EQ(queue.Max(), 2);
  queue.Push(3);
  EXPECT_EQ(queue.Max(), 3);
  queue.Push(4);
  EXPECT_EQ(queue.Max(), 4);
  queue.Push(2);
  EXPECT_EQ(queue.Max(), 4);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 4);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 4);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 2);
  queue.Push(6);
  EXPECT_EQ(queue.Max(), 6);
  queue.Push(2);
  EXPECT_EQ(queue.Max(), 6);
  queue.Push(5);
  EXPECT_EQ(queue.Max(), 6);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 6);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 5);
  queue.Pop();
  EXPECT_EQ(queue.Max(), 5);
  queue.Push(1);
  EXPECT_EQ(queue.Max(), 5);
}