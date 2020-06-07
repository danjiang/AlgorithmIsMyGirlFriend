//
// Created by Dan Jiang on 2020/6/7.
//

#include "find_kth_node_in_bst.h"

BinaryTreeNode* FindKthNodeInBSTCore(BinaryTreeNode *root, int &k) {
  BinaryTreeNode *found_node = nullptr;
  if (root->left != nullptr) {
    found_node = FindKthNodeInBSTCore(root->left, k);
  }
  if (found_node == nullptr) {
    if (k == 1) {
      found_node = root;
    }
    k--;
  }
  if (found_node == nullptr && root->right != nullptr) {
    found_node = FindKthNodeInBSTCore(root->right, k);
  }
  return found_node;
}

BinaryTreeNode* FindKthNodeInBST(BinaryTreeNode *root, int k) {
  if (root == nullptr || k <= 0) {
    return nullptr;
  }
  return FindKthNodeInBSTCore(root, k);
}