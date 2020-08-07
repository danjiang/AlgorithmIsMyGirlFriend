//
// Created by Dan Jiang on 2020/8/5.
//

#include "gtest/gtest.h"

#include "fill_bag.h"

TEST(FillBag, WeightBacktrackingCase) {
  int max_weight = 34;

  int weights1[] = { 2, 8, 4, 4, 8, 7, 8, 5, 16, 16 };
  FillBagBacktracking(weights1, 10, max_weight);

  int weights2[] = { 4, 5, 7, 2, 8, 3, 6, 1, 10, 9 };
  FillBagBacktracking(weights2, 10, max_weight);

  int weights3[] = { 4, 5, 7, 2, 8, 3, 9, 6, 1, 10 };
  FillBagBacktracking(weights3, 10, max_weight);

  int weights4[] = { 2, 2, 4, 6, 3 };
  FillBagBacktracking(weights4, 5, 9);
}

TEST(FillBag, WeightDynamciCase) {
  int max_weight = 34;

  int weights1[] = { 2, 8, 4, 4, 8, 7, 8, 5, 16, 16 };
  FillBagDynamic(weights1, 10, max_weight);

  int weights2[] = { 4, 5, 7, 2, 8, 3, 6, 1, 10, 9 };
  FillBagDynamic(weights2, 10, max_weight);

  int weights3[] = { 4, 5, 7, 2, 8, 3, 9, 6, 1, 10 };
  FillBagDynamic(weights3, 10, max_weight);

  int weights4[] = { 2, 2, 4, 6, 3 };
  FillBagDynamic(weights4, 5, 9);
}

TEST(FillBag, ValueBacktrackingCase) {
  int max_weight = 34;

  int weights1[] = { 2, 8, 4, 4, 8, 7, 8, 5, 16, 16 };
  int values1[] = { 15, 25, 9, 9, 15, 12, 12, 6, 14, 9 };
  FillBagAdvanceBacktracking(weights1, 10, max_weight, values1);

  int weights2[] = { 4, 5, 7, 2, 8, 3, 6, 1, 10, 9 };
  int values2[] = { 25, 14, 15, 4, 14, 5, 8, 1, 10, 2 };
  FillBagAdvanceBacktracking(weights2, 10, max_weight, values2);

  int weights3[] = { 4, 5, 7, 2, 8, 3, 9, 6, 1, 10 };
  int values3[] = { 25, 14, 15, 4, 14, 5, 14, 8, 1, 10 };
  FillBagAdvanceBacktracking(weights3, 10, max_weight, values3);

  int weights4[] = { 2, 2, 4, 6, 3 };
  int values4[] = { 3, 4, 8, 9, 6 };
  FillBagAdvanceBacktracking(weights4, 5, 9, values4);
}

TEST(FillBag, ValueDynamicCase) {
  int max_weight = 34;

  int weights1[] = { 2, 8, 4, 4, 8, 7, 8, 5, 16, 16 };
  int values1[] = { 15, 25, 9, 9, 15, 12, 12, 6, 14, 9 };
  FillBagAdvanceDynamic(weights1, 10, max_weight, values1);

  int weights2[] = { 4, 5, 7, 2, 8, 3, 6, 1, 10, 9 };
  int values2[] = { 25, 14, 15, 4, 14, 5, 8, 1, 10, 2 };
  FillBagAdvanceDynamic(weights2, 10, max_weight, values2);

  int weights3[] = { 4, 5, 7, 2, 8, 3, 9, 6, 1, 10 };
  int values3[] = { 25, 14, 15, 4, 14, 5, 14, 8, 1, 10 };
  FillBagAdvanceDynamic(weights3, 10, max_weight, values3);

  int weights4[] = { 2, 2, 4, 6, 3 };
  int values4[] = { 3, 4, 8, 9, 6 };
  FillBagAdvanceDynamic(weights4, 5, 9, values4);
}