//
// Created by Dan Jiang on 2020/4/18.
//

#include "data_structure_string.h"
#include <cstdio>
#include <string>

enum Status { kValid = 0, kInvalid };
enum Status g_nStatus = kValid;

int StrToInt(const char *str, char min, char max, int start) {
    g_nStatus = kInvalid;

    int step = max - min + 1;
    long long num = 0;

    if (str != nullptr && *str != '\0') {
        bool minus = false;
        if (*str == '+') {
            str++;
        } else if (*str == '-') {
            str++;
            minus = true;
        }
        if (*str != '\0') {
            while (*str != '\0') {
                if (*str >= min && *str <= max) {
                    int flag = minus ? -1 : 1;
                    num = num * step + flag * (*str - min + start);
                    if ((!minus && num > 0x7FFFFFFF)
                        || (minus && num < (signed int)0x80000000)) {
                        num = 0;
                        break;
                    }
                    str++;
                } else {
                    num = 0;
                    break;
                }
            }
            if (*str == '\0') {
                g_nStatus = kValid;
            }
        }
    }

    return num;
}

// "1234" => 1234
int DigitToInt(const char *str) {
   return StrToInt(str, '0', '9', 0);
}

// A=1,B=2,C=3,...,Z=26,AA=27,AB=28
int AlphaToInt(const char *str) {
    return StrToInt(str, 'A', 'Z', 1);
}

// reverse C-Style character string
void Reverse(char *pBegin, char *pEnd) {
    if (pBegin == nullptr || pEnd == nullptr) {
        return;
    }

    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }
}

// "I am a student." => "student a am I"
char* ReverseSentence(char *pData) {
    if (pData == nullptr) {
        return nullptr;
    }

    char *pBegin = pData;
    char *pEnd = pData;
    while (*pEnd != '\0') {
        pEnd++;
    }
    pEnd--;

    // reverse whole sentence
    Reverse(pBegin, pEnd);

    // reverse each word
    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        } else {
            pEnd++;
        }
    }

    return pData;
}

// "abcdefg" 2 => "cdefgab"
char* LeftRotateString(char *pStr, int n) {
    if (pStr != nullptr) {
        int nLength = static_cast<int>(std::strlen(pStr));
        if (nLength > 0 && n > 0 && n < nLength) {
            char *pFirstStart = pStr;
            char *pFirstEnd = pStr + n - 1;
            char *pSecondStart = pStr + n;
            char *pSecondEnd = pStr + nLength - 1;

            // reverse first part of string
            Reverse(pFirstStart, pFirstEnd);
            // reverse second part of string
            Reverse(pSecondStart, pSecondEnd);
            // reverse whole string
            Reverse(pFirstStart, pSecondEnd);
        }
    }
}

void ValidDigitToInt(const char *str) {
    int result = DigitToInt(str);
    if (result == 0 && g_nStatus == kInvalid) {
        printf("the input %s is invalid.\n", str);
    } else {
        printf("number for %s is: %d.\n", str, result);
    }
}

void ValidAlphaToInt(const char *str) {
    int result = AlphaToInt(str);
    if (result == 0 && g_nStatus == kInvalid) {
        printf("the input %s is invalid.\n", str);
    } else {
        printf("number for %s is: %d.\n", str, result);
    }
}

void ValidReverseSentence(char* input, const char* expectedResult) {
    ReverseSentence(input);

    if((input == nullptr && expectedResult == nullptr)
       || (input != nullptr && std::strcmp(input, expectedResult) == 0))
        printf("result:%s\nPassed.\n", input);
    else
        printf("result:%s\nFailed.\n", input);
}

void ValidLeftRotateString(char* input, int n, const char* expectedResult) {
    LeftRotateString(input, n);

    if((input == nullptr && expectedResult == nullptr)
       || (input != nullptr && std::strcmp(input, expectedResult) == 0))
        printf("result:%s\nPassed.\n", input);
    else
        printf("result:%s\nFailed.\n", input);
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
