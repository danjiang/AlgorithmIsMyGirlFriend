//
// Created by Dan Jiang on 2020/8/9.
//

#include "cutting_rope.h"

#include <cmath>

int CuttingRopeDPStates(int length) {
  if (length < 2) {
    return 0;
  }
  if (length == 2) {
    return 1;
  }
  if (length == 3) {
    return 2;
  }
  int products[length + 1];
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;

  for (int i = 4; i <= length; ++i) {
    int max = 0;
    int product = 0;
    for (int j = 1; j <= i / 2; ++j) {
      product = products[j] * products[i - j];
      if (product > max) {
        max = product;
      }
    }
    products[i] = max;
  }

  return products[length];
}

int CuttingRopeGreedy(int length) {
  if (length < 2) {
    return 0;
  }
  if (length == 2) {
    return 1;
  }
  if (length == 3) {
    return 2;
  }

  int time3 = length / 3;
  if (length - time3 * 3 == 1) {
    time3 -= 1;
  }
  int time2 = (length - time3 * 3) / 2;

  return int(std::pow(3, time3) * std::pow(2, time2));
}