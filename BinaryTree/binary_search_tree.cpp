//
// Created by Dan Jiang on 2020/7/28.
//

#include "binary_search_tree.h"

BinaryTreeNode* BSTFind(BinaryTreeNode *root, int value) {
  if (root == nullptr) {
    return nullptr;
  }
  if (value == root->value) {
    return root;
  } else if (value < root->value) {
    return BSTFind(root->left, value);
  } else {
    return BSTFind(root->right, value);
  }
}

BinaryTreeNode* BSTFindMin(BinaryTreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->left == nullptr) {
    return root;
  } else {
    return BSTFindMin(root->left);
  }
}

BinaryTreeNode* BSTFindMax(BinaryTreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->right == nullptr) {
    return root;
  } else {
    return BSTFindMax(root->right);
  }
}

BinaryTreeNode* BSTGetPrev(BinaryTreeNode *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->left != nullptr) {
    return BSTFindMax(node->left);
  } else if (node->parent != nullptr) {
    auto parent = node->parent;
    if (parent->right == node) {
      return parent;
    }
    while (parent->parent != nullptr && parent->parent->left == parent) {
      parent = parent->parent;
    }
    return parent->parent;
  }
  return nullptr;
}

BinaryTreeNode* BSTGetNext(BinaryTreeNode *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->right != nullptr) {
    return BSTFindMin(node->right);
  } else if (node->parent != nullptr) {
    auto parent = node->parent;
    if (parent->left == node) {
      return parent;
    }
    while (parent->parent != nullptr && parent->parent->right == parent) {
      parent = parent->parent;
    }
    return parent->parent;
  }
  return nullptr;
}

void BSTInsertCore(BinaryTreeNode *root, int value) {
  if (value < root->value) {
    if (root->left == nullptr) {
      auto node = new BinaryTreeNode(value);
      node->parent = root;
      root->left = node;
    } else {
      BSTInsertCore(root->left, value);
    }
  } else {
    if (root->right == nullptr) {
      auto node = new BinaryTreeNode(value);
      node->parent = root;
      root->right = node;
    } else {
      BSTInsertCore(root->right, value);
    }
  }
}

void BSTInsert(BinaryTreeNode **root, int value) {
  if (root == nullptr) {
    return;
  }
  if (*root == nullptr) {
    *root = new BinaryTreeNode(value);
    return;
  }
  BSTInsertCore(*root, value);
}

void BSTDeleteCore(BinaryTreeNode **root, BinaryTreeNode *parent, BinaryTreeNode *node, int value) {
  if (node == nullptr) {
    return;
  }
  if (value == node->value) {
    BinaryTreeNode *child = nullptr;
    if (node->left != nullptr && node->right != nullptr) {
      auto min_parent = node;
      auto min = node->right;
      while (min->left != nullptr) {
        min_parent = min;
        min = min->left;
      }
      if (min_parent->left == min) {
        min_parent->left = min->right;
      } else {
        min_parent->right = min->right;
      }
      child = min;
      child->left = node->left;
      child->right = node->right;
    } else if (node->left != nullptr) {
      child = node->left;
    } else if (node->right != nullptr) {
      child = node->right;
    }
    if (parent != nullptr) {
      if (parent->left == node) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    } else {
      *root = child;
    }
    delete node;
  } else if (value < node->value) {
    BSTDeleteCore(root, node, node->left, value);
  } else {
    BSTDeleteCore(root, node, node->right, value);
  }
}

void BSTDelete(BinaryTreeNode **root, int value) {
  if (root == nullptr || *root == nullptr) {
    return;
  }
  BSTDeleteCore(root, nullptr, *root, value);
}