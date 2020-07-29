//
// Created by Dan Jiang on 2020/7/20.
//

#include "find_max_kth_in_unsorted_array.h"
#include <string>
#include "quick_sort.h"

int FindMaxKthInUnsortedArrayCore(int k, int array[], int size, int start, int end) {
  if (start == end) {
    return array[start];
  }
  int index = Partition(array, start, end);
  int big = size - index;
  if (big == k) {
    return array[index];
  } else if (k > big) {
    return FindMaxKthInUnsortedArrayCore(k, array, size, start, index - 1);
  } else {
    return FindMaxKthInUnsortedArrayCore(k, array, size, index + 1, end);
  }
}

int FindMaxKthInUnsortedArray(int k, int array[], int size) {
  if (array == nullptr || size <= 0 || k < 1 || k > size) {
    throw invalid_input("invalid input");
  }
  return FindMaxKthInUnsortedArrayCore(k, array, size, 0, size - 1);
}
