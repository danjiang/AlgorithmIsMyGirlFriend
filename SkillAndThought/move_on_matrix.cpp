//
// Created by Dan Jiang on 2020/8/7.
//

#include "move_on_matrix.h"

#include <limits>

int MoveOnMatrix(int matrix[], int size) {
  if (matrix == nullptr || size <= 0) {
    return -1;
  }

  int states[size * size];
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      int min = 0;
      if (i - 1 >= 0 && j - 1 >= 0) {
        if (states[(i - 1) * size + j] < states[i * size + j - 1]) {
          min = states[(i - 1) * size + j];
        } else {
          min = states[i * size + j - 1];
        }
      } else if (i - 1 >= 0) {
        min = states[(i - 1) * size + j];
      } else if (j - 1 >= 0) {
        min = states[i * size + j - 1];
      }
      states[i * size + j] = min + matrix[i * size + j];
    }
  }
  return states[(size - 1) * size + size - 1];
}

int MoveOnMatrixMemoCore(int i, int j, int memo[], int matrix[], int size) {
  if (i == 0 && j == 0) {
    return matrix[0];
  }
  if (memo[i * size + j] != -1) {
    return memo[i * size + j];
  }
  int min = std::numeric_limits<int>::max();
  if (i - 1 >= 0) {
    int top = MoveOnMatrixMemoCore(i - 1, j, memo, matrix, size);
    if (top < min) {
      min = top;
    }
  }
  if (j - 1 >= 0) {
    int left = MoveOnMatrixMemoCore(i, j - 1, memo, matrix, size);
    if (left < min) {
      min = left;
    }
  }
  min += matrix[i * size + j];
  memo[i * size + j] = min;
  return min;
}

int MoveOnMatrixMemo(int matrix[], int size) {
  if (matrix == nullptr || size <= 0) {
    return -1;
  }

  int memo[size * size];
  for (int i = 0; i < size * size; ++i) {
    memo[i] = -1;
  }

  return MoveOnMatrixMemoCore(size - 1, size - 1, memo, matrix, size);
}