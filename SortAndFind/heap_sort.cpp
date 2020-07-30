//
// Created by Dan Jiang on 2020/7/30.
//

#include "heap_sort.h"

#include "array_util.h"

void Heapify(int array[], int size, int index) {
  while (true) {
    int max = index;
    if ((index * 2 < size) && (array[max] < array[index * 2])) {
      max = index * 2;
    }
    if ((index * 2 + 1 < size) && (array[max] < array[index * 2 + 1])) {
      max = index * 2 + 1;
    }
    if (max == index) {
      break;
    }
    Swap(&array[index], &array[max]);
    index = max;
  }
}

void HeapSort(int array[], int size) {
  if (size <= 2) {
    return;
  }
  // build heap
  for (int i = (size - 1) / 2; i > 0; --i) {
    Heapify(array, size, i);
  }
  // sort
  for (int i = size - 1; i > 1; --i) {
    Swap(&array[1], &array[i]);
    Heapify(array, i, 1);
  }
}