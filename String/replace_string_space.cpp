//
// Created by Dan Jiang on 2020/8/4.
//

#include "replace_string_space.h"

#include <string>

void ReplaceStringSpace(char *string, int capacity) {
  if (string == nullptr || capacity <= 0) {
    throw invalid_input("invalid input");
  }

  int old_size = 0;
  int number_of_space = 0;
  int i = 0;
  while (string[i] != '\0') {
    old_size++;
    if (string[i] == ' ') {
      number_of_space++;
    }
    i++;
  }

  int new_size = old_size + number_of_space * 2;
  if (new_size > capacity) {
    throw invalid_input("capacity is not enough");
  }

  int old_index = old_size;
  int new_index = new_size;
  while (old_index >= 0 && old_index < new_index) {
    if (string[old_index] == ' ') {
      string[new_index--] = '0';
      string[new_index--] = '2';
      string[new_index--] = '%';
    } else {
      string[new_index--] = string[old_index];
    }
    old_index--;
  }
}