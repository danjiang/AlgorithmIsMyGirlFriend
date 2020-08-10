//
// Created by Dan Jiang on 2020/8/10.
//

#include "queue_with_max.h"

#include <string>

std::vector<int> MaxInSlidingWindow(int array[], int size, int window) {
  if (array == nullptr || size <= 0 || window <= 0 || window > size) {
    throw invalid_input("invalid input");
  }

  std::vector<int> max;
  std::deque<int> max_candidate;
  for (int i = 0; i < window; ++i) {
    while (!max_candidate.empty() && array[i] > array[max_candidate.back()]) {
      max_candidate.pop_back();
    }
    max_candidate.push_back(i);
  }
  max.push_back(array[max_candidate.front()]);
  for (int i = window; i < size; ++i) {
    if (max_candidate.front() == i - window) {
      max_candidate.pop_front();
    }
    while (!max_candidate.empty() && array[i] > array[max_candidate.back()]) {
      max_candidate.pop_back();
    }
    max_candidate.push_back(i);
    max.push_back(array[max_candidate.front()]);
  }

  return max;
}

QueueWithMax::QueueWithMax() = default;

void QueueWithMax::Push(int value) {
  while (!max.empty() && value > max.back().number) {
    max.pop_back();
  }
  max.push_back(InternalData {index, value});
  queue.push_back(InternalData {index, value});
  index++;
}

int QueueWithMax::Pop() {
  if (queue.empty()) {
    throw invalid_operation("queue is empty");
  }
  if (queue.front().index == max.front().index) {
    max.pop_front();
  }
  int number = queue.front().number;
  queue.pop_front();
  return number;
}

int QueueWithMax::Max() {
  if (queue.empty()) {
    throw invalid_operation("queue is empty");
  }
  return max.front().number;
}
