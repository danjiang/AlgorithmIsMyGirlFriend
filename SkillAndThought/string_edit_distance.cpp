//
// Created by Dan Jiang on 2020/8/8.
//

#include "string_edit_distance.h"

#include <cstring>
#include <string>

int LevenshteinDistanceMin(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}

int LevenshteinDistance(char *string1, char *string2) {
  if (string1 == nullptr || string2 == nullptr) {
    throw invalid_input("invalid input");
  }

  int columns = std::strlen(string1) + 1;
  int rows = std::strlen(string2) + 1;
  int states[rows * columns];

  for (int i = 0; i < rows; ++i) {
    states[i * columns] = i;
  }
  for (int j = 0; j < columns; ++j) {
    states[j] = j;
  }

  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < columns; ++j) {
      if (string1[j - 1] == string2[i - 1]) {
        states[i * columns + j] = LevenshteinDistanceMin(states[(i - 1) * columns + j] + 1,
                                                         states[i * columns + j - 1] + 1,
                                                         states[(i - 1) * columns + j - 1]); // no +1
      } else {
        states[i * columns + j] = LevenshteinDistanceMin(states[(i - 1) * columns + j] + 1,
                                                         states[i * columns + j - 1] + 1,
                                                         states[(i - 1) * columns + j - 1] + 1); // do +1
      }
    }
  }

  return states[(rows - 1) * columns + columns - 1];
}

int LongestCommonSubsequenceMax(int a, int b) {
  return a > b ? a : b;
}

int LongestCommonSubsequence(char *string1, char *string2) {
  if (string1 == nullptr || string2 == nullptr) {
    throw invalid_input("invalid input");
  }

  int columns = std::strlen(string1) + 1;
  int rows = std::strlen(string2) + 1;
  int states[rows * columns];

  for (int i = 0; i < rows; ++i) {
    states[i * columns] = 0;
  }
  for (int j = 0; j < columns; ++j) {
    states[j] = 0;
  }

  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < columns; ++j) {
      if (string1[j - 1] == string2[i - 1]) {
        states[i * columns + j] = states[(i - 1) * columns + j - 1] + 1; // top left +1
      } else {
        states[i * columns + j] = LongestCommonSubsequenceMax(states[(i - 1) * columns + j],
                                                              states[i * columns + j - 1]); // max of top or left
      }
    }
  }

  return states[(rows - 1) * columns + columns - 1];
}