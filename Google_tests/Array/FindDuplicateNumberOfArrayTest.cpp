//
// Created by Dan Jiang on 2020/7/27.
//

#include "gtest/gtest.h"

#include "find_duplicate_number_of_array.h"
#include "array_util.h"

TEST(FindDuplicateNumberOfArray, EditCase) {
  int array1[] = { 2, 1, 3, 1, 4 };
  EXPECT_EQ(FindDuplicateNumberOfArrayEdit(array1, 5), 1);

  int array2[] = { 2, 4, 3, 1, 4 };
  EXPECT_EQ(FindDuplicateNumberOfArrayEdit(array2, 5), 4);

  int array3[] = { 2, 4, 2, 1, 4 };
  int duplications[] = { 2, 4 };
  int duplicate = FindDuplicateNumberOfArrayEdit(array3, 5);
  EXPECT_TRUE(ArrayContain(duplications, 2, duplicate));

  int array4[] = { 2, 1, 3, 0, 4 };
  EXPECT_THROW(FindDuplicateNumberOfArrayEdit(array4, 5), not_found);

  int array5[] = { 2, 1, 3, 5, 4 };
  EXPECT_THROW(FindDuplicateNumberOfArrayEdit(array5, 5), invalid_input);

  EXPECT_THROW(FindDuplicateNumberOfArrayEdit(nullptr, 0), invalid_input);
}

TEST(FindDuplicateNumberOfArray, NoEditCase) {
  int array1[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
  int duplications1[] = { 2, 3 };
  int duplicate = FindDuplicateNumberOfArrayNoEdit(array1, 8);
  EXPECT_TRUE(ArrayContain(duplications1, 2, duplicate));

  int array2[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array2, 8), 4);

  int array3[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array3, 9), 1);

  int array4[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array4, 9), 8);

  int array5[] = { 1, 1 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array5, 2), 1);

  int array6[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array6, 8), 3);

  int array7[] = { 1, 2, 2, 6, 4, 5, 6 };
  int duplications2[] = { 2, 6 };
  duplicate = FindDuplicateNumberOfArrayNoEdit(array7, 7);
  EXPECT_TRUE(ArrayContain(duplications2, 2, duplicate));

  int array8[] = { 1, 2, 2, 6, 4, 5, 2 };
  EXPECT_EQ(FindDuplicateNumberOfArrayNoEdit(array8, 7), 2);

  int array9[] = { 1, 2, 6, 4, 5, 3 };
  EXPECT_THROW(FindDuplicateNumberOfArrayNoEdit(array9, 6), not_found);

  EXPECT_THROW(FindDuplicateNumberOfArrayNoEdit(nullptr, 0), invalid_input);
}
