//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "get_tree_last_common_parent.h"

TEST(Tree, Test1) {
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
  auto *node1 = new TreeNode(1);
  auto *node2 = new TreeNode(2);
  auto *node3 = new TreeNode(3);
  auto *node4 = new TreeNode(4);
  auto *node5 = new TreeNode(5);
  auto *node6 = new TreeNode(6);
  auto *node7 = new TreeNode(7);
  auto *node8 = new TreeNode(8);
  auto *node9 = new TreeNode(9);
  auto *node10 = new TreeNode(10);
  ConnectTreeNodes(node1, node2);
  ConnectTreeNodes(node1, node3);
  ConnectTreeNodes(node2, node4);
  ConnectTreeNodes(node2, node5);
  ConnectTreeNodes(node4, node6);
  ConnectTreeNodes(node4, node7);
  ConnectTreeNodes(node5, node8);
  ConnectTreeNodes(node5, node9);
  ConnectTreeNodes(node5, node10);
  auto root = node1;

  auto parent = GetTreeLastCommonParent(root, node6, node8);
  EXPECT_EQ(parent->value, node2->value);
}

TEST(Tree, Test2) {
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
  auto *node1 = new TreeNode(1);
  auto *node2 = new TreeNode(2);
  auto *node3 = new TreeNode(3);
  auto *node4 = new TreeNode(4);
  auto *node5 = new TreeNode(5);
  ConnectTreeNodes(node1, node2);
  ConnectTreeNodes(node2, node3);
  ConnectTreeNodes(node3, node4);
  ConnectTreeNodes(node4, node5);
  auto root = node1;

  auto parent = GetTreeLastCommonParent(root, node5, node4);
  EXPECT_EQ(parent->value, node3->value);

  auto *node6 = new TreeNode(6);

  parent = GetTreeLastCommonParent(root, node5, node6);
  EXPECT_EQ(parent, nullptr);
}

TEST(Tree, Test3) {
  auto parent = GetTreeLastCommonParent(nullptr, nullptr, nullptr);
  EXPECT_EQ(parent, nullptr);
}