//
// Created by Dan Jiang on 2020/8/9.
//

#include "longest_no_duplicate_substring.h"

#include <cstring>

int LongestNoDuplicateSubString(char *string) {
  if (string == nullptr) {
    return 0;
  }

  int positions[26];
  for (int i = 0; i < 26; ++i) {
    positions[i] = -1;
  }

  int length = std::strlen(string);
  int longest_length = 0;
  int current_length = 0;
  int duplicate_position = -1;
  int no_duplicate_start = 0;
  for (int i = 0; i < length; ++i) {
    duplicate_position = positions[string[i] - 'a'];
    if (duplicate_position >= 0 && duplicate_position >= no_duplicate_start) { // duplicate
      current_length = i - duplicate_position;
      no_duplicate_start = duplicate_position + 1;
    } else {
      current_length += 1;
    }
    positions[string[i] - 'a'] = i;
    if (current_length > longest_length) {
      longest_length = current_length;
    }
  }

  return longest_length;
}