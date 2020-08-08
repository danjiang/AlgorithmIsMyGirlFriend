//
// Created by Dan Jiang on 2020/8/8.
//

#include "find_longest_add_one_subsequence.h"

#include <string>

void FindLongestAddOneSubsequence(int array[], int size, int *offset, int *length) {
  if (array == nullptr || size == 0) {
    throw invalid_input("invalid input");
  }
  if (size <= 1) {
    *offset = 0;
    *length = 1;
    return;
  }
  int max_offset = 0;
  int max_count = 1;
  int count = 1;
  int index = 1;
  while (index < size) {
    if (array[index - 1] + 1 == array[index]) {
      count++;
    } else {
      if (count > max_count) {
        max_count = count;
        max_offset = index - count;
      }
      count = 1;
    }
    index++;
  }
  index--;
  if (array[index - 1] + 1 == array[index]) {
    if (count > max_count) {
      max_count = count;
      max_offset = index - count + 1;
    }
  }
  *offset = max_offset;
  *length = max_count;
}