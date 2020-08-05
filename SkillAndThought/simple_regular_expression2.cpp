//
// Created by Dan Jiang on 2020/8/5.
//

#include "simple_regular_expression2.h"

void SimpleRegularExpression2Core(char *string, char *pattern, bool *matched) {
  if (*matched) {
    return;
  }
  if (*pattern == '\0') {
    if (*string == '\0') {
      *matched = true;
    }
    return;
  }
  if (*pattern == '*') {
    // match any include zero
    while (*string != '\0') {
      SimpleRegularExpression2Core(string, pattern + 1, matched);
      string++;
    }
    SimpleRegularExpression2Core(string, pattern + 1, matched);
  } else if (*pattern == '?') {
    SimpleRegularExpression2Core(string, pattern + 1, matched); // match zero
    SimpleRegularExpression2Core(string + 1, pattern + 1, matched); // match one
  } else if (*string != '\0' && *string == *pattern) {
    SimpleRegularExpression2Core(string + 1, pattern + 1, matched); // match one
  }
}

bool SimpleRegularExpression2(char *string, char *pattern) {
  bool matched = false;
  SimpleRegularExpression2Core(string, pattern, &matched);
  return matched;
}
