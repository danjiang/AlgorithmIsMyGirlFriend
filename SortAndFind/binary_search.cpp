//
// Created by Dan Jiang on 2020/7/21.
//

#include "binary_search.h"
#include <string>

int BinarySearchLoop(const int array[], int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) { // pay attention
    int middle = low + (high - low) / 2; // avoid overflow as mid = (low + high) / 2
    if (array[middle] == value) {
      return middle;
    } else if (value < array[middle]) {
      high = middle - 1; // pay attention
    } else {
      low = middle + 1; // pay attention
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int BinarySearchRecursionCore(const int array[], int low, int high, int value) {
  if (low > high) {
    throw not_found(std::to_string(value) + " is not found");
  }
  int middle = low + ((high - low) >> 1); // avoid overflow as mid = (low + high) / 2
  if (value == array[middle]) {
    return middle;
  } else if (value < array[middle]) {
    return BinarySearchRecursionCore(array, low, middle - 1, value);
  } else {
    return BinarySearchRecursionCore(array, middle + 1, high, value);
  }
}

int BinarySearchRecursion(const int array[], int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  return BinarySearchRecursionCore(array, 0, size - 1, value);
}

int BinarySearchFirstEQ(const int *array, int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] == value) {
      if (middle == 0 || array[middle - 1] != value) {
        return middle;
      } else {
        high = middle - 1;
      }
    } else if (value < array[middle]) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int BinarySearchLastEQ(const int *array, int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] == value) {
      if (middle == size - 1 || array[middle + 1] != value) {
        return middle;
      } else {
        low = middle + 1;
      }
    } else if (value < array[middle]) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int BinarySearchFirstGE(const int *array, int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] >= value) {
      if (middle == 0 || array[middle - 1] < value) {
        return middle;
      } else {
        high = middle - 1;
      }
    } else {
      low = middle + 1;
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}

int BinarySearchLastLE(const int array[], int size, int value) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middle = low + ((high - low) >> 1);
    if (array[middle] <= value) {
      if (middle == size - 1 || array[middle + 1] > value) {
        return middle;
      } else {
        low = middle + 1;
      }
    } else {
      high = middle - 1;
    }
  }

  throw not_found(std::to_string(value) + " is not found");
}