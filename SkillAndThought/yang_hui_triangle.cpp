//
// Created by Dan Jiang on 2020/8/7.
//

#include "yang_hui_triangle.h"

int YangHuiTriangle(int triangle[], int size) {
  if (triangle == nullptr || size <= 0) {
    return -1;
  }

  int states[size * size];
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - i; ++j) {
      int min_sum = 0;
      if (i - 1 >= 0 && j - 1 >= 0) {
        if (states[(i - 1) * size + j] < states[i * size + j - 1]) {
          min_sum = states[(i - 1) * size + j];
        } else {
          min_sum = states[i * size + j - 1];
        }
      } else if (i - 1 >= 0) {
        min_sum = states[(i - 1) * size + j];
      } else if (j - 1 >= 0) {
        min_sum = states[i * size + j - 1];
      }
      states[i * size + j] = min_sum + triangle[i * size + j];
    }
  }

  int min = states[size - 1];
  for (int i = 1; i < size; ++i) {
    int j = size - i - 1;
    if (states[i * size + j] < min) {
      min = states[i * size + j];
    }
  }
  return min;
}