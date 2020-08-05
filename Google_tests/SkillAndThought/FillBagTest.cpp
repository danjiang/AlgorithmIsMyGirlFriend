//
// Created by Dan Jiang on 2020/8/5.
//

#include "gtest/gtest.h"

#include "fill_bag.h"

TEST(FillBag, ZeroOneCase) {
  int max_weight = 34;

  int items1[] = { 2, 8, 4, 4, 8, 7, 8, 5, 16, 16 };
  FillBagZeroOne(items1, 10, max_weight);

  int items2[] = { 4, 5, 7, 2, 8, 3, 6, 1, 10, 9 };
  FillBagZeroOne(items2, 10, max_weight);

  int items3[] = { 4, 5, 7, 2, 8, 3, 9, 6, 1, 10 };
  FillBagZeroOne(items3, 10, max_weight);
}