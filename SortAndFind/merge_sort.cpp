//
// Created by Dan Jiang on 2020/7/20.
//

#include "merge_sort.h"

void Merge(int array[], int start, int middle, int end) {
  int n1 = middle - start;
  int n2 = end - middle + 1;
  int left[n1];
  int i = 0;
  for (; i < n1; ++i) {
    left[i] = array[start + i];
  }
  int right[n2];
  int j = 0;
  for (; j < n2; ++j) {
    right[j] = array[middle + j];
  }
  i = 0;
  j = 0;
  int k = start;
  while (i < n1 && j < n2) {
    if (left[i] < right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }
  for (; i < n1; ++i) {
    array[k] = left[i];
    k++;
  }
  for (; j < n2; ++j) {
    array[k] = right[j];
    k++;
  }
}

// https://www.raywenderlich.com/741-swift-algorithm-club-swift-merge-sort
// O(nlogn) Fast sort, but needs a temporary "working" array equal in size to the array being sorted.
void MergeSort(int array[], int size, int start, int end) {
  if (start == end) {
    return;
  }
  int middle = start + (end - start + 1) / 2;
  MergeSort(array, size, start, middle - 1);
  MergeSort(array, size, middle, end);
  Merge(array, start, middle, end);
}

void MergeSort(int array[], int size) {
  MergeSort(array, size, 0, size - 1);
}
