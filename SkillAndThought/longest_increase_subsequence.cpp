//
// Created by Dan Jiang on 2020/8/8.
//

#include "longest_increase_subsequence.h"

int LongestIncreaseSubsequenceCore(int end, int array[], int size, int *min, int *max) {
  if (end == 0) {
    *min = array[0];
    *max = array[0];
    return 1;
  }
  int length = LongestIncreaseSubsequenceCore(end - 1, array, size, min, max);
  if (array[end] > *max) {
    length += 1;
    *max = array[end];
  } else if (array[end] > *min) {
    *max = array[end];
  }
  return length;
}

int LongestIncreaseSubsequence(int array[], int size) {
  if (array == nullptr || size <= 0) {
    return 0;
  }
  int min = 0;
  int max = 0;
  return LongestIncreaseSubsequenceCore(size - 1, array, size, &min, &max);
}