//
// Created by Dan Jiang on 2020/7/17.
//

#ifndef ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_H_
#define ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_H_

#include <stack>
#include "../common.h"
#include "link_list.h"

class QueueInTwoStack {
 public:
  QueueInTwoStack();
  void Push(int value);
  int Pop();
 private:
  std::stack<int> stack1;
  std::stack<int> stack2;
};

class QueueInArray {
 public:
  QueueInArray(int length);
  void Push(int value);
  int Pop();
 private:
  int *array;
  int size;
  int head;
  int tail;
};

class QueueInCircularArray {
 public:
  QueueInCircularArray(int length);
  void Push(int value);
  int Pop();
 private:
  int *array;
  int size;
  int head;
  int tail;
};

class QueueInLinkList {
 public:
  QueueInLinkList();
  void Push(int value);
  int Pop();
 private:
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
};

#endif //ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_H_
