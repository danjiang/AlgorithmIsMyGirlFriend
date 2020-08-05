//
// Created by Dan Jiang on 2020/8/5.
//

#include "count_inverse_pairs.h"

int CountInversePairsMerge(int array[], int start, int middle, int end) {
  int count = 0;
  int left_index = start;
  int right_index = middle + 1;
  int index = 0;
  int size = end - start + 1;
  int sorted_array[size];
  while (left_index <= middle && right_index <= end) {
    if (array[left_index] <= array[right_index]) {
      sorted_array[index] = array[left_index];
      index++;
      left_index++;
    } else {
      count += middle - left_index + 1;
      sorted_array[index] = array[right_index];
      index++;
      right_index++;
    }
  }
  while (left_index <= middle) {
    sorted_array[index] = array[left_index];
    index++;
    left_index++;
  }
  while (right_index <= end) {
    sorted_array[index] = array[right_index];
    index++;
    right_index++;
  }
  for (int i = 0; i < size; ++i) {
    array[start + i] = sorted_array[i];
  }
  return count;
}

int CountInversePairsCore(int array[], int start, int end) {
  if (start >= end) {
    return 0;
  }
  int middle = (start + end) / 2;
  int left_count = CountInversePairsCore(array, start, middle);
  int right_count = CountInversePairsCore(array, middle + 1, end);
  int merge_count = CountInversePairsMerge(array, start, middle, end);
  return left_count + right_count + merge_count;
}

int CountInversePairs(int array[], int size) {
  if (array == nullptr || size <= 0) {
    return 0;
  }
  return CountInversePairsCore(array, 0, size - 1);
}