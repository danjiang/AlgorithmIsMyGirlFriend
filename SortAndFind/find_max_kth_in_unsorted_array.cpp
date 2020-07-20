//
// Created by Dan Jiang on 2020/7/20.
//

#include "find_max_kth_in_unsorted_array.h"
#include <string>
#include "array_util.h"

int FindMaxKthInUnsortedArrayCore(int k, int array[], int start, int end) {
  if (start == end) {
    return array[start];
  }
  int big = start - 1;
  for (int i = start; i < end; ++i) {
    if (array[i] > array[end]) {
      big++;
      if (big != i) {
        Swap(&array[big], &array[i]);
      }
    }
  }
  big++;
  Swap(&array[big], &array[end]);
  if (big + 1 == k) {
    return array[big];
  } else if (k < big + 1) {
    return FindMaxKthInUnsortedArrayCore(k, array, start, big - 1);
  } else {
    return FindMaxKthInUnsortedArrayCore(k, array, big + 1, end);
  }
}

int FindMaxKthInUnsortedArray(int k, int array[], int size) {
  if (array == nullptr || size < 0 || k < 1 || k > size) {
    throw invalid_input("invalid input");
  }
  return FindMaxKthInUnsortedArrayCore(k, array, 0, size - 1);
}
