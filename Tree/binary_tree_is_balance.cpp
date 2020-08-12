//
// Created by Dan Jiang on 2020/6/12.
//

#include "binary_tree_is_balance.h"

bool BinaryTreeIsBalanceCore(BinaryTreeNode *root, int *depth) {
  if (root == nullptr) {
    *depth = 0;
    return true;
  }

  int left, right;
  if (BinaryTreeIsBalanceCore(root->left, &left)
      && BinaryTreeIsBalanceCore(root->right, &right)) {
    int diff = left - right;
    if (diff <= 1 && diff >= -1) {
      *depth = left > right ? left + 1 : right + 1;
      return true;
    }
  }

  return false;
}

bool BinaryTreeIsBalance(BinaryTreeNode *root) {
  int depth = 0;
  return BinaryTreeIsBalanceCore(root, &depth);
}
