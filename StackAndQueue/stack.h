//
// Created by Dan Jiang on 2020/7/17.
//

#ifndef ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_STACK_H_
#define ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_STACK_H_

#include <stack>
#include "../common.h"
#include "link_list.h"

class StackWithMin {
 public:
  StackWithMin();
  void Push(int value);
  int Pop();
  int Min();
 private:
  std::stack<int> stack;
  std::stack<int> min;
};

class StackInArray {
 public:
  StackInArray(int length);
  void Push(int value);
  int Top();
  void Pop();
  bool Empty();
 private:
  int *array;
  int size;
  int index;
};

class StackInLinkList {
 public:
  StackInLinkList();
  void Push(int value);
  int Top();
  void Pop();
  bool Empty();
 private:
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
};

#endif //ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_STACK_H_
