//
// Created by Dan Jiang on 2020/7/20.
//

#include "fibonacci.h"

int FibonacciRecursion(int n) { // f(n) = f(n - 1) + f(n - 2)
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

int FibonacciLoop(int n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  int f_n_2 = 0;
  int f_n_1 = 1;
  int f_n = 0;
  for (int i = 2; i <= n; i++) {
    f_n = f_n_1 + f_n_2;
    f_n_2 = f_n_1;
    f_n_1 = f_n;
  }
  return f_n;
}