//
// Created by Dan Jiang on 2020/7/27.
//

#include "reverse_string.h"

#include <string>

// reverse C-Style character string
void Reverse(char *begin, char *end) {
  if (begin == nullptr || end == nullptr) {
    return;
  }

  while (begin < end) {
    char temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
  }
}

// "I am a student." => ".student a am I"
char* ReverseSentence(char *string) {
  if (string == nullptr) {
    return nullptr;
  }

  char *begin = string;
  char *end = string;
  while (*end != '\0') {
    end++;
  }
  end--;

  // reverse whole sentence
  Reverse(begin, end);

  // reverse each word
  begin = end = string;
  while (*begin != '\0') {
    if (*begin == ' ') {
      begin++;
      end++;
    } else if (*end == ' ' || *end == '\0') {
      Reverse(begin, --end);
      begin = ++end;
    } else {
      end++;
    }
  }

  return string;
}

// "abcdefg" 2 => "cdefgab"
void LeftRotateString(char *string, int n) {
  if (string != nullptr) {
    int size = static_cast<int>(std::strlen(string));
    if (size > 0 && n > 0 && n < size) {
      char *first_start = string;
      char *first_end = string + n - 1;
      char *second_start = string + n;
      char *second_end = string + size - 1;

      // reverse first part of string
      Reverse(first_start, first_end);
      // reverse second part of string
      Reverse(second_start, second_end);
      // reverse whole string
      Reverse(first_start, second_end);
    }
  }
}