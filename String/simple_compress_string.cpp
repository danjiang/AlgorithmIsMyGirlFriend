//
// Created by Dan Jiang on 2020/8/20.
//

#include "simple_compress_string.h"

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
        output[out++] = '0' + count;
      }
      count = 1;
    } else {
      count++;
    }
    in++;
  }
  output[out++] = input[in - 1];
  if (count > 1) {
    output[out++] = '0' + count;
  }
  output[out] = '\0';
}