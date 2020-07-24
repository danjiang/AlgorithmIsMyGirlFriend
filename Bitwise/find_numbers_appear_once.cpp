//
// Created by Dan Jiang on 2020/7/24.
//

#include "find_numbers_appear_once.h"

#include <string>

unsigned int FindFirstBitIsOne(int num) {
  int index = 0;
  while (((num & 1) == 0) && (index < 8 * sizeof(int ))) {
    num = num >> 1;
    ++index;
  }
  return index;
}

bool IsBitOne(int num, unsigned int index) {
  num = num >> index;
  return (num & 1);
}

void FindNumbersAppearOnce(int array[], int size, int *num1, int *num2) {
  if (array == nullptr || size < 2) {
    throw invalid_input("invalid input");
  }

  int xor_result = 0;
  for (int i = 0; i < size; i++) {
    xor_result ^= array[i];
  }

  unsigned int index_of_one = FindFirstBitIsOne(xor_result);

  *num1 = 0;
  *num2 = 0;
  for (int i = 0; i < size; ++i) {
    if (IsBitOne(array[i], index_of_one)) {
      *num1 ^= array[i];
    } else {
      *num2 ^= array[i];
    }
  }
}

int FindNumberAppearOnce(int array[], int size) {
  if (array == nullptr || size < 2) {
    throw invalid_input("invalid input");
  }

  int bits_sum[32] = { 0 };
  for (int i = 0; i < size; ++i) {
    int bit_mask = 1;
    for (int j = 31; j >= 0; --j) {
      int bit = array[i] & bit_mask;
      if (bit != 0) {
        bits_sum[j] += 1;
      }
      bit_mask = bit_mask << 1;
    }
  }
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    result = result << 1;
    result += bits_sum[i] % 3;
  }
  return result;
}