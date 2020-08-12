//
// Created by Dan Jiang on 2020/6/12.
//

#include "get_binary_tree_inorder_walk_next.h"

BinaryTreeNode* GetBinaryTreeInorderWalkNext(BinaryTreeNode *node) {
  if (node == nullptr) {
    return nullptr;
  }

  BinaryTreeNode *next = nullptr;
  if (node->right != nullptr) {
    BinaryTreeNode *right = node->right;
    while (right->left != nullptr) {
      right = right->left;
    }
    next = right;
  } else if (node->parent != nullptr) {
    BinaryTreeNode *current = node;
    BinaryTreeNode *parent = node->parent;
    while (parent != nullptr && current == parent->right) {
      current = parent;
      parent = parent->parent;
    }
    next = parent;
  }

  return next;
}