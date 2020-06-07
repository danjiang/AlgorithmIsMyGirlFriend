//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "mirror_binary_tree.h"
#include "binary_tree_contain_sub_tree.h"
#include "is_postorder_sequence_of_bst.h"
#include "find_summary_path_in_binary_tree.h"

class EmptyBinaryTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    root = nullptr;
  }

  virtual void TearDown() {
    root = nullptr;
  }

  BinaryTreeNode *root;
};

TEST_F(EmptyBinaryTreeFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1), nullptr);
}

TEST_F(EmptyBinaryTreeFixture, ConstructBinaryTree) {
  EXPECT_EQ(ConstructBinaryTree(nullptr, nullptr, 0), nullptr);
}

TEST_F(EmptyBinaryTreeFixture, MirrorBinaryTree) {
  MirrorBinaryTree(root);
  EXPECT_EQ(root, nullptr);
}

TEST_F(EmptyBinaryTreeFixture, BinaryTreeContainSubTree) {
  BinaryTreeNode *node1 = new BinaryTreeNode(5);
  EXPECT_FALSE(BinaryTreeContainSubTree(root, node1));
  EXPECT_FALSE(BinaryTreeContainSubTree(root, nullptr));
}

TEST_F(EmptyBinaryTreeFixture, IsPostorderSequenceOfBST) {
  EXPECT_FALSE(IsPostorderSequenceOfBST(nullptr, 0));
}

TEST_F(EmptyBinaryTreeFixture, FindSummaryPathInBT) {
  std::ostringstream os;
  FindSummaryPathInBT(root, 5, os);
  EXPECT_EQ(os.str(),"");
}