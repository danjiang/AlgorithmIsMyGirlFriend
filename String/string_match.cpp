//
// Created by Dan Jiang on 2020/8/3.
//

#include "string_match.h"

#include <cstring>
#include <string>

void GenerateBadCharacter(char *pattern, int length, int *hash_table, int size) {
  for (int i = 0; i < size; ++i) {
    hash_table[i] = -1;
  }
  for (int i = 0; i < length; ++i) {
    hash_table[pattern[i]] = i;
  }
}

void GenerateGoodSuffix(char *pattern, int *suffix, bool *prefix, int size) {
  for (int i = 0; i < size; ++i) {
    suffix[i] = -1;
    prefix[i] = false;
  }
  for (int i = 0; i < size - 1; ++i) {
    int start_index = i;
    int suffix_length = 0;
    while (start_index >= 0 && pattern[start_index] == pattern[size - 1 - suffix_length]) {
      start_index--;
      suffix_length++;
      suffix[suffix_length] = start_index + 1;
    }
    if (start_index == -1) {
      prefix[suffix_length] = true;
    }
  }
}

int MoveByGoodSuffix(int index_of_string, int pattern_length, int *suffix, bool *prefix) {
  int suffix_length = pattern_length - 1 - index_of_string;
  if (suffix[suffix_length] != -1) {
    return index_of_string + 1 - suffix[suffix_length];
  }
  for (int start_index = index_of_string + 2; start_index <= pattern_length - 1; ++start_index) {
    if (prefix[pattern_length - start_index] == true) {
      return start_index;
    }
  }
  return pattern_length;
}

int StringMatchBM(char *string, char *pattern) {
  if (string == nullptr || pattern == nullptr) {
    throw invalid_input("invalid input");
  }
  int string_length = std::strlen(string);
  int pattern_length = std::strlen(pattern);
  if (string_length < pattern_length) {
    throw invalid_input("invalid input");
  }

  int size = 256;
  int hash_table[size];
  GenerateBadCharacter(pattern, pattern_length, hash_table, size);

  int suffix[pattern_length];
  bool prefix[pattern_length];
  GenerateGoodSuffix(pattern, suffix, prefix, pattern_length);

  int index_of_string = 0;
  while (index_of_string <= string_length - pattern_length) {
    int index_of_pattern = pattern_length - 1;
    for (; index_of_pattern >= 0; --index_of_pattern) {
      if (string[index_of_string + index_of_pattern] != pattern[index_of_pattern]) { // got bad character
        break;
      }
    }
    if (index_of_pattern < 0) { // match
      return index_of_string;
    }
    int bad_move = index_of_pattern - hash_table[string[index_of_string + index_of_pattern]];
    int good_move = 0;
    if (index_of_pattern < pattern_length - 1) { // got good suffix
      good_move = MoveByGoodSuffix(index_of_string, pattern_length, suffix, prefix);
    }
    if (bad_move > good_move) {
      index_of_string += bad_move;
    } else {
      index_of_string += good_move;
    }
  }

  throw not_found("pattern is not found in string");
}

void GenerateNext(char *pattern, int *next, int size) {
  next[0] = -1;
  int prefix_index = -1; // last character index of max match prefix string
  for (int i = 1; i < size; ++i) {
    while (prefix_index != -1 && pattern[prefix_index + 1] != pattern[i]) {
      prefix_index = next[prefix_index]; // shorten length of max match prefix string
    }
    if (pattern[prefix_index + 1] == pattern[i]) {
      ++prefix_index;
    }
    next[i] = prefix_index;
  }
}

int StringMatchKMP(char *string, char *pattern) {
  if (string == nullptr || pattern == nullptr) {
    throw invalid_input("invalid input");
  }
  int string_length = std::strlen(string);
  int pattern_length = std::strlen(pattern);
  if (string_length < pattern_length) {
    throw invalid_input("invalid input");
  }

  int next[pattern_length];
  GenerateNext(pattern, next, pattern_length);

  int index_of_pattern = 0; // index of pattern is align with index of string
  for (int index_of_string = 0; index_of_string < string_length; ++index_of_string) {
    while (index_of_pattern > 0 && string[index_of_string] != pattern[index_of_pattern]) {
      index_of_pattern = next[index_of_pattern - 1] + 1;
    }
    if (string[index_of_string] == pattern[index_of_pattern]) {
      ++index_of_pattern;
    }
    if (index_of_pattern == pattern_length) {
      return index_of_string - pattern_length + 1;
    }
  }

  throw not_found("pattern is not found in string");
}