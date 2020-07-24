//
// Created by Dan Jiang on 2020/7/24.
//

#include "add_with_bitwise.h"

int AddWithBitwise(int num1, int num2) {
  int sum, carry;
  do {
    sum = num1 ^ num2;
    carry = (num1 & num2) << 1;
    num1 = sum;
    num2 = carry;
  } while (num2 != 0);
  return num1;
}