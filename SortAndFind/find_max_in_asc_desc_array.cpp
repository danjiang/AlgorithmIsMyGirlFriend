//
// Created by Dan Jiang on 2020/9/8.
//

#include "find_max_in_asc_desc_array.h"

int FindMaxInAscDescArray(int array[], int size) {
  if (array == nullptr || size <= 2) {
    return -1;
  }
  int start = 0;
  int end = size - 1;
  while (start < end) {
    int middle = start + ((end - start) >> 1);
    if (end - start == 1) {
      if (array[end] < array[start]) {
        return start;
      } else {
        return -1;
      }
    } else if (array[middle] > array[middle - 1]) {
      start = middle;
    } else {
      end = middle;
    }
  }
  return -1;
}