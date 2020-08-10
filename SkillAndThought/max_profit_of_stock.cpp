//
// Created by Dan Jiang on 2020/8/10.
//

#include "max_profit_of_stock.h"

#include <string>
#include <limits>

int MaxProfitOfStock(int array[], int size) {
  if (array == nullptr || size <= 0) {
    throw invalid_input("invalid input");
  }
  if (size == 1) {
    return 0;
  }

  int min = array[0];
  int max_profit = std::numeric_limits<int>::min();
  for (int i = 1; i < size; ++i) {
    int profit = array[i] - min;
    if (profit > max_profit) {
      max_profit = profit;
    }
    if (array[i] < min) {
      min = array[i];
    }
  }

  return max_profit;
}