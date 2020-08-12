//
// Created by Dan Jiang on 2020/6/11.
//

#include "binary_tree_depth.h"

int BinaryTreeDepth(BinaryTreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int left = BinaryTreeDepth(root->left);
  int right = BinaryTreeDepth(root->right);
  return left > right ? left + 1 : right + 1;
}