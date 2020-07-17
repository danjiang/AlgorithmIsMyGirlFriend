//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "top_to_bottom_binary_tree_walk.h"
#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "mirror_binary_tree.h"
#include "binary_tree_contain_sub_tree.h"
#include "serialize_binary_tree.h"
#include "binary_tree_is_balance.h"
#include "get_binary_tree_inorder_walk_next.h"

class CompleteBinaryTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
    auto *node1 = new BinaryTreeNode(1);
    auto *node2 = new BinaryTreeNode(2);
    auto *node3 = new BinaryTreeNode(3);
    auto *node4 = new BinaryTreeNode(4);
    auto *node5 = new BinaryTreeNode(5);
    auto *node6 = new BinaryTreeNode(6);
    auto *node7 = new BinaryTreeNode(7);
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

TEST_F(CompleteBinaryTreeFixture, PreorderBinaryTreeWalk) {
  std::ostringstream os;

  PreorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 2 4 5 3 6 7 ");
}

TEST_F(CompleteBinaryTreeFixture, InorderBinaryTreeWalk) {
  std::ostringstream os;

  InorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"4 2 5 1 6 3 7 ");
}

TEST_F(CompleteBinaryTreeFixture, PostorderBinaryTreeWalk) {
  std::ostringstream os;

  PostorderBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"4 5 2 6 7 3 1 ");
}

TEST_F(CompleteBinaryTreeFixture, TopToBottomBinaryTreeWalk) {
std::ostringstream os;

TopToBottomBinaryTreeWalk(root, os);

EXPECT_EQ(os.str(),"1 2 3 4 5 6 7 ");
}

TEST_F(CompleteBinaryTreeFixture, TopToBottomLineBreakBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n2 3 \n4 5 6 7 \n");
}

TEST_F(CompleteBinaryTreeFixture, TopToBottomLineBreakZBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakZBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"1 \n3 2 \n4 5 6 7 \n");
}

TEST_F(CompleteBinaryTreeFixture, ConstructBinaryTree) {
  const int length = 7;
  int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
  int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };
  BinaryTreeNode *new_root = ConstructBinaryTree(preorder, inorder, length);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(CompleteBinaryTreeFixture, MirrorBinaryTree) {
  auto *node1 = new BinaryTreeNode(1);
  auto *node2 = new BinaryTreeNode(3);
  auto *node3 = new BinaryTreeNode(2);
  auto *node4 = new BinaryTreeNode(7);
  auto *node5 = new BinaryTreeNode(6);
  auto *node6 = new BinaryTreeNode(5);
  auto *node7 = new BinaryTreeNode(4);
  ConnectBinaryTreeNodes(node1, node2, node3);
  ConnectBinaryTreeNodes(node2, node4, node5);
  ConnectBinaryTreeNodes(node3, node6, node7);
  MirrorBinaryTree(root);
  EXPECT_TRUE(IsSameBinaryTree(node1, root));
}

TEST_F(CompleteBinaryTreeFixture, BinaryTreeContainSubTree) {
  auto *node1 = new BinaryTreeNode(2);
  auto *node2 = new BinaryTreeNode(4);
  auto *node3 = new BinaryTreeNode(5);
  ConnectBinaryTreeNodes(node1, node2, node3);
  EXPECT_TRUE(BinaryTreeContainSubTree(root, node1));

  auto *node4 = new BinaryTreeNode(6);
  ConnectBinaryTreeNodes(node2, node4, nullptr);
  EXPECT_FALSE(BinaryTreeContainSubTree(root, node1));

  EXPECT_FALSE(BinaryTreeContainSubTree(root, nullptr));
}

TEST_F(CompleteBinaryTreeFixture, SerializeBinaryTree) {
  std::ostringstream os;
  SerializeBinaryTree(root, os);
  std::istringstream is;
  is.str(os.str());
  BinaryTreeNode *new_root;
  DeserializeBinaryTree(&new_root, is);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(CompleteBinaryTreeFixture, BinaryTreeIsBalance) {
  EXPECT_TRUE(BinaryTreeIsBalance(root));
}

TEST_F(CompleteBinaryTreeFixture, GetBinaryTreeInorderWalkNext) {
  auto node = root->left->left;
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 2);
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 5);
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 1);
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 6);
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 3);
  node = GetBinaryTreeInorderWalkNext(node);
  EXPECT_EQ(node->value, 7);
}