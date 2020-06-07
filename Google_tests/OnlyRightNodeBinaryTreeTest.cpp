//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "top_to_bottom_binary_tree_walk.h"
#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "mirror_binary_tree.h"
#include "binary_tree_contain_sub_tree.h"
#include "find_summary_path_in_binary_tree.h"

class OnlyRightNodeBinaryTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
// 1
//  \
//   4
//    \
//     3
//      \
//       2
//        \
//         5
    auto *node1 = new BinaryTreeNode(1);
    auto *node2 = new BinaryTreeNode(4);
    auto *node3 = new BinaryTreeNode(3);
    auto *node4 = new BinaryTreeNode(2);
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

TEST_F(OnlyRightNodeBinaryTreeFixture, TopToBottomBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 4 3 2 5 ");
}

TEST_F(OnlyRightNodeBinaryTreeFixture, TopToBottomLineBreakBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n4 \n3 \n2 \n5 \n");
}

TEST_F(OnlyRightNodeBinaryTreeFixture, TopToBottomLineBreakZBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakZBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n4 \n3 \n2 \n5 \n");
}

TEST_F(OnlyRightNodeBinaryTreeFixture, ConstructBinaryTree) {
  const int length = 5;
  int preorder[length] = { 1, 4, 3, 2, 5 };
  int inorder[length] = { 1, 4, 3, 2, 5 };
  BinaryTreeNode *new_root = ConstructBinaryTree(preorder, inorder, length);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(OnlyRightNodeBinaryTreeFixture, MirrorBinaryTree) {
  auto *node1 = new BinaryTreeNode(1);
  auto *node2 = new BinaryTreeNode(4);
  auto *node3 = new BinaryTreeNode(3);
  auto *node4 = new BinaryTreeNode(2);
  auto *node5 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, nullptr);
  ConnectBinaryTreeNodes(node2, node3, nullptr);
  ConnectBinaryTreeNodes(node3, node4, nullptr);
  ConnectBinaryTreeNodes(node4, node5, nullptr);
  MirrorBinaryTree(root);
  EXPECT_TRUE(IsSameBinaryTree(node1, root));
}

TEST_F(OnlyRightNodeBinaryTreeFixture, BinaryTreeContainSubTree) {
  auto *node1 = new BinaryTreeNode(4);
  auto *node2 = new BinaryTreeNode(3);
  auto *node3 = new BinaryTreeNode(2);
  ConnectBinaryTreeNodes(node1, nullptr, node2);
  ConnectBinaryTreeNodes(node2, nullptr, node3);
  EXPECT_TRUE(BinaryTreeContainSubTree(root, node1));

  node3->value = 3;
  EXPECT_FALSE(BinaryTreeContainSubTree(root, node1));
}

TEST_F(OnlyRightNodeBinaryTreeFixture, FindSummaryPathInBT) {
  std::ostringstream os;
  FindSummaryPathInBT(root, 15, os);
  EXPECT_EQ(os.str(),"1 4 3 2 5 \n");

  os.str("");
  FindSummaryPathInBT(root, 10, os);
  EXPECT_EQ(os.str(),"");
}