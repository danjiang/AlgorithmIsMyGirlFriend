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

BinaryTreeNode* ConstructCore(int *start_preorder, int *end_preorder,
    int *start_inorder, int *end_inorder) {
  int root_value = *start_preorder; // first node of preorder is root node

  BinaryTreeNode *root = new BinaryTreeNode();
  root->value = root_value;
  root->left = nullptr;
  root->right = nullptr;

  if (start_preorder == end_preorder) {
    if (start_preorder == end_preorder && *start_preorder == *start_inorder) {
      return root;
    } else {
      std::cout << "Invalid input." << std::endl;
      return nullptr;
    }
  }

  int *root_inorder = start_inorder; // find root node in inorder
  while (root_inorder <= end_inorder) {
    if (*root_inorder == root_value) {
      break;
    } else if (root_inorder == end_inorder) {
      std::cout << "Invalid input." << std::endl;
      return nullptr;
    } else {
      root_inorder++;
    }
  }

  int left_length = root_inorder - start_inorder;
  if (left_length > 0) {
    root->left = ConstructCore(start_preorder + 1, start_preorder + left_length, start_inorder, root_inorder - 1);
  }
  int right_length = end_inorder - root_inorder;
  if (right_length > 0) {
    root->right = ConstructCore(end_preorder - right_length + 1, end_preorder, root_inorder + 1, root_inorder + right_length);
  }

  return root;
}

BinaryTreeNode* Construct(int *preorder, int *inorder, int length) {
  if (preorder == nullptr || inorder == nullptr || length <= 0) {
    return nullptr;
  }
  return ConstructCore(preorder, preorder + length - 1,
      inorder, inorder + length - 1);
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

void TestConstruct() {
  const int length1 = 8;
  int preorder1[length1] = { 1, 2, 4, 7, 3, 5, 6, 8 };
  int inorder1[length1] = { 4, 7, 2, 1, 5, 3, 8, 6 };
  BinaryTreeNode *tree1 = Construct(preorder1, inorder1, length1);
  PreorderBinaryTreeWalk(tree1);
  std::cout << std::endl;
  InorderBinaryTreeWalk(tree1);
  std::cout << std::endl;

  const int length2 = 5;
  int preorder2[length2] = { 1, 2, 3, 4, 5 };
  int inorder2[length2] = { 5, 4, 3, 2, 1 };
  BinaryTreeNode *tree2 = Construct(preorder2, inorder2, length2);
  PreorderBinaryTreeWalk(tree2);
  std::cout << std::endl;
  InorderBinaryTreeWalk(tree2);
  std::cout << std::endl;

  const int length3 = 5;
  int preorder3[length3] = { 1, 2, 3, 4, 5 };
  int inorder3[length3] = { 1, 2, 3, 4, 5 };
  BinaryTreeNode *tree3 = Construct(preorder3, inorder3, length3);
  PreorderBinaryTreeWalk(tree3);
  std::cout << std::endl;
  InorderBinaryTreeWalk(tree3);
  std::cout << std::endl;

  const int length4 = 1;
  int preorder4[length4] = { 1 };
  int inorder4[length4] = { 1 };
  BinaryTreeNode *tree4 = Construct(preorder4, inorder4, length4);
  PreorderBinaryTreeWalk(tree4);
  std::cout << std::endl;
  InorderBinaryTreeWalk(tree4);
  std::cout << std::endl;

  std::cout << (Construct(nullptr, nullptr, 0) == nullptr ? "Test5 Pass" : "Test5 Fail") << std::endl;

  const int length6 = 7;
  int preorder6[length6] = { 1, 2, 4, 5, 3, 6, 7 };
  int inorder6[length6] = { 4, 2, 8, 1, 6, 3, 7 };
  Construct(preorder6, inorder6, length6);
}