//
// Created by Dan Jiang on 2020/6/7.
//

#include "mirror_binary_tree.h"

void MirrorBinaryTree(BinaryTreeNode *root) {
  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return;
  }

  BinaryTreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  if (root->left != nullptr) {
    MirrorBinaryTree(root->left);
  }
  if (root->right != nullptr) {
    MirrorBinaryTree(root->right);
  }
}