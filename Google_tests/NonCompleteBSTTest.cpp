//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "is_postorder_sequence_of_bst.h"

class NonCompleteBSTFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//           5
//          / \
//         4   7
//            /
//           6
    auto *node1 = new BinaryTreeNode(5);
    auto *node2 = new BinaryTreeNode(4);
    auto *node3 = new BinaryTreeNode(7);
    auto *node4 = new BinaryTreeNode(6);
    ConnectBinaryTreeNodes(node1, node2, node3);
    ConnectBinaryTreeNodes(node3, node4, nullptr);
    root = node1;
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root;
};

TEST_F(NonCompleteBSTFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1)->value, 4);
  EXPECT_EQ(FindKthNodeInBST(root, 2)->value, 5);
  EXPECT_EQ(FindKthNodeInBST(root, 4)->value, 7);
}

TEST_F(NonCompleteBSTFixture, IsPostorderSequenceOfBST) {
  int sequence[] = { 4, 6, 7, 5 };
  int length = sizeof(sequence) / sizeof(int);
  EXPECT_TRUE(IsPostorderSequenceOfBST(sequence, length));
}