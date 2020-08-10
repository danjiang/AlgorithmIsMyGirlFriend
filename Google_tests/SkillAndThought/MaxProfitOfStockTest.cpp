//
// Created by Dan Jiang on 2020/8/10.
//

#include "gtest/gtest.h"

#include "max_profit_of_stock.h"

TEST(MaxProfitOfStock, NormalCase) {
  int array1[] = { 4, 1, 3, 2, 5 };
  EXPECT_EQ(MaxProfitOfStock(array1, sizeof(array1) / sizeof(int)), 4);

  int array2[] = { 1, 2, 4, 7, 11, 16 };
  EXPECT_EQ(MaxProfitOfStock(array2, sizeof(array2) / sizeof(int)), 15);

  int array3[] = { 16, 11, 7, 4, 2, 1 };
  EXPECT_EQ(MaxProfitOfStock(array3, sizeof(array3) / sizeof(int)), -1);

  int array4[] = { 16, 16, 16, 16, 16 };
  EXPECT_EQ(MaxProfitOfStock(array4, sizeof(array4) / sizeof(int)), 0);

  int array5[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
  EXPECT_EQ(MaxProfitOfStock(array5, sizeof(array5) / sizeof(int)), 11);

  int array6[] = { 2, 4 };
  EXPECT_EQ(MaxProfitOfStock(array6, sizeof(array6) / sizeof(int)), 2);

  int array7[] = { 4, 2 };
  EXPECT_EQ(MaxProfitOfStock(array7, sizeof(array7) / sizeof(int)), -2);

  EXPECT_THROW(MaxProfitOfStock(nullptr, 0), invalid_input);
}
