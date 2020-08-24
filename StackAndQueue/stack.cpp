//
// Created by Dan Jiang on 2020/7/17.
//

#include "stack.h"
#include <string>

StackWithMin::StackWithMin() = default;

void StackWithMin::Push(int value) {
  stack.push(value);
  if (min.empty()) {
    min.push(value);
  } else if (value < min.top()) {
    min.push(value);
  } else {
    min.push(min.top());
  }
}

int StackWithMin::Pop() {
  int value = stack.top();
  stack.pop();
  min.pop();
  return value;
}

int StackWithMin::Min() {
  return min.top();
}

StackInArray::StackInArray(int length) {
  size = length;
  index = 0;
  array = new int[size];
}

void StackInArray::Push(int value) {
  if (index < size) {
    array[index] = value;
    index++;
  } else {
    throw invalid_operation("stack is full");
  }
}

int StackInArray::Top() {
  if (index > 0) {
    return array[index - 1];
  } else {
    throw invalid_operation("stack is empty");
  }
}

void StackInArray::Pop() {
  if (index > 0) {
    index--;
  } else {
    throw invalid_operation("stack is empty");
  }
}

bool StackInArray::Empty() {
  return index == 0;
}

StackInLinkList::StackInLinkList() = default;

void StackInLinkList::Push(int value) {
  auto node = new ListNode(value);
  if (tail == nullptr) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

int StackInLinkList::Top() {
  if (head != nullptr) {
    return tail->value;
  } else {
    throw invalid_operation("stack is empty");
  }
}

void StackInLinkList::Pop() {
  if (head != nullptr) {
    ListNode *deleted_node = tail;
    if (head->next == nullptr) {
      head = nullptr;
      tail = nullptr;
    } else {
      ListNode *tail_prev = head;
      while (tail_prev->next->value != tail->value) {
        tail_prev = tail_prev->next;
      }
      tail = tail_prev;
      tail->next = nullptr;
    }
    delete deleted_node;
  } else {
    throw invalid_operation("stack is empty");
  }
}

bool StackInLinkList::Empty() {
  return head == nullptr;
}

