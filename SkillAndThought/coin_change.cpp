//
// Created by Dan Jiang on 2020/8/7.
//

#include "coin_change.h"

#include <limits>
#include <string>

int CoinChangeMemoCore(int money, int memo[], int coins[], int size) {
  if (money < coins[size - 1]) { // less than min coin
    throw invalid_input("cannot change coins");
  }
  if (memo[money] != -1) {
    return memo[money];
  }
  int min = std::numeric_limits<int>::max();
  for (int i = 0; i < size; ++i) {
    if (money == coins[i]) {
      return 1;
    }
    if (money - coins[i] > 0) {
      int rest_min = CoinChangeMemoCore(money - coins[i], memo, coins, size);
      if (rest_min < min) {
        min = rest_min;
      }
    }
  }
  min += 1;
  memo[money] = min;
  return min;
}

int CoinChangeMemo(int coins[], int size, int money) {
  if (coins == nullptr || size <= 0 || money <= 0) {
    return -1;
  }

  int memo[money + 1];
  for (int i = 0; i < money + 1; ++i) {
    memo[i] = -1;
  }

  return CoinChangeMemoCore(money, memo, coins, size);
}

int CoinChangeStates(int coins[], int size, int money) {
  if (coins == nullptr || size <= 0 || money <= 0) {
    return -1;
  }

  int states[(money + 1) * size];
  for (int i = 0; i < (money + 1) * size; ++i) {
    states[i] = -1;
  }
  for (int i = 0; i < size; ++i) {
    states[i] = 0;
  }

  for (int i = 1; i < money + 1; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i - coins[j] >= 0) {
        int min = std::numeric_limits<int>::max();
        for (int k = 0; k < size; ++k) {
          if (states[(i - coins[j]) * size + k] != -1
              && states[(i - coins[j]) * size + k] < min) {
            min = states[(i - coins[j]) * size + k];
          }
        }
        states[i * size + j] = 1 + min;
      }
    }
  }

  int min = states[money * size];
  for (int j = 1; j < size; ++j) {
    if (states[money * size + j] < min) {
      min = states[money * size + j];
    }
  }

  return min;
}