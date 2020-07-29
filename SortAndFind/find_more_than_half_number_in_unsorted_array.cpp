//
// Created by Dan Jiang on 2020/7/29.
//

#include "find_more_than_half_number_in_unsorted_array.h"

#include <string>
#include "find_max_kth_in_unsorted_array.h"

void CheckMoreThanHalf(int array[], int size, int number) {
  int times = 0;
  for (int i = 0; i < size; ++i) {
    if (array[i] == number) {
      times++;
    }
  }
  if (times * 2 <= size) {
    throw invalid_input("no more than half number");
  }
}

int FindMoreThanHalfNumberInUnsortedArrayPartition(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int middle = size / 2 + 1;
  int number = FindMaxKthInUnsortedArray(middle, array, size);
  CheckMoreThanHalf(array, size, number);
  return number;
}

int FindMoreThanHalfNumberInUnsortedArrayCount(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int number = array[0];
  int times = 1;
  for (int i = 1; i < size; ++i) {
    if (times == 0) {
      number = array[i];
    } else if (number == array[i]) {
      times++;
    } else {
      times--;
    }
  }
  CheckMoreThanHalf(array, size, number);
  return number;
}