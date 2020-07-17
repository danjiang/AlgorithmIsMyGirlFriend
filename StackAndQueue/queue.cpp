//
// Created by Dan Jiang on 2020/7/17.
//

#include "queue.h"

#include <string>

QueueInTwoStack::QueueInTwoStack() = default;

void QueueInTwoStack::Push(int value) {
  stack1.push(value);
}

int QueueInTwoStack::Pop() {
  if (stack2.empty()) {
    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }
  }
  if (stack2.empty()) {
    throw invalid_operation("queue is empty");
  }
  int value = stack2.top();
  stack2.pop();
  return value;
}

QueueInArray::QueueInArray(int length) {
  size = length;
  array = new int[size];
  head = 0;
  tail = 0;
}

void QueueInArray::Push(int value) {
  if (tail < size) {
    array[tail] = value;
    tail++;
  } else if (head > 0) {
    int distance = head;
    tail = tail - distance;
    while (head < size) {
      array[head - distance] = array[head];
      head++;
    }
    head = 0;
    array[tail] = value;
    tail++;
  } else {
    throw invalid_operation("queue is full");
  }
}

int QueueInArray::Pop() {
  if (head != tail) {
    int value = array[head];
    head++;
    return value;
  } else {
    throw invalid_operation("queue is empty");
  }
}

QueueInCircularArray::QueueInCircularArray(int length) {
  size = length + 1;
  array = new int[size];
  head = 0;
  tail = 0;
}

void QueueInCircularArray::Push(int value) {
  if ((tail + 1) % size != head) {
    array[tail] = value;
    tail = (tail + 1) % size;
  } else {
    throw invalid_operation("queue is full");
  }
}

int QueueInCircularArray::Pop() {
  if (head != tail) {
    int value = array[head];
    head = (head + 1) % size;
    return value;
  } else {
    throw invalid_operation("queue is empty");
  }
}

QueueInLinkList::QueueInLinkList() = default;

void QueueInLinkList::Push(int value) {
  auto node = new ListNode(value);
  if (tail == nullptr) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = tail->next;
  }
}

int QueueInLinkList::Pop() {
  if (head != nullptr) {
    int value = head->value;
    ListNode *deleted_node = head;
    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    }
    delete deleted_node;
    deleted_node = nullptr;
    return value;
  } else {
    throw invalid_operation("queue is empty");
  }
}