//
// Created by Dan Jiang on 2020/7/29.
//

#include "print_one_to_max_of_n_digits.h"

#include <cstring>
#include <iostream>

void PrintNumber(char *number) {
  bool is_beginning_zero = true;
  int size = std::strlen(number);

  for (int i = 0; i < size; ++i) {
    if (is_beginning_zero && number[i] != '0') {
      is_beginning_zero = false;
    }
    if (!is_beginning_zero) {
      std::cout << number[i];
    }
  }
  std::cout << std::endl;
}

bool Increment(char *number) {
  bool is_overflow = false;
  int take_over = 0;
  int size = std::strlen(number);
  for (int i = size - 1; i >= 0; --i) {
    int sum = number[i] - '0' + take_over;
    take_over = 0;
    if (i == size - 1) {
      sum++;
    }
    if (sum >= 10) {
      if (i == 0) {
        is_overflow = true;
      } else {
        sum -= 10;
        take_over = 1;
        number[i] = '0' + sum;
      }
    } else {
      number[i] = '0' + sum;
    }
  }
  return is_overflow;
}

void PrintOneToMaxOfNDigitsIncrement(int n) {
  if (n <= 0) {
    return;
  }

  char *number = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    number[i] = '0';
  }
  number[n] = '\0';

  while (!Increment(number)) {
    PrintNumber(number);
  }

  delete[] number;
}

void PrintOneToMaxOfNDigitsRecursionCore(char *number, int size, int index) {
  if (index == size - 1) {
    PrintNumber(number);
    return;
  }
  for (int i = 0; i < 10; ++i) {
    number[index + 1] = i + '0';
    PrintOneToMaxOfNDigitsRecursionCore(number, size, index + 1);
  }
}

void PrintOneToMaxOfNDigitsRecursion(int n) {
  if (n <= 0) {
    return;
  }

  char *number = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    number[i] = '0';
  }
  number[n] = '\0';

  for (int i = 0; i < 10; ++i) {
    number[0] = i + '0';
    PrintOneToMaxOfNDigitsRecursionCore(number, n, 0);
  }

  delete[] number;
}