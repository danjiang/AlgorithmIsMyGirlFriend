//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "top_to_bottom_binary_tree_walk.h"
#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "binary_tree_contain_sub_tree.h"
#include "find_summary_path_in_binary_tree.h"
#include "binary_tree_depth.h"
#include "binary_tree_is_balance.h"

class NonCompleteBinaryTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
    auto *node1 = new BinaryTreeNode(1);
    auto *node2 = new BinaryTreeNode(2);
    auto *node3 = new BinaryTreeNode(3);
    auto *node4 = new BinaryTreeNode(4);
    auto *node5 = new BinaryTreeNode(5);
    auto *node6 = new BinaryTreeNode(6);
    auto *node7 = new BinaryTreeNode(7);
    auto *node8 = new BinaryTreeNode(8);
    ConnectBinaryTreeNodes(node1, node2, node3);
    ConnectBinaryTreeNodes(node2, node4, nullptr);
    ConnectBinaryTreeNodes(node3, node5, node6);
    ConnectBinaryTreeNodes(node4, nullptr, node7);
    ConnectBinaryTreeNodes(node6, node8, nullptr);
    root = node1;
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root;
};

TEST_F(NonCompleteBinaryTreeFixture, PreorderBinaryTreeWalk) {
  std::ostringstream os;

  PreorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 2 4 7 3 5 6 8 ");
}

TEST_F(NonCompleteBinaryTreeFixture, InorderBinaryTreeWalk) {
  std::ostringstream os;

  InorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"4 7 2 1 5 3 8 6 ");
}

TEST_F(NonCompleteBinaryTreeFixture, PostorderBinaryTreeWalk) {
  std::ostringstream os;

  PostorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"7 4 2 5 8 6 3 1 ");
}

TEST_F(NonCompleteBinaryTreeFixture, TopToBottomBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 2 3 4 5 6 7 8 ");
}

TEST_F(NonCompleteBinaryTreeFixture, TopToBottomLineBreakBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n2 3 \n4 5 6 \n7 8 \n");
}

TEST_F(NonCompleteBinaryTreeFixture, TopToBottomLineBreakZBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakZBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n3 2 \n4 5 6 \n8 7 \n");
}

TEST_F(NonCompleteBinaryTreeFixture, ConstructBinaryTree) {
  const int length = 8;
  int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
  int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
  BinaryTreeNode *new_root = ConstructBinaryTree(preorder, inorder, length);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(NonCompleteBinaryTreeFixture, BinaryTreeContainSubTree) {
  auto *node1 = new BinaryTreeNode(3);
  auto *node2 = new BinaryTreeNode(5);
  auto *node3 = new BinaryTreeNode(6);
  ConnectBinaryTreeNodes(node1, node2, node3);
  EXPECT_TRUE(BinaryTreeContainSubTree(root, node1));

  node3->value = 3;
  EXPECT_FALSE(BinaryTreeContainSubTree(root, node1));
}

TEST_F(NonCompleteBinaryTreeFixture, FindSummaryPathInBT) {
  std::ostringstream os;
  FindSummaryPathInBT(root, 9, os);
  EXPECT_EQ(os.str(),"1 3 5 \n");

  os.str("");
  FindSummaryPathInBT(root, 10, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(NonCompleteBinaryTreeFixture, BinaryTreeDepth) {
  int depth = BinaryTreeDepth(root);
  EXPECT_EQ(depth, 4);
}

TEST_F(NonCompleteBinaryTreeFixture, BinaryTreeIsBalance) {
  EXPECT_FALSE(BinaryTreeIsBalance(root));
}