//
// Created by Dan Jiang on 2020/6/7.
//

#ifndef ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_TREE_NODE_H_
#define ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_TREE_NODE_H_

#include <sstream>

struct BinaryTreeNode {
  int value;
  BinaryTreeNode *left = nullptr;
  BinaryTreeNode *right = nullptr;
  BinaryTreeNode *parent = nullptr;

  BinaryTreeNode() {
  }

  BinaryTreeNode(int value) {
    this->value = value;
  }
};

void ConnectBinaryTreeNodes(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right);
void DestroyBinaryTree(BinaryTreeNode *root);
void InorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os);
void PreorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os);
void PostorderBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os);
bool IsSameBinaryTree(BinaryTreeNode *root1, BinaryTreeNode *root2);

#endif //ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_TREE_NODE_H_
