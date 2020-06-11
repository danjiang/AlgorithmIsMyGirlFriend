//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "top_to_bottom_binary_tree_walk.h"
#include "construct_binary_tree_with_preorder_inorder_walk_result.h"
#include "mirror_binary_tree.h"
#include "is_postorder_sequence_of_bst.h"
#include "find_summary_path_in_binary_tree.h"
#include "bst_to_link_list.h"
#include "serialize_binary_tree.h"
#include "binary_tree_depth.h"

class OneNodeBinaryTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    root = new BinaryTreeNode(5);
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root;
};

TEST_F(OneNodeBinaryTreeFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1)->value, 5);
}

TEST_F(OneNodeBinaryTreeFixture, TopToBottomBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"5 ");
}

TEST_F(OneNodeBinaryTreeFixture, TopToBottomLineBreakBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"5 \n");
}

TEST_F(OneNodeBinaryTreeFixture, TopToBottomLineBreakZBinaryTreeWalk) {
  std::ostringstream os;

  TopToBottomLineBreakZBinaryTreeWalk(root, os);

  EXPECT_EQ(os.str(),"5 \n");
}

TEST_F(OneNodeBinaryTreeFixture, ConstructBinaryTree) {
  const int length = 1;
  int preorder[length] = { 5 };
  int inorder[length] = { 5 };
  BinaryTreeNode *new_root = ConstructBinaryTree(preorder, inorder, length);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(OneNodeBinaryTreeFixture, MirrorBinaryTree) {
  auto *node1 = new BinaryTreeNode(5);
  MirrorBinaryTree(root);
  EXPECT_TRUE(IsSameBinaryTree(node1, root));
}

TEST_F(OneNodeBinaryTreeFixture, IsPostorderSequenceOfBST) {
  int sequence[] = { 5 };
  int length = sizeof(sequence) / sizeof(int);
  EXPECT_TRUE(IsPostorderSequenceOfBST(sequence, length));
}

TEST_F(OneNodeBinaryTreeFixture, FindSummaryPathInBT) {
  std::ostringstream os;
  FindSummaryPathInBT(root, 5, os);
  EXPECT_EQ(os.str(),"5 \n");

  os.str("");
  FindSummaryPathInBT(root, 10, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(OneNodeBinaryTreeFixture, BST2LinkList) {
  BinaryTreeNode *head = BST2LinkList(root);

  std::ostringstream os;
  BinaryTreeWalkAsLinkList(head, os);
  EXPECT_EQ(os.str(),"5 ");
}

TEST_F(OneNodeBinaryTreeFixture, SerializeBinaryTree) {
  std::ostringstream os;
  SerializeBinaryTree(root, os);
  std::istringstream is;
  is.str(os.str());
  BinaryTreeNode *new_root;
  DeserializeBinaryTree(&new_root, is);
  EXPECT_TRUE(IsSameBinaryTree(root, new_root));
}

TEST_F(OneNodeBinaryTreeFixture, BinaryTreeDepth) {
  int depth = BinaryTreeDepth(root);
  EXPECT_EQ(depth, 1);
}