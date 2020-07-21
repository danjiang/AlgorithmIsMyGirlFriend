//
// Created by Dan Jiang on 2020/7/21.
//

#include "counting_sort.h"

void CountingSort(int array[], int size) {
  if (size <= 1) {
    return;
  }

  int max = array[0];
  for (int i = 1; i < size; ++i) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  int count_array[max + 1];
  for (int i = 0; i < max + 1; ++i) {
    count_array[i] = 0;
  }

  for (int i = 0; i < size; ++i) {
    count_array[array[i]]++;
  }

  for (int i = 1; i < max + 1; ++i) {
    count_array[i] = count_array[i] + count_array[i - 1];
  }

  int sorted_array[size];
  for (int i = size - 1; i >= 0; --i) {
    sorted_array[count_array[array[i]] - 1] = array[i];
    count_array[array[i]]--;
  }

  for (int i = 0; i < size; ++i) {
    array[i] = sorted_array[i];
  }
}