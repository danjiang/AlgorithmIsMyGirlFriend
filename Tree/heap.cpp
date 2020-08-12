//
// Created by Dan Jiang on 2020/7/30.
//

#include "heap.h"

#include <string>
#include <iostream>
#include "array_util.h"

HeapInArray::HeapInArray(int length) {
  size = length + 1;
  index = 1;
  array = new int[size];
}

void HeapInArray::Insert(int value) {
  if (index < size) {
    int child = index;
    array[index] = value;
    index++;

    while (child / 2 > 0 && array[child] > array[child / 2]) {
      Swap(&array[child], &array[child / 2]);
      child /= 2;
    }
  } else {
    throw invalid_operation("heap is full");
  }
}

void HeapInArray::RemoveTop() {
  if (index > 1) {
    int parent = 1;
    Swap(&array[index - 1], &array[parent]);
    index--;
    while (true) {
      int max = parent;
      if ((parent * 2 < index) && (array[max] < array[parent * 2])) {
        max = parent * 2;
      }
      if ((parent * 2 + 1 < index) && (array[max] < array[parent * 2 + 1])) {
        max = parent * 2 + 1;
      }
      if (max == parent) {
        break;
      }
      Swap(&array[parent], &array[max]);
      parent = max;
    }
  } else {
    throw invalid_operation("heap is empty");
  }
}

int HeapInArray::Top() {
  if (index > 1) {
    return array[1];
  } else {
    throw invalid_operation("heap is empty");
  }
}

void HeapInArray::PrintArray() {
  PrintHeapArray(array, index);
}

void HeapInArray::PrintTree() {
  PrintHeapTree(array, index);

}
