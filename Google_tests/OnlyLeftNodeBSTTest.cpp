//
// Created by Dan Jiang on 2020/6/7.
//

#include "gtest/gtest.h"

#include "binary_tree.h"
#include "find_kth_node_in_bst.h"
#include "is_postorder_sequence_of_bst.h"
#include "bst_to_link_list.h"

class OnlyLeftNodeBSTFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
    auto *node1 = new BinaryTreeNode(5);
    auto *node2 = new BinaryTreeNode(4);
    auto *node3 = new BinaryTreeNode(3);
    auto *node4 = new BinaryTreeNode(2);
    auto *node5 = new BinaryTreeNode(1);
    ConnectBinaryTreeNodes(node1, node2, nullptr);
    ConnectBinaryTreeNodes(node2, node3, nullptr);
    ConnectBinaryTreeNodes(node3, node4, nullptr);
    ConnectBinaryTreeNodes(node4, node5, nullptr);
    root = node1;
  }

  virtual void TearDown() {
    if (need_destroy) {
      DestroyBinaryTree(root);
    }
  }

  BinaryTreeNode *root;
  bool need_destroy = true;
};

TEST_F(OnlyLeftNodeBSTFixture, FindKthNodeInBST) {
  EXPECT_EQ(FindKthNodeInBST(root, 1)->value, 1);
  EXPECT_EQ(FindKthNodeInBST(root, 3)->value, 3);
  EXPECT_EQ(FindKthNodeInBST(root, 5)->value, 5);
}

TEST_F(OnlyLeftNodeBSTFixture, IsPostorderSequenceOfBST) {
  int sequence[] = { 1, 2, 3, 4, 5 };
  int length = sizeof(sequence) / sizeof(int);
  EXPECT_TRUE(IsPostorderSequenceOfBST(sequence, length));
}

TEST_F(OnlyLeftNodeBSTFixture, BST2LinkList) {
  BinaryTreeNode *head = BST2LinkList(root);

  std::ostringstream os;
  BinaryTreeWalkAsLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 3 4 5 ");

  need_destroy = false;
}