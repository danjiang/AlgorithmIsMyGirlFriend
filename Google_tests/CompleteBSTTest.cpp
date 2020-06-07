//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "is_postorder_sequence_of_bst.h"

class CompleteBSTFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
    auto *node1 = new BinaryTreeNode(10);
    auto *node2 = new BinaryTreeNode(6);
    auto *node3 = new BinaryTreeNode(14);
    auto *node4 = new BinaryTreeNode(4);
    auto *node5 = new BinaryTreeNode(8);
    auto *node6 = new BinaryTreeNode(12);
    auto *node7 = new BinaryTreeNode(16);
    ConnectBinaryTreeNodes(node1, node2, node3);
    ConnectBinaryTreeNodes(node2, node4, node5);
    ConnectBinaryTreeNodes(node3, node6, node7);
    root = node1;
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root;
};

TEST_F(CompleteBSTFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1)->value, 4);
  EXPECT_EQ(FindKthNodeInBST(root, 5)->value, 12);
  EXPECT_EQ(FindKthNodeInBST(root, 7)->value, 16);

  EXPECT_EQ(FindKthNodeInBST(root, 0), nullptr);
  EXPECT_EQ(FindKthNodeInBST(root, 8), nullptr);
}

TEST_F(CompleteBSTFixture, IsPostorderSequenceOfBST) {
  int sequence[] = { 4, 8, 6, 12, 16, 14, 10 };
  int length = sizeof(sequence) / sizeof(int);
  EXPECT_TRUE(IsPostorderSequenceOfBST(sequence, length));
}