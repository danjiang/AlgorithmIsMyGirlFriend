//
// Created by Dan Jiang on 2020/7/20.
//

#include "array_util.h"

#include <iostream>
#include <cmath>

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

bool ArrayContain(int array[], int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == value) {
      return true;
    }
  }
  return false;
}

void PrintArray(int array[], int size) {
  std::cout << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void PrintHeapArray(int array[], int size) {
  std::cout << std::endl;
  for (int i = 1; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void PrintHeapTree(int array[], int size) {
  std::cout << std::endl;
  int i = 1;
  int max = 2;
  for (; i < size; ++i) {
    std::cout << array[i] << " ";
    if (i == max - 1) {
      max += max;
      std::cout << std::endl;
    }
  }
  if (i - 1 != max) {
    std::cout << std::endl;
  }
}