//
// Created by Dan Jiang on 2020/6/12.
//

#include "binary_tree_is_symmetrical.h"

bool BinaryTreeIsSymmetricalCore(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  if (root1->value != root2->value) {
    return false;
  }
  return BinaryTreeIsSymmetricalCore(root1->left, root2->right)
      && BinaryTreeIsSymmetricalCore(root1->right, root2->left);
}

bool BinaryTreeIsSymmetrical(BinaryTreeNode *root) {
  return BinaryTreeIsSymmetricalCore(root, root);
}