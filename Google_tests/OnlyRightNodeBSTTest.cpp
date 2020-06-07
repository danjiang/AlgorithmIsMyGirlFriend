//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "is_postorder_sequence_of_bst.h"

class OnlyRightNodeBSTFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
    auto *node1 = new BinaryTreeNode(1);
    auto *node2 = new BinaryTreeNode(2);
    auto *node3 = new BinaryTreeNode(3);
    auto *node4 = new BinaryTreeNode(4);
    auto *node5 = new BinaryTreeNode(5);
    ConnectBinaryTreeNodes(node1, nullptr, node2);
    ConnectBinaryTreeNodes(node2, nullptr, node3);
    ConnectBinaryTreeNodes(node3, nullptr, node4);
    ConnectBinaryTreeNodes(node4, nullptr, node5);
    root = node1;
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root;
};

TEST_F(OnlyRightNodeBSTFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1)->value, 1);
  EXPECT_EQ(FindKthNodeInBST(root, 3)->value, 3);
  EXPECT_EQ(FindKthNodeInBST(root, 5)->value, 5);
}

TEST_F(OnlyRightNodeBSTFixture, IsPostorderSequenceOfBST) {
  int sequence[] = { 5, 4, 3, 2, 1 };
  int length = sizeof(sequence) / sizeof(int);
  EXPECT_TRUE(IsPostorderSequenceOfBST(sequence, length));
}