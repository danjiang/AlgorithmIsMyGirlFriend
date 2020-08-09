//
// Created by Dan Jiang on 2020/8/9.
//

#include "max_sum_sub_array.h"

#include <string>

int MaxSumSubArray(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }

  int max = array[0];
  int sum = array[0];

  for (int i = 1; i < size; ++i) {
    if (sum > 0) {
      sum += array[i];
    } else {
      sum = array[i];
    }
    if (sum > max) {
      max = sum;
    }
  }

  return max;
}