//
// Created by Dan Jiang on 2020/7/20.
//

#include "insertion_sort.h"

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
void InsertionSort(int array[], int size) {
  if (size <= 1) {
    return;
  }
  for (int i = 1; i < size; ++i) {
    int j = i;
    int temp = array[j];
    while (j > 0) {
      if (temp < array[j - 1]) {
        array[j] = array[j - 1];
      } else {
        break;
      }
      --j;
    }
    array[j] = temp;
  }
}