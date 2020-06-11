//
// Created by Dan Jiang on 2020/6/7.
//

#include "binary_tree.h"

void ConnectBinaryTreeNodes(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right) {
  if(parent != nullptr) {
    parent->left = left;
    parent->right = right;

    if(left != nullptr)
      left->parent = parent;
    if(right != nullptr)
      right->parent = parent;
  }
}

void DestroyBinaryTree(BinaryTreeNode *root) {
  if (root != nullptr) {
    DestroyBinaryTree(root->left);
    DestroyBinaryTree(root->right);
    delete root;
    root = nullptr;
  }
}

void InorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (root != nullptr) {
    InorderBinaryTreeWalk(root->left, os);
    os << root->value << " ";
    InorderBinaryTreeWalk(root->right, os);
  }
}

void PreorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (root != nullptr) {
    os << root->value << " ";
    PreorderBinaryTreeWalk(root->left, os);
    PreorderBinaryTreeWalk(root->right, os);
  }
}

void PostorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (root != nullptr) {
    PostorderBinaryTreeWalk(root->left, os);
    PostorderBinaryTreeWalk(root->right, os);
    os << root->value << " ";
  }
}

bool IsSameBinaryTree(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  return root1->value == root2->value
      && IsSameBinaryTree(root1->left, root2->left)
      && IsSameBinaryTree(root1->right, root2->right);
}

void BinaryTreeWalkAsLinkList(BinaryTreeNode *head, std::ostringstream &os) {
    BinaryTreeNode *node = head;
    while (node != nullptr){
      os << node->value << " ";
      node = node->right;
    }
}