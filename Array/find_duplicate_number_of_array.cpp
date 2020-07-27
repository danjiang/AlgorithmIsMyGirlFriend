//
// Created by Dan Jiang on 2020/7/27.
//

#include "find_duplicate_number_of_array.h"

#include <string>
#include "array_util.h"

int FindDuplicateNumberOfArrayEdit(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }

  for (int i = 0; i < size; ++i) {
    if (array[i] < 0 || array[i] > size - 1) {
      throw invalid_input("invalid input");
    }
  }

  for (int i = 0; i < size; ++i) {
    while (array[i] != i) {
      if (array[i] == array[array[i]]) {
        return array[i];
      }

      Swap(&array[i], &array[array[i]]);
    }
  }

  throw not_found("no duplicate");
}

int CountRange(int array[], int size, int low, int high) {
  if (array == nullptr) {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (array[i] >= low && array[i] <= high) {
      count++;
    }
  }
  return count;
}

int FindDuplicateNumberOfArrayNoEdit(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }

  int low = 1;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    int count = CountRange(array, size, low, middle);
    if (low == high) {
      if (count > 1) {
        return low;
      } else {
        break;
      }
    }
    if (count > middle - low + 1) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }

  throw not_found("no duplicate");
}
