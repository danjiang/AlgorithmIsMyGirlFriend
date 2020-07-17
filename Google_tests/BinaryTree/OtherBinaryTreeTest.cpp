//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "is_postorder_sequence_of_bst.h"
#include "serialize_binary_tree.h"
#include "binary_tree_is_balance.h"

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

TEST(OtherBinaryTree, SerializeBinaryTree) {
//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(5);
  auto *node3 = new BinaryTreeNode(5);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(5);
  auto *node6 = new BinaryTreeNode(5);
  auto *node7 = new BinaryTreeNode(5);
  auto *node8 = new BinaryTreeNode(5);
  auto *node9 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, nullptr, node2);
  ConnectBinaryTreeNodes(node2, nullptr, node3);
  ConnectBinaryTreeNodes(node3, node4, nullptr);
  ConnectBinaryTreeNodes(node4, node5, nullptr);
  ConnectBinaryTreeNodes(node5, node6, node7);
  ConnectBinaryTreeNodes(node6, node8, nullptr);
  ConnectBinaryTreeNodes(node7, nullptr, node9);
  auto root = node1;

  std::ostringstream os;
  SerializeBinaryTree(root, os);
  std::istringstream is;
  is.str(os.str());
  BinaryTreeNode *new_root;
  DeserializeBinaryTree(&new_root, is);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST(OtherBinaryTree, BinaryTreeIsBalance) {
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
  auto *node1 = new BinaryTreeNode(1);
  auto *node2 = new BinaryTreeNode(2);
  auto *node3 = new BinaryTreeNode(3);
  auto *node4 = new BinaryTreeNode(4);
  auto *node5 = new BinaryTreeNode(5);
  auto *node6 = new BinaryTreeNode(6);
  auto *node7 = new BinaryTreeNode(7);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, node5);
  ConnectBinaryTreeNodes(node3, nullptr, node6);
  ConnectBinaryTreeNodes(node5, node7, nullptr);
  auto root = node1;

  EXPECT_TRUE(BinaryTreeIsBalance(root));
}