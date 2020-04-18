//
// Created by Dan Jiang on 2020/4/18.
//

#include "data_structure_string.h"
#include <cstdio>

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

