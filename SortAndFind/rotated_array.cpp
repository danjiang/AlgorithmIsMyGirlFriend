//
// Created by Dan Jiang on 2020/7/23.
//

#include "rotated_array.h"
#include <string>

int BinarySearch(const int array[], int low, int high, int value) {
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] == value) {
      return middle;
    } else if (value < array[middle]) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int SearchRotatedArray(const int array[], int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] == value) {
      return middle;
    } else if (array[low] < array[middle]) {
      if (value >= array[low] && value <= array[middle]) {
        return BinarySearch(array, low, middle, value);
      } else {
        low = middle + 1;
      }
    } else {
      if (value >= array[middle] && value <= array[high]) {
        return BinarySearch(array, middle, high, value);
      } else {
        high = middle - 1;
      }
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int SearchMinValueOfDistinctRotatedArray(const int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  if (size == 1) {
    return array[0];
  }
  int low = 0;
  int high = size - 1;
  int min = low;
  while (array[low] >= array[high]) {
    int middle = low + ((high - low) >> 1);
    if (high - low == 1) {
      min = high;
      break;
    }
    if (array[low] < array[middle]) {
      low = middle;
    } else {
      high = middle;
    }
  }
  return array[min];
}

int SearchMinValueOfRepeatRotatedArray(const int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  if (size == 1) {
    return array[0];
  }
  int low = 0;
  int high = size - 1;
  int min = low;
  while (array[low] >= array[high]) {
    int middle = low + ((high - low) >> 1);
    if (high - low == 1) {
      min = high;
      break;
    }

    if (array[low] == array[middle] && array[middle] == array[high]) {
      min = low;
      for (int i = low + 1; i <= high; ++i) {
        if (array[i] < array[min]) {
          min = i;
        }
      }
      break;
    }

    if (array[low] < array[middle]) {
      low = middle;
    } else {
      high = middle;
    }
  }
  return array[min];
}