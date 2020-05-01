//
// Created by Dan Jiang on 2020/4/11.
//

#include "sort.h"
#include "common.h"

/*

First Pass

[ 5 1 4 2 8 ] -> [ 1 5 4 2 8 ], Here, algorithm compares the first two elements, and swaps since 5 > 1.

[ 1 5 4 2 8 ] -> [ 1 4 5 2 8 ], Swap since 5 > 4

[ 1 4 5 2 8 ] -> [ 1 4 2 5 8 ], Swap since 5 > 2

[ 1 4 2 5 8 ] -> [ 1 4 2 5 8 ], Now, since these elements are already in order (8 > 5), algorithm does not swap them.

 */

// O(n^2) Bad sorting algorithms, always need O(n^2).
void BubbleSort(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 1; j < size - i; ++j) {
      if (array[j] < array[j - 1]) {
        Swap(&array[j], &array[j - 1]);
      }
    }
  }
}

/*

[ 3, 5, 8, 4 | 6 ]   remember 4
           *

[ 3, 5, 8, 8 | 6 ]   shift 8 to the right
        --->

[ 3, 5, 5, 8 | 6 ]   shift 5 to the right
     --->

[ 3, 4, 5, 8 | 6 ]   copy 4 into place
     *

 */

// O(n^2) Basic sort, is really fast if the array is already sorted and is actually very fast for sorting small arrays.
void InsertionSort(int array[], int size) {
  if (size <= 1) {
    return;
  }
  for (int i = 1; i < size; ++i) {
    int j = i;
    int temp = array[j];
    while (j > 0 && temp < array[j - 1]) {
      array[j] = array[j - 1];
      --j;
    }
    array[j] = temp;
  }
}

/*
[ values <= pivot |  values > pivot  | not looked at yet | pivot ]
  start     small   small+1  index-1   index       end-1   end
 */
int Partition(int array[], int size, int start, int end) {
  int index = start + (end - start + 1) / 2;
  Swap(&array[index], &array[end]);
  int small = start - 1;
  for (index = start; index < end; ++index) {
    if (array[index] < array[end]) {
      ++small;
      if (small != index) {
        Swap(&array[small], &array[index]);
      }
    }
  }
  ++small;
  Swap(&array[small], &array[end]);
  return small;
}

// O(n log n) Fast sort, in-place sort.
void QuickSort(int array[], int size, int start, int end) {
  if (start == end) {
    return;
  }
  int index = Partition(array, size, start, end);
  if (index > start) {
    QuickSort(array, size, start, index - 1);
  }
  if (index < end) {
    QuickSort(array, size, index + 1, end);
  }
}

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
// O(n log n) Fast sort, but needs a temporary "working" array equal in size to the array being sorted.
void MergeSort(int array[], int size, int start, int end) {
  if (start == end) {
    return;
  }
  int middle = start + (end - start + 1) / 2;
  MergeSort(array, size, start, middle - 1);
  MergeSort(array, size, middle, end);
  Merge(array, start, middle, end);
}

void TestBubbleSort() {
  int array[] = {5, 1, 4, 2, 8};
  int size = 5;
  BubbleSort(array, size);
  PrintArray(array, size);
}

void TestInsertionSort() {
  int array[] = {5, 1, 4, 2, 8};
  int size = 5;
  InsertionSort(array, size);
  PrintArray(array, size);
}

void TestQuickSort() {
  int array[] = {5, 1, 4, 2, 8};
  int size = 5;
  QuickSort(array, size, 0, size - 1);
  PrintArray(array, size);
}

void TestMergeSort() {
  int array[] = {5, 1, 4, 2, 8};
  int size = 5;
  MergeSort(array, size, 0, size - 1);
  PrintArray(array, size);
}
