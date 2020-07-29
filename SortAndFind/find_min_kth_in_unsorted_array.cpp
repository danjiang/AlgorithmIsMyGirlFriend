//
// Created by Dan Jiang on 2020/7/29.
//

#include "find_min_kth_in_unsorted_array.h"

#include <string>
#include "quick_sort.h"

int FindMinKthInUnsortedArrayCore(int k, int array[], int start, int end) {
  if (start == end) {
    return array[start];
  }
  int index = Partition(array, start, end);
  int small = index + 1;
  if (small == k) {
    return index;
  } else if (k < small) {
    return FindMinKthInUnsortedArrayCore(k, array, start, index - 1);
  } else {
    return FindMinKthInUnsortedArrayCore(k, array, index + 1, end);
  }
}

void FindMinKthInUnsortedArray(int k, int array[], int size, int mins[]) {
  if (array == nullptr || mins == nullptr || size <= 0 || k < 1 || k > size) {
    throw invalid_input("invalid input");
  }
  int index = FindMinKthInUnsortedArrayCore(k, array, 0, size - 1);
  for (int i = 0; i <= index; ++i) {
    mins[i] = array[i];
  }
}
