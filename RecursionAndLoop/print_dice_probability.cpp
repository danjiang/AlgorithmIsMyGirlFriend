//
// Created by Dan Jiang on 2020/7/20.
//

#include "print_dice_probability.h"

#include <complex>
#include <iostream>

void DiceProbability(int number, int rest, int sum, int *probabilities) {
  if (rest == 1) {
    probabilities[sum - number]++;
  } else {
    for (int i = 1; i <= 6; i++) {
      DiceProbability(number, rest - 1, sum + i, probabilities);
    }
  }
}

void DiceProbability(int number, int *probabilities) {
  for (int i = 1; i <= 6; ++i) {
    DiceProbability(number, number, i, probabilities);
  }
}

void PrintDiceProbabilityRecursion(int number) {
  if (number < 1) {
    return;
  }

  int max_sum = number * 6;
  int *probabilities = new int[max_sum - number + 1];
  for (int i = number; i <= max_sum; ++i) {
    probabilities[i - number] = 0;
  }

  DiceProbability(number, probabilities);

  int total = std::pow(6, number);
  for (int i = number; i<= max_sum; ++i) {
    double ratio = (double)probabilities[i - number] / total;
    std::cout << i << " : " << ratio << std::endl;
  }
  delete [] probabilities;
}

void PrintDiceProbabilityLoop(int number) {
  if (number < 1) {
    return;
  }

  int max_sum = number * 6;
  int *probabilities[2];
  probabilities[0] = new int[max_sum + 1];
  probabilities[1] = new int[max_sum + 1];
  for (int i = 0; i < max_sum + 1; ++i) {
    probabilities[0][i] = 0;
    probabilities[1][i] = 0;
  }

  int flag = 0;
  for (int i = 1; i <= 6; ++i) {
    probabilities[flag][i] = 1;
  }
  for (int k = 2; k <= number; ++k) {
    for (int i = 0; i < k; ++i) { // 比当前点数最小值还小的都设置为 0
      probabilities[1 - flag][i] = 0;
    }
    for (int i = k; i <= 6 * k; ++i) {
      probabilities[1 - flag][i] = 0;
      for (int j = 1; j <= i && j <= 6; ++j) {
        probabilities[1 - flag][i] += probabilities[flag][i - j];
      }
    }
    flag = 1 - flag;
  }
  int total = std::pow(6, number);
  for (int i = number; i<= max_sum; ++i) {
    double ratio = (double)probabilities[flag][i] / total;
    std::cout << i << " : " << ratio << std::endl;
  }
  delete [] probabilities[0];
  delete [] probabilities[1];
}