//
// Created by Dan Jiang on 2020/7/20.
//

#include "bubble_sort.h"
#include "array_util.h"

/*

First Pass

[ 5 1 4 2 8 ] -> [ 1 5 4 2 8 ], Here, algorithm compares the first two elements, and swaps since 5 > 1.

[ 1 5 4 2 8 ] -> [ 1 4 5 2 8 ], Swap since 5 > 4

[ 1 4 5 2 8 ] -> [ 1 4 2 5 8 ], Swap since 5 > 2

[ 1 4 2 5 8 ] -> [ 1 4 2 5 8 ], Now, since these elements are already in order (8 > 5), algorithm does not swap them.

 */
void BubbleSort(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    bool flag = false; // if swap?
    for (int j = 1; j < size - i; ++j) {
      if (array[j] < array[j - 1]) {
        Swap(&array[j], &array[j - 1]);
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
}
