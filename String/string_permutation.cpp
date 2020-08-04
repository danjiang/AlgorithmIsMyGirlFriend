//
// Created by Dan Jiang on 2020/8/4.
//

#include "string_permutation.h"

#include <iostream>

void StringPermutation(char *string, char *begin) {
  if (*begin == '\0') {
    std::cout << string << std::endl;
  } else {
    char *ch = begin;
    while (*ch != '\0') {
      char temp = *ch;
      *ch = *begin;
      *begin = temp;

      StringPermutation(string, begin + 1);

      temp = *ch;
      *ch = *begin;
      *begin = temp;

      ch++;
    }
  }
}

void StringPermutation(char *string) {
  if (string == nullptr) {
    throw invalid_input("invalid input");
  }
  StringPermutation(string, string);
}
