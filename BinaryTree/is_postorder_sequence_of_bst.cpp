//
// Created by Dan Jiang on 2020/6/7.
//

#include "is_postorder_sequence_of_bst.h"

bool IsPostorderSequenceOfBST(int *sequence, int length) {
  if (sequence == nullptr || length <= 0) {
    return false;
  }

  int root = sequence[length - 1];

  int i = 0;
  for (; i < length - 1; ++i) {
    if (sequence[i] > root) {
      break;
    }
  }

  int j = i;
  for (; j < length - 1; ++j) {
    if (sequence[j] < root) {
      return false;
    }
  }

  bool left = true;
  if (i > 0) {
    left = IsPostorderSequenceOfBST(sequence, i);
  }

  bool right = true;
  if (i < length - 1) {
    right = IsPostorderSequenceOfBST(sequence + i, length - i - 1);
  }

  return left && right;
}
