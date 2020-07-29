//
// Created by Dan Jiang on 2020/7/29.
//

#include "power.h"

#include <string>

bool equal(double num1, double num2) {
  return (num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
  if (exponent == 0) {
    return 1;
  }
  if (exponent == 1) {
    return base;
  }
  double result = PowerWithUnsignedExponent(base, exponent >> 1);
  result *= result;
  if ((exponent & 0x1) == 1) {
    result *= base;
  }
  return result;
}

double Power(double base, int exponent) {
  if (equal(base, 0.0) && exponent <= 0) {
    throw invalid_input("invalid input");
  }

  unsigned int abs_exponent = (unsigned int)exponent;
  if (exponent < 0) {
    abs_exponent = (unsigned int)(-exponent);
  }
  double result = PowerWithUnsignedExponent(base, abs_exponent);
  if (exponent < 0) {
    result = 1.0 / result;
  }
  return result;
}
