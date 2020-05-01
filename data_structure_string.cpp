//
// Created by Dan Jiang on 2020/4/18.
//

#include "data_structure_string.h"
#include <iostream>
#include <string>

enum Status { kValid = 0, kInvalid };
enum Status g_nStatus = kValid;

int StringToInt(const char *string, char min, char max, int start) {
  g_nStatus = kInvalid;

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
        g_nStatus = kValid;
      }
    }
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
char* LeftRotateString(char *string, int n) {
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

void ValidDigitToInt(const char *string) {
  int result = DigitToInt(string);
  if (result == 0 && g_nStatus == kInvalid) {
    std::cout << "the input " << (string == nullptr ? "nullptr" : string) << " is invalid." << std::endl;
  } else {
    std::cout << "number for " << string << " is: " << result << std::endl;
  }
}

void ValidAlphaToInt(const char *string) {
  int result = AlphaToInt(string);
  if (result == 0 && g_nStatus == kInvalid) {
    std::cout << "the input " << (string == nullptr ? "nullptr" : string) << " is invalid." << std::endl;
  } else {
    std::cout << "number for " << string << " is: " << result << std::endl;
  }
}

void ValidReverseSentence(char *input, const char *expected) {
  ReverseSentence(input);

  if((input == nullptr && expected == nullptr)
      || (input != nullptr && std::strcmp(input, expected) == 0)) {
    std::cout << (input == nullptr ? "nullptr" : input) << " is passed." << std::endl;
  } else {
    std::cout << (input == nullptr ? "nullptr" : input) << " is failed." << std::endl;
  }
}

void ValidLeftRotateString(char* input, int n, const char *expected) {
  LeftRotateString(input, n);

  if((input == nullptr && expected == nullptr)
      || (input != nullptr && std::strcmp(input, expected) == 0)) {
    std::cout << (input == nullptr ? "nullptr" : input) << " is passed." << std::endl;
  } else {
    std::cout << (input == nullptr ? "nullptr" : input) << " is failed." << std::endl;
  }
}
void TestDigitToInt() {
  ValidDigitToInt(nullptr);
  ValidDigitToInt("");
  ValidDigitToInt("123");
  ValidDigitToInt("+123");
  ValidDigitToInt("-123");
  ValidDigitToInt("1a33");
  ValidDigitToInt("+0");
  ValidDigitToInt("-0");
  ValidDigitToInt("+2147483647");
  ValidDigitToInt("-2147483647");
  ValidDigitToInt("+2147483648");
  ValidDigitToInt("-2147483648");
  ValidDigitToInt("+2147483649");
  ValidDigitToInt("-2147483649");
  ValidDigitToInt("+");
  ValidDigitToInt("-");
}

void TestAlphaToInt() {
  ValidAlphaToInt("A");
  ValidAlphaToInt("B");
  ValidAlphaToInt("Z");
  ValidAlphaToInt("AA");
  ValidAlphaToInt("AB");
  ValidAlphaToInt("AAA");
  ValidAlphaToInt("A1A");
}

void TestReverseSentence() {
  char input1[] = "I am a student.";
  char expected1[] = "student. a am I" ;
  ValidReverseSentence(input1, expected1);
  char input2[] = "Wonderful";
  char expected2[] = "Wonderful" ;
  ValidReverseSentence(input2, expected2);
  ValidReverseSentence(nullptr, nullptr);
  ValidReverseSentence("", "");
  char input3[] = "   ";
  char expected3[] = "    " ;
  ValidReverseSentence(input3, expected3);
}

void TestLeftRotateString() {
  char input1[] = "abcdefg";
  char expected1[] = "cdefgab" ;
  ValidLeftRotateString(input1, 2, expected1);
  char input2[] = "abcdefg";
  char expected2[] = "bcdefga" ;
  ValidLeftRotateString(input2, 1, expected2);
}
