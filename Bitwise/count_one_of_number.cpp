//
// Created by Dan Jiang on 2020/7/24.
//

#include "count_one_of_number.h"

int CountOneOfNumberNormal(int n) {
  int count = 0;
  unsigned int flag = 1;
  while (flag) {
    if (n & flag){
      count++;
    }
    flag = flag << 1;
  }
  return count;
}

int CountOneOfNumberBest(int n) {
  int count = 0;
  while (n) {
    ++count;
    n = (n - 1) & n;
  }
  return count;
}