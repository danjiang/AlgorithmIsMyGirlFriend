//
// Created by Dan Jiang on 2020/7/20.
//

#include "selection_sort.h"
#include "array_util.h"

void SelectionSort(int array[], int size) {
  if (size <= 1) {
    return;
  }
  for (int i = 0; i < size - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < size; ++j) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (min != i) {
      Swap(&array[min], &array[i]);
    }
  }
}