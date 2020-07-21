//
// Created by Dan Jiang on 2020/7/21.
//

#include "sqrt_binary_search.h"

double SqrtBinarySearch(double value, double precision) {
  double low, high, middle, square;
  if (value > 1) {
    low = 1;
    high = value;
  } else {
    low = value;
    high = 1;
  }
  while (low <= high) {
    middle = low + (high - low) / 2.0;
    square = middle * middle;
    if (square - value <= precision && square - value >= -precision) {
      return middle;
    } else if (square > value) {
      high = middle;
    } else {
      low = middle;
    }
  }
}
