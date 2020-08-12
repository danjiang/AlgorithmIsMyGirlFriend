//
// Created by Dan Jiang on 2020/7/27.
//

#include "char_hash_table.h"

#include <limits>

char FindFirstNotRepeatChar(const char *string) {
  if (string == nullptr) {
    return '\0';
  }

  const int size = 256;
  unsigned int hash_table[size];
  for (int i = 0; i < size; ++i) {
    hash_table[i] = 0;
  }

  const char *key = string;
  while (*key != '\0') {
    hash_table[*key]++;
    key++;
  }

  key = string;
  while (*key != '\0') {
    if (hash_table[*key] == 1) {
      return *key;
    }
    key++;
  }

  return '\0';
}

CharStatistics::CharStatistics(): index(0) {
  for (int i = 0; i < 256; ++i) {
    occurrence[i] = -1;
  }
}

void CharStatistics::Insert(char ch) {
  if (occurrence[ch] == -1) { // the character has not found
    occurrence[ch] = index;
  } else if (occurrence[ch] >= 0) { // the character has been found only once
    occurrence[ch] = -2; // the character has been found for multiple times
  }
  index++;
}

char CharStatistics::FirstAppearingOnce() {
  char ch = '\0';
  int min_index = std::numeric_limits<int>::max();
  for (int i = 0; i < 256; ++i) {
    if (occurrence[i] >= 0 && occurrence[i] < min_index) {
      ch = (char)i;
      min_index = occurrence[i];
    }
  }
  return ch;
}
