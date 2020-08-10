//
// Created by Dan Jiang on 2020/8/10.
//

#include "josephuse_circle.h"

#include <string>

int JosephuseCircle(int n, int m) {
  if (n <= 0 || m <= 0) {
    throw invalid_input("invalid input");
  }

  int last = 0;
  for (int i = 2; i <= n; ++i) {
    last = (last + m) % i;
  }
  return last;
}