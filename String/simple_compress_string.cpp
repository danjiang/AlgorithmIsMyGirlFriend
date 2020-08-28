//
// Created by Dan Jiang on 2020/8/20.
//

#include "simple_compress_string.h"

char* Int2String(int number) {
  int size = 1;
  int new_number = number / 10;
  while (new_number > 0) {
    size++;
    new_number /= 10;
  }
  char *string = new char[size + 1];
  string[size] = '\0';
  for (int i = size - 1; i >= 0; --i) {
    string[i] = '0' + number % 10;
    number /= 10;
  }
  return string;
}

void SimpleCompressString(const char *input, char *output) {
  if (input == nullptr) {
    return;
  }
  int out = 0;
  int in = 1;
  int count = 1;
  if (input[in] == '\0') {
    output[out++] = *input;
    output[out] = '\0';
    return;
  }
  while (input[in] != '\0') {
    if (input[in] != input[in - 1]) {
      output[out++] = input[in - 1];
      if (count > 1) {
        char *number = Int2String(count);
        int index = 0;
        while (number[index] != '\0') {
          output[out++] = number[index++];
        }
        delete number;
      }
      count = 1;
    } else {
      count++;
    }
    in++;
  }
  output[out++] = input[in - 1];
  if (count > 1) {
    char *number = Int2String(count);
    int index = 0;
    while (number[index] != '\0') {
      output[out++] = number[index++];
    }
    delete number;
  }
  output[out] = '\0';
}

std::string ZipString(std::string string) {
  int size = string.length();
  if (size == 1) {
    return string;
  }
  const char *input = string.c_str();
  char output[size + 1];  // size with null-terminated byte
  int in = 1;
  int count = 1;
  int out = 0;
  while (in < size && out < size) {
    if (input[in] != input[in - 1]) {
      output[out++] = input[in - 1];
      char *number = Int2String(count);
      int index = 0;
      while (number[index] != '\0') {
        if (out < size) {
          output[out++] = number[index++];
        } else {
          break;
        }
      }
      delete number;
      count = 1;
    } else {
      count++;
    }
    in++;
  }
  if (in == size && out < size) {
    output[out++] = input[in - 1];
    char *number = Int2String(count);
    int index = 0;
    while (number[index] != '\0') {
      if (out < size) {
        output[out++] = number[index++];
      } else {
        break;
      }
    }
    delete number;
    output[out] = '\0';
    return std::string(output);
  } else {
    return string;
  }
}