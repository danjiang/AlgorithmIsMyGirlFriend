//
// Created by Dan Jiang on 2020/6/7.
//

#include "binary_tree_contain_sub_tree.h"

bool BinaryTreeContainSubTreeCore(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  if (root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr) {
    return false;
  }
  if (root1->value != root2->value) {
    return false;
  }

  return BinaryTreeContainSubTreeCore(root1->left, root2->left)
      && BinaryTreeContainSubTreeCore(root1->right, root2->right);
}

bool BinaryTreeContainSubTree(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  bool contain = false;

  if (root1 != nullptr && root2 != nullptr) {
    if (root1->value == root2->value) {
      contain = BinaryTreeContainSubTreeCore(root1, root2);
    }
    if (!contain) {
      contain = BinaryTreeContainSubTree(root1->left, root2);
    }
    if (!contain) {
      contain = BinaryTreeContainSubTree(root1->right, root2);
    }
  }

  return contain;
}