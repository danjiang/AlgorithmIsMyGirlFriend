//
// Created by Dan Jiang on 2020/8/4.
//

#include "simple_regular_expression.h"

#include <string>

bool SimpleRegularExpressionCore(char *string, char *pattern) {
  // both at end
  if (*string == '\0' && *pattern == '\0') {
    return true;
  }
  // string not at end, patten at end
  if (*string != '\0' && *pattern == '\0') {
    return false;
  }
  if (*(pattern + 1) == '*') {
    if (*string == *pattern || (*pattern == '.' && *string != '\0')) {
      return SimpleRegularExpressionCore(string + 1, pattern + 2) // bc b*
      || SimpleRegularExpressionCore(string + 1, pattern) // bb b*
      || SimpleRegularExpressionCore(string, pattern + 2);  // bbbba .*a*a
    } else {
      return SimpleRegularExpressionCore(string, pattern + 2); // a b*
    }
  } else if (*string == *pattern || (*pattern == '.' && *string != '\0')) {
    return SimpleRegularExpressionCore(string + 1, pattern + 1); // bc bc
  }
  return false;
}

bool SimpleRegularExpression(char *string, char *pattern) {
  if (string == nullptr || pattern == nullptr) {
    throw invalid_input("invalid input");
  }

  return SimpleRegularExpressionCore(string, pattern);
}