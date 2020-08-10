//
// Created by Dan Jiang on 2020/8/10.
//

#include "sum_of_numbers.h"

#include <string>
#include <iostream>

void SumTwoNumbersOfArray(int array[], int size, int sum, int *a, int *b) {
  if (array == nullptr || size <= 1 || sum <= 0) {
    throw invalid_input("invalid input");
  }

  int start = 0;
  int end = size - 1;
  while (start != end) {
    if (array[start] + array[end] == sum) {
      *a = array[start];
      *b = array[end];
      return;
    } else if (array[start] + array[end] < sum) {
      start++;
    } else {
      end--;
    }
  }

  throw not_found("cannot find two numbers");
}

void FindSumSequence(int sum) {
  if (sum <= 2) {
    throw invalid_input("invalid input");
  }

  int start = 1;
  int end = 2;
  int middle = (sum + 1) / 2;
  int current_sum = start + end;
  std::cout << std::endl;
  std::cout << "sum = " << sum << std::endl;
  while (start < middle) {
    if (current_sum == sum) {
      for (int i = start; i <= end; ++i) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
      end++;
      current_sum += end;
    } else if (current_sum > sum) {
      current_sum -= start;
      start++;
    } else {
      end++;
      current_sum += end;
    }
  }
}