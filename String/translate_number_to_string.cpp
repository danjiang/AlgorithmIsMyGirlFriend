//
// Created by Dan Jiang on 2020/8/4.
//

#include "translate_number_to_string.h"

#include <string>

int CountTranslatedNumberToString(const std::string &number) {
  int length = number.length();
  int next_next_count = 0;
  int next_count = 0;
  int count = 0;

  for (int i = length - 1; i >= 0; --i) {
    count = 0;
    if (i < length - 1) {
      count = next_count;
    } else {
      count = 1;
    }

    if (i < length - 1) {
      int digit = number[i] - '0';
      int next_digit = number[i + 1] - '0';
      int alpha = digit * 10 + next_digit;
      if (alpha >= 10 && alpha <= 25) {
        if (i < length - 2) {
          count += next_next_count;
        } else {
          count += 1;
        }
      }
    }

    if (i < length - 1) {
      next_next_count = next_count;
    }
    next_count = count;
  }

  return count;
}

int CountTranslatedNumberToString(int number) {
  if (number < 0) {
    return 0;
  }
  std::string number_in_string = std::to_string(number);
  return CountTranslatedNumberToString(number_in_string);
}