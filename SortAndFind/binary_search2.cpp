//
// Created by Dan Jiang on 2020/7/23.
//

#include "binary_search2.h"
#include "binary_search.h"
#include <string>

int CountValueInSortedArray(const int array[], int size, int value) {
  int first = BinarySearchFirstEQ(array, size, value);
  int last = BinarySearchLastEQ(array, size, value);
  return last - first + 1;
}

int FindMissingValueInSortedArray(const int *array, int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] != middle) {
      if (middle == 0 || array[middle - 1] == middle - 1) {
        return middle;
      } else {
        high = middle - 1;
      }
    } else {
      low = middle + 1;
    }
  }
  if (low == size) { // missing size - 1
    return size;
  }

  throw not_found("missing value is not found");
}

int FindValueEqualIndexInSortedArray(const int *array, int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] == middle) {
      return middle;
    } else if (middle < array[middle]) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  throw not_found("value is not found");
}