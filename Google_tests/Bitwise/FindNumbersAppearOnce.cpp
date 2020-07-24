//
// Created by Dan Jiang on 2020/7/24.
//

#include "gtest/gtest.h"

#include "find_numbers_appear_once.h"

TEST(FindNumbersAppearOnce, TwoNumbers) {
  int num1 = 0;
  int num2 = 0;
  int array1[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
  FindNumbersAppearOnce(array1, 8, &num1, &num2);
  EXPECT_EQ(num1, 6);
  EXPECT_EQ(num2, 4);

  int array2[] = { 4, 6 };
  FindNumbersAppearOnce(array2, 2, &num1, &num2);
  EXPECT_EQ(num1, 6);
  EXPECT_EQ(num2, 4);

  int array3[] = { 4, 6, 1, 1, 1, 1 };
  FindNumbersAppearOnce(array3, 6, &num1, &num2);
  EXPECT_EQ(num1, 6);
  EXPECT_EQ(num2, 4);
}

TEST(FindNumbersAppearOnce, OneNumber) {
  int array1[] = { 1, 1, 2, 2, 2, 1, 3 };
  EXPECT_EQ(FindNumberAppearOnce(array1, 7), 3);

  int array2[] = { 4, 3, 3, 2, 2, 2, 3 };
  EXPECT_EQ(FindNumberAppearOnce(array2, 7), 4);

  int array3[] = { 4, 4, 1, 1, 1, 7, 4 };
  EXPECT_EQ(FindNumberAppearOnce(array3, 7), 7);

  int array4[] = { -10, 214, 214, 214 };
  EXPECT_EQ(FindNumberAppearOnce(array4, 4), -10);

  int array5[] = { -209, 3467, -209, -209 };
  EXPECT_EQ(FindNumberAppearOnce(array5, 4), 3467);

  int array6[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
  EXPECT_EQ(FindNumberAppearOnce(array6, 7), 1023);

  int array7[] = { -1024, -1024, -1024, -1023 };
  EXPECT_EQ(FindNumberAppearOnce(array7, 4), -1023);

  int array8[] = { -23, 0, 214, -23, 214, -23, 214 };
  EXPECT_EQ(FindNumberAppearOnce(array8, 7), 0);

  int array9[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
  EXPECT_EQ(FindNumberAppearOnce(array9, 8), 3467);
}
