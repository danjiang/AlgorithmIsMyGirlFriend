//
// Created by Dan Jiang on 2020/7/17.
//

#include "gtest/gtest.h"

#include "queue.h"

TEST(Queue, QueueInTwoStack) {
  QueueInTwoStack queue;

  queue.Push(1);
  queue.Push(2);
  queue.Push(3);

  EXPECT_EQ(queue.Pop(), 1);
  EXPECT_EQ(queue.Pop(), 2);

  queue.Push(4);
  EXPECT_EQ(queue.Pop(), 3);

  queue.Push(5);
  EXPECT_EQ(queue.Pop(), 4);

  EXPECT_EQ(queue.Pop(), 5);

  EXPECT_THROW(queue.Pop(), invalid_operation);
}

TEST(Queue, QueueInArray) {
  QueueInArray queue(5);

  queue.Push(1);
  queue.Push(2);
  queue.Push(3);

  EXPECT_EQ(queue.Pop(), 1);
  EXPECT_EQ(queue.Pop(), 2);

  queue.Push(4);
  queue.Push(5);
  queue.Push(6);

  EXPECT_EQ(queue.Pop(), 3);

  queue.Push(7);
  queue.Push(8);

  EXPECT_THROW(queue.Push(9), invalid_operation);

  EXPECT_EQ(queue.Pop(), 4);
  EXPECT_EQ(queue.Pop(), 5);
  EXPECT_EQ(queue.Pop(), 6);
  EXPECT_EQ(queue.Pop(), 7);
  EXPECT_EQ(queue.Pop(), 8);

  EXPECT_THROW(queue.Pop(), invalid_operation);
}

TEST(Queue, QueueInCircularArray) {
  QueueInCircularArray queue(5);

  queue.Push(1);
  queue.Push(2);
  queue.Push(3);

  EXPECT_EQ(queue.Pop(), 1);
  EXPECT_EQ(queue.Pop(), 2);

  queue.Push(4);
  queue.Push(5);
  queue.Push(6);

  EXPECT_EQ(queue.Pop(), 3);

  queue.Push(7);
  queue.Push(8);

  EXPECT_THROW(queue.Push(9), invalid_operation);

  EXPECT_EQ(queue.Pop(), 4);
  EXPECT_EQ(queue.Pop(), 5);
  EXPECT_EQ(queue.Pop(), 6);
  EXPECT_EQ(queue.Pop(), 7);
  EXPECT_EQ(queue.Pop(), 8);

  EXPECT_THROW(queue.Pop(), invalid_operation);
}

TEST(Queue, QueueInLinkList) {
  QueueInLinkList queue;

  queue.Push(1);
  queue.Push(2);
  queue.Push(3);

  EXPECT_EQ(queue.Pop(), 1);
  EXPECT_EQ(queue.Pop(), 2);

  queue.Push(4);
  queue.Push(5);
  queue.Push(6);

  EXPECT_EQ(queue.Pop(), 3);

  queue.Push(7);
  queue.Push(8);

  EXPECT_EQ(queue.Pop(), 4);
  EXPECT_EQ(queue.Pop(), 5);
  EXPECT_EQ(queue.Pop(), 6);
  EXPECT_EQ(queue.Pop(), 7);
  EXPECT_EQ(queue.Pop(), 8);

  EXPECT_THROW(queue.Pop(), invalid_operation);
}