//
// Created by Dan Jiang on 2020/8/5.
//

#include "gtest/gtest.h"

#include "has_string_path_in_matrix.h"

TEST(HasStringPathInMatrix, NormalCase) {
////ABTG
////CFCS
////JDEH
//
////BFCE
//  char matrix1[] = "ABTGCFCSJDEH";
//  char path1[] = "BFCE";
//  EXPECT_TRUE(HasStringPathInMatrix(path1, matrix1, 3, 4));
//
////ABCE
////SFCS
////ADEE
//
////SEE
//  char matrix2[] = "ABCESFCSADEE";
//  char path2[] = "SEE";
//  EXPECT_TRUE(HasStringPathInMatrix(path2, matrix2, 3, 4));
//
////ABTG
////CFCS
////JDEH
//
////ABFB
//  char matrix3[] = "ABTGCFCSJDEH";
//  char path3[] = "ABFB";
//  EXPECT_FALSE(HasStringPathInMatrix(path3, matrix3, 3, 4));
//
////ABCEHJIG
////SFCSLOPQ
////ADEEMNOE
////ADIDEJFM
////VCEIFGGS
//
////SLHECCEIDEJFGGFIE
//  char matrix4[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
//  char path4[] = "SLHECCEIDEJFGGFIE";
//  EXPECT_TRUE(HasStringPathInMatrix(path4, matrix4, 5, 8));
//
////ABCEHJIG
////SFCSLOPQ
////ADEEMNOE
////ADIDEJFM
////VCEIFGGS
//
////SGGFIECVAASABCEHJIGQEM
//  char matrix5[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
//  char path5[] = "SGGFIECVAASABCEHJIGQEM";
//  EXPECT_TRUE(HasStringPathInMatrix(path5, matrix5, 5, 8));
//
////ABCEHJIG
////SFCSLOPQ
////ADEEMNOE
////ADIDEJFM
////VCEIFGGS
//
////SGGFIECVAASABCEEJIGOEM
//  char matrix6[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
//  char path6[] = "SGGFIECVAASABCEEJIGOEM";
//  EXPECT_FALSE(HasStringPathInMatrix(path6, matrix6, 5, 8));
//
////ABCEHJIG
////SFCSLOPQ
////ADEEMNOE
////ADIDEJFM
////VCEIFGGS
//
////SGGFIECVAASABCEHJIGQEMS
//  char matrix7[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
//  char path7[] = "SGGFIECVAASABCEHJIGQEMS";
//  EXPECT_FALSE(HasStringPathInMatrix(path7, matrix7, 5, 8));
//
////AAAA
////AAAA
////AAAA
//
////AAAAAAAAAAAA
//  char matrix8[] = "AAAAAAAAAAAA";
//  char path8[] = "AAAAAAAAAAAA";
//  EXPECT_TRUE(HasStringPathInMatrix(path8, matrix8, 3, 4));
//
////AAAA
////AAAA
////AAAA
//
////AAAAAAAAAAAAA
//  char matrix9[] = "AAAAAAAAAAAA";
//  char path9[] = "AAAAAAAAAAAAA";
//  EXPECT_FALSE(HasStringPathInMatrix(path9, matrix9, 3, 4));

//A

//A
  char matrix10[] = "A";
  char path10[] = "A";
  EXPECT_TRUE(HasStringPathInMatrix(path10, matrix10, 1, 1));

//A

//B
  char matrix11[] = "A";
  char path11[] = "B";
  EXPECT_FALSE(HasStringPathInMatrix(path11, matrix11, 1, 1));

  EXPECT_FALSE(HasStringPathInMatrix(nullptr, nullptr, 0, 0));
}