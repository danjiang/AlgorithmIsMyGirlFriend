//
// Created by Dan Jiang on 2020/8/7.
//

#include "gtest/gtest.h"

#include "coin_change.h"

TEST(CoinChange, MenoCase) {
  int coins[] = { 5, 3, 1 };
  EXPECT_EQ(CoinChangeMemo(coins, 3, 9), 3);
  EXPECT_EQ(CoinChangeMemo(coins, 3, 20), 4);
  EXPECT_EQ(CoinChangeMemo(coins, 3, 17), 5);
}

TEST(CoinChange, StatesCase) {
  int coins[] = { 5, 3, 1 };
  EXPECT_EQ(CoinChangeStates(coins, 3, 9), 3);
  EXPECT_EQ(CoinChangeStates(coins, 3, 20), 4);
  EXPECT_EQ(CoinChangeStates(coins, 3, 17), 5);
}