//
// Created by Dan Jiang on 2020/5/5.
//

#include "data_structure_tree.h"
#include <iostream>

struct BinaryTreeNode {
  int value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
};

BinaryTreeNode* BinarySearchTreeInsert(BinaryTreeNode **root, int value) {
  BinaryTreeNode *new_node = new BinaryTreeNode();
  new_node->value = value;

  if (root == nullptr || *root == nullptr) {
    *root = new_node;
  } else {
    BinaryTreeNode *parent_node = nullptr;
    BinaryTreeNode *node = *root;
    while (node != nullptr) {
      parent_node = node;
      if (new_node->value < node->value) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    if (new_node->value < parent_node->value) {
      parent_node->left = new_node;
    } else {
      parent_node->right = new_node;
    }
  }

  return new_node;
}

void InorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    InorderBinaryTreeWalk(root->left);
    std::cout << root->value << " ";
    InorderBinaryTreeWalk(root->right);
  }
}

void PreorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    std::cout << root->value << " ";
    PreorderBinaryTreeWalk(root->left);
    PreorderBinaryTreeWalk(root->right);
  }
}

void PostorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    PostorderBinaryTreeWalk(root->left);
    PostorderBinaryTreeWalk(root->right);
    std::cout << root->value << " ";
  }
}

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

void TestBinaryTree() {
  BinaryTreeNode *tree = nullptr;
  BinarySearchTreeInsert(&tree, 10);
  BinarySearchTreeInsert(&tree, 6);
  BinarySearchTreeInsert(&tree, 14);
  BinarySearchTreeInsert(&tree, 4);
  BinarySearchTreeInsert(&tree, 8);
  BinarySearchTreeInsert(&tree, 12);
  BinarySearchTreeInsert(&tree, 16);

  // 10 6 4 8 14 12 16
  PreorderBinaryTreeWalk(tree);
  std::cout << std::endl;
  // 4 6 8 10 12 14 16
  InorderBinaryTreeWalk(tree);
  std::cout << std::endl;
  // 4 8 6 12 16 14 10
  PostorderBinaryTreeWalk(tree);
  std::cout << std::endl;
}

void TestFindKthNodeInBST() {
  BinaryTreeNode *tree1 = nullptr;
  BinarySearchTreeInsert(&tree1, 8);
  BinarySearchTreeInsert(&tree1, 6);
  BinarySearchTreeInsert(&tree1, 10);
  BinarySearchTreeInsert(&tree1, 5);
  BinarySearchTreeInsert(&tree1, 7);
  BinarySearchTreeInsert(&tree1, 9);
  BinarySearchTreeInsert(&tree1, 11);
  InorderBinaryTreeWalk(tree1);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree1, 3)->value << std::endl;

  BinaryTreeNode *tree2 = nullptr;
  BinarySearchTreeInsert(&tree2, 5);
  BinarySearchTreeInsert(&tree2, 4);
  BinarySearchTreeInsert(&tree2, 3);
  BinarySearchTreeInsert(&tree2, 2);
  BinarySearchTreeInsert(&tree2, 1);
  InorderBinaryTreeWalk(tree2);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree2, 3)->value << std::endl;

  BinaryTreeNode *tree3 = nullptr;
  BinarySearchTreeInsert(&tree3, 1);
  BinarySearchTreeInsert(&tree3, 2);
  BinarySearchTreeInsert(&tree3, 3);
  BinarySearchTreeInsert(&tree3, 4);
  BinarySearchTreeInsert(&tree3, 5);
  InorderBinaryTreeWalk(tree3);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree3, 3)->value << std::endl;

  BinaryTreeNode *tree4 = nullptr;
  BinarySearchTreeInsert(&tree4, 1);
  InorderBinaryTreeWalk(tree4);
  std::cout << std::endl;
  std::cout << ((FindKthNodeInBST(tree4, 3) == nullptr) ? "Test4 Pass" : "Test4 Fail") << std::endl;

  std::cout << ((FindKthNodeInBST(nullptr, 3) == nullptr) ? "Test5 Pass" : "Test5 Fail") << std::endl;
}