//
// Created by Dan Jiang on 2020/7/27.
//

#include "divide_array.h"

#include <string>
#include "array_util.h"

void DivideArrayFunc(int array[], int size, bool (*func)(int)) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }

  int index_of_first_part = -1;
  for (int i = 0; i < size; ++i) {
    if (func(array[i])) {
      index_of_first_part++;
      if (index_of_first_part != i) {
        Swap(&array[index_of_first_part], &array[i]);
      }
    }
  }
}

bool isOdd(int n) {
  return n % 2 == 1;
}

void DivideArray(int array[], int size) {
  DivideArrayFunc(array, size, isOdd);
}