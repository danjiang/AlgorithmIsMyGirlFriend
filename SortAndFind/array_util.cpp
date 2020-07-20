//
// Created by Dan Jiang on 2020/7/20.
//

#include "array_util.h"

bool IsSameArray(int array1[], int array2[], int size) {
  if (array1 == nullptr || array2 == nullptr || size <= 0) {
    return false;
  }
  for (int i = 0; i < size; ++i) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }
  return true;
}

void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
