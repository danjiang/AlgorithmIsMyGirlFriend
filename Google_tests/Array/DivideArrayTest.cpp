//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "divide_array.h"
#include "array_util.h"

TEST(DivideArray, NormalCase) {
  int array1[] = {1, 2, 3, 4, 5, 6, 7};
  DivideArray(array1, 7);
  PrintArray(array1, 7);

  int array2[] = {2, 4, 6, 1, 3, 5, 7};
  DivideArray(array2, 7);
  PrintArray(array2, 7);

  int array3[] = {1, 3, 5, 7, 2, 4, 6};
  DivideArray(array3, 7);
  PrintArray(array3, 7);

  int array4[] = {1};
  int divided_array2[] = {1};
  DivideArray(array4, 1);
  PrintArray(array4, 1);

  int array5[] = {2};
  int divided_array3[] = {2};
  DivideArray(array5, 1);
  PrintArray(array5, 1);

  EXPECT_THROW(DivideArray(nullptr, 0), invalid_input);
}
