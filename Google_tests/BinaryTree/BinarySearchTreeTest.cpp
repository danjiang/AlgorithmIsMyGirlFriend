//
// Created by Dan Jiang on 2020/7/28.
//

#include "gtest/gtest.h"

#include "binary_search_tree.h"
#include "top_to_bottom_binary_tree_walk.h"

class BinarySearchTreeFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
//               33
//           /        \
//         16         50
//       /   \       /   \
//      13   18     34   58
//       \   / \        / \
//       15 17 25      51 66
//            / \       \
//           19 27      55
    BSTInsert(&root, 33);
    BSTInsert(&root, 16);
    BSTInsert(&root, 50);
    BSTInsert(&root, 13);
    BSTInsert(&root, 18);
    BSTInsert(&root, 34);
    BSTInsert(&root, 58);
    BSTInsert(&root, 15);
    BSTInsert(&root, 17);
    BSTInsert(&root, 25);
    BSTInsert(&root, 51);
    BSTInsert(&root, 66);
    BSTInsert(&root, 19);
    BSTInsert(&root, 27);
    BSTInsert(&root, 55);
  }

  virtual void TearDown() {
    DestroyBinaryTree(root);
  }

  BinaryTreeNode *root = nullptr;
};

TEST_F(BinarySearchTreeFixture, BSTFind) {
  int values[] = { 13, 15, 16, 17, 18, 19, 25, 27, 33, 34, 50, 51, 55, 58, 66 };
  for (int i = 0; i < 15; ++i) {
    int value = values[i];
    auto node = BSTFind(root, value);
    EXPECT_EQ(node->value, value);
  }
  EXPECT_EQ(BSTFind(root, 32), nullptr);
  EXPECT_EQ(BSTFind(nullptr, 25), nullptr);
}

TEST_F(BinarySearchTreeFixture, BSTDelete) {
  std::ostringstream os;

  os << "delete 13" << std::endl;
  BSTDelete(&root, 13);
  TopToBottomLineBreakEmptyBinaryTreeWalk(root, os);

  os << "delete 18" << std::endl;
  BSTDelete(&root, 18);
  TopToBottomLineBreakEmptyBinaryTreeWalk(root, os);

  os << "delete 55" << std::endl;
  BSTDelete(&root, 55);
  TopToBottomLineBreakEmptyBinaryTreeWalk(root, os);

  os << "delete 33" << std::endl;
  BSTDelete(&root, 33);
  TopToBottomLineBreakEmptyBinaryTreeWalk(root, os);

  os << "delete 34" << std::endl;
  BSTDelete(&root, 34);
  TopToBottomLineBreakEmptyBinaryTreeWalk(root, os);

  std::cout << os.str() << std::endl;
}

TEST_F(BinarySearchTreeFixture, BSTFindMin) {
  auto node = BSTFindMin(root);
  EXPECT_EQ(node->value, 13);

  BSTDelete(&root, 13);
  node = BSTFindMin(root);
  EXPECT_EQ(node->value, 15);

  BSTDelete(&root, 15);
  node = BSTFindMin(root);
  EXPECT_EQ(node->value, 16);
}

TEST_F(BinarySearchTreeFixture, BSTGetPrev) {
  int values[] = { 13, 15, 16, 17, 18, 19, 25, 27, 33, 34, 50, 51, 55, 58, 66 };
  for (int i = 0; i < 15; ++i) {
    auto node = BSTFind(root, values[i]);
    auto prev = BSTGetPrev(node);
    if (i != 0) {
      EXPECT_EQ(prev->value, values[i - 1]);
    } else {
      EXPECT_EQ(prev, nullptr);
    }
  }
}

TEST_F(BinarySearchTreeFixture, BSTGetNext) {
  int values[] = { 13, 15, 16, 17, 18, 19, 25, 27, 33, 34, 50, 51, 55, 58, 66 };
  for (int i = 0; i < 15; ++i) {
    auto node = BSTFind(root, values[i]);
    auto next = BSTGetNext(node);
    if (i != 14) {
      EXPECT_EQ(next->value, values[i + 1]);
    } else {
      EXPECT_EQ(next, nullptr);
    }
  }
}