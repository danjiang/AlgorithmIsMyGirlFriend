//
// Created by Dan Jiang on 2020/8/9.
//

#include "max_value_of_gifts.h"

int MaxValueOfGifts(int matrix[], int rows, int columns) {
  if (matrix == nullptr || rows <= 0 || columns <= 0) {
    return -1;
  }

  int states[rows * columns];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      int max = 0;
      if (i - 1 >= 0 && j - 1 >= 0) {
        if (states[(i - 1) * columns + j] > states[i * columns + j - 1]) {
          max = states[(i - 1) * columns + j];
        } else {
          max = states[i * columns + j - 1];
        }
      } else if (i - 1 >= 0) {
        max = states[(i - 1) * columns + j];
      } else if (j - 1 >= 0) {
        max = states[i * columns + j - 1];
      }
      states[i * columns + j] = max + matrix[i * columns + j];
    }
  }
  return states[(rows - 1) * columns + columns - 1];
}