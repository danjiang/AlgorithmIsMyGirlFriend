//
// Created by Dan Jiang on 2020/7/31.
//

#include "get_middle_number_of_stream.h"

#include <algorithm>
#include <string>

DynamicArrayInHeap::DynamicArrayInHeap() = default;

void DynamicArrayInHeap::Insert(int value) {
  if (((max.size() + min.size()) & 1) == 0) { // size is even
    int max_value = value;
    if (max.size() > 0 && max_value < max[0]) {
      max.push_back(max_value);
      std::push_heap(max.begin(), max.end(), std::less<int>());

      max_value = max[0];

      std::pop_heap(max.begin(), max.end(), std::less<int>());
      max.pop_back();
    }

    min.push_back(max_value);
    std::push_heap(min.begin(), min.end(), std::greater<int>());
  } else { // size is odd
    int min_value = value;
    if (min.size() > 0 && min_value > min[0]) {
      min.push_back(value);
      std::push_heap(min.begin(), min.end(), std::greater<int>());

      min_value = min[0];

      std::pop_heap(min.begin(), min.end(), std::greater<int>());
      min.pop_back();
    }

    max.push_back(min_value);
    std::push_heap(max.begin(), max.end(), std::less<int>());
  }
}

double DynamicArrayInHeap::Middle() {
  int size = max.size() + min.size();
  if (size == 0) {
    throw invalid_operation("dynamic array is empty");
  }
  if ((size & 1) == 1) {
    return min[0];
  } else {
    return (min[0] + max[0]) / 2.0;
  }
}
