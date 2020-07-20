//
// Created by Dan Jiang on 2020/7/20.
//

#include "quick_sort.h"
#include "array_util.h"

/*
[ values <= pivot |  values > pivot  | not looked at yet | pivot ]
  start     small   small+1  index-1   index       end-1   end
 */
int Partition(int array[], int start, int end) {
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
  int index = Partition(array, start, end);
  if (index > start) {
    QuickSort(array, size, start, index - 1);
  }
  if (index < end) {
    QuickSort(array, size, index + 1, end);
  }
}