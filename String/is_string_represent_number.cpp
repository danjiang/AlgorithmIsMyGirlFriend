//
// Created by Dan Jiang on 2020/7/29.
//

#include "is_string_represent_number.h"

bool ScanUnsignedInteger(const char **string) {
  const char *before = *string;
  while (**string != '\0' && **string >= '0' && **string <= '9') {
    (*string)++;
  }
  return *string > before;
}

bool  ScanInteger(const char **string) {
  if (**string == '+' || **string == '-') {
    (*string)++;
  }
  return ScanUnsignedInteger(string);
}

bool IsStringRepresentNumber(const char *string) {
  if (string == nullptr) {
    return false;
  }

  bool numeric = ScanInteger(&string); // A part

  if (*string == '.') { // B part
    ++string;
    numeric = ScanUnsignedInteger(&string) || numeric;
  }

  if (*string == 'e' || *string == 'E') { // C part
    ++string;
    numeric = numeric && ScanInteger(&string);
  }

  return numeric && *string == '\0';
}