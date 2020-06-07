//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "is_postorder_sequence_of_bst.h"

TEST(OtherBinaryTree, ConstructBinaryTree) {
  const int length = 7;
  int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
  int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };
  EXPECT_THROW(ConstructBinaryTree(preorder, inorder, length), invalid_input);
}

TEST(OtherBinaryTree, IsPostorderSequenceOfBST) {
  int sequence1[] = { 7, 4, 6, 5 };
  int length1 = sizeof(sequence1) / sizeof(int);
  EXPECT_FALSE(IsPostorderSequenceOfBST(sequence1, length1));

  int sequence2[] = { 4, 6, 12, 8, 16, 14, 10 };
  int length2 = sizeof(sequence2) / sizeof(int);
  EXPECT_FALSE(IsPostorderSequenceOfBST(sequence2, length2));
}