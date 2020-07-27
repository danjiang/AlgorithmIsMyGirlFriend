//
// Created by Dan Jiang on 2020/7/27.
//

#include "string_to_int.h"

#include <string>

int StringToInt(const char *string, char min, char max, int start) {
  bool valid = false;
  int step = max - min + 1;
  long long number = 0;

  if (string != nullptr && *string != '\0') {
    bool minus = false;
    if (*string == '+') {
      string++;
    } else if (*string == '-') {
      string++;
      minus = true;
    }
    if (*string != '\0') {
      while (*string != '\0') {
        if (*string >= min && *string <= max) {
          int flag = minus ? -1 : 1;
          number = number * step + flag * (*string - min + start);
          if ((!minus && number > 0x7FFFFFFF)
              || (minus && number < (signed int)0x80000000)) {
            number = 0;
            break;
          }
          string++;
        } else {
          number = 0;
          break;
        }
      }
      if (*string == '\0') {
        valid = true;
      }
    }
  }

  if (!valid) {
    throw invalid_input("cannot convert to int");
  }

  return number;
}

// "1234" => 1234
int DigitToInt(const char *string) {
  return StringToInt(string, '0', '9', 0);
}

// A=1,B=2,C=3,...,Z=26,AA=27,AB=28
int AlphaToInt(const char *string) {
  return StringToInt(string, 'A', 'Z', 1);
}