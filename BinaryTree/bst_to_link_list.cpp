//
// Created by Dan Jiang on 2020/6/11.
//

#include "bst_to_link_list.h"

void BST2LinkListCore(BinaryTreeNode *node, BinaryTreeNode **last_node) {
  if (node == nullptr) {
    return;
  }

  BinaryTreeNode *current_node = node;

  if (current_node->left != nullptr) {
    BST2LinkListCore(current_node->left, last_node);
  }

  current_node->left = *last_node;
  if (*last_node != nullptr) {
    (*last_node)->right = current_node;
  }

  *last_node = current_node;

  if (current_node->right != nullptr) {
    BST2LinkListCore(current_node->right, last_node);
  }
}

BinaryTreeNode* BST2LinkList(BinaryTreeNode *root) {
  BinaryTreeNode *last_node = nullptr;

  BST2LinkListCore(root, &last_node);

  BinaryTreeNode *head = last_node;
  while (head != nullptr && head->left != nullptr) {
    head = head->left;
  }

  return head;
}