//
// Created by Dan Jiang on 2020/6/12.
//

#include "gtest/gtest.h"

#include "binary_tree_is_symmetrical.h"

TEST(BinaryTreeIsSymmetrical, Test1) {
//            8
//        6      6
//       5 7    7 5
  auto *node1 = new BinaryTreeNode(8);
  auto *node2 = new BinaryTreeNode(6);
  auto *node3 = new BinaryTreeNode(6);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(7);
  auto *node6 = new BinaryTreeNode(7);
  auto *node7 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, node5);
  ConnectBinaryTreeNodes(node3, node6, node7);
  auto root = node1;

  EXPECT_TRUE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test2) {
//            8
//        6      9
//       5 7    7 5
  auto *node1 = new BinaryTreeNode(8);
  auto *node2 = new BinaryTreeNode(6);
  auto *node3 = new BinaryTreeNode(9);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(7);
  auto *node6 = new BinaryTreeNode(7);
  auto *node7 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, node5);
  ConnectBinaryTreeNodes(node3, node6, node7);
  auto root = node1;

  EXPECT_FALSE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test3) {
//            8
//        6      6
//       5 7    7
  auto *node1 = new BinaryTreeNode(8);
  auto *node2 = new BinaryTreeNode(6);
  auto *node3 = new BinaryTreeNode(6);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(7);
  auto *node6 = new BinaryTreeNode(7);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, node5);
  ConnectBinaryTreeNodes(node3, node6, nullptr);
  auto root = node1;

  EXPECT_FALSE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test4) {
//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(3);
  auto *node3 = new BinaryTreeNode(3);
  auto *node4 = new BinaryTreeNode(4);
  auto *node5 = new BinaryTreeNode(4);
  auto *node6 = new BinaryTreeNode(2);
  auto *node7 = new BinaryTreeNode(2);
  auto *node8 = new BinaryTreeNode(1);
  auto *node9 = new BinaryTreeNode(1);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  ConnectBinaryTreeNodes(node3, nullptr, node5);
  ConnectBinaryTreeNodes(node4, node6, nullptr);
  ConnectBinaryTreeNodes(node5, nullptr, node7);
  ConnectBinaryTreeNodes(node6, node8, nullptr);
  ConnectBinaryTreeNodes(node7, nullptr, node9);
  auto root = node1;

  EXPECT_TRUE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test5) {
//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(3);
  auto *node3 = new BinaryTreeNode(3);
  auto *node4 = new BinaryTreeNode(4);
  auto *node5 = new BinaryTreeNode(4);
  auto *node6 = new BinaryTreeNode(6);
  auto *node7 = new BinaryTreeNode(2);
  auto *node8 = new BinaryTreeNode(1);
  auto *node9 = new BinaryTreeNode(1);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  ConnectBinaryTreeNodes(node3, nullptr, node5);
  ConnectBinaryTreeNodes(node4, node6, nullptr);
  ConnectBinaryTreeNodes(node5, nullptr, node7);
  ConnectBinaryTreeNodes(node6, node8, nullptr);
  ConnectBinaryTreeNodes(node7, nullptr, node9);
  auto root = node1;

  EXPECT_FALSE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test6) {
//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(3);
  auto *node3 = new BinaryTreeNode(3);
  auto *node4 = new BinaryTreeNode(4);
  auto *node5 = new BinaryTreeNode(4);
  auto *node6 = new BinaryTreeNode(2);
  auto *node7 = new BinaryTreeNode(2);
  auto *node8 = new BinaryTreeNode(1);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  ConnectBinaryTreeNodes(node3, nullptr, node5);
  ConnectBinaryTreeNodes(node4, node6, nullptr);
  ConnectBinaryTreeNodes(node5, nullptr, node7);
  ConnectBinaryTreeNodes(node7, nullptr, node8);
  auto root = node1;

  EXPECT_FALSE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test7) {
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(5);
  auto *node3 = new BinaryTreeNode(5);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(5);
  auto *node6 = new BinaryTreeNode(5);
  auto *node7 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  ConnectBinaryTreeNodes(node3, nullptr, node5);
  ConnectBinaryTreeNodes(node4, node6, nullptr);
  ConnectBinaryTreeNodes(node5, nullptr, node7);
  auto root = node1;

  EXPECT_TRUE(BinaryTreeIsSymmetrical(root));
}

TEST(BinaryTreeIsSymmetrical, Test8) {
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
  auto *node1 = new BinaryTreeNode(5);
  auto *node2 = new BinaryTreeNode(5);
  auto *node3 = new BinaryTreeNode(5);
  auto *node4 = new BinaryTreeNode(5);
  auto *node5 = new BinaryTreeNode(5);
  auto *node6 = new BinaryTreeNode(5);
  auto *node7 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  ConnectBinaryTreeNodes(node3, nullptr, node5);
  ConnectBinaryTreeNodes(node4, node6, nullptr);
  ConnectBinaryTreeNodes(node5, node7, nullptr);
  auto root = node1;

  EXPECT_FALSE(BinaryTreeIsSymmetrical(root));
}