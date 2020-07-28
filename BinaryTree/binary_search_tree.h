//
// Created by Dan Jiang on 2020/7/28.
//

#ifndef ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_SEARCH_TREE_H_
#define ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_SEARCH_TREE_H_

#include "binary_tree.h"

BinaryTreeNode* BSTFind(BinaryTreeNode *root, int value);
BinaryTreeNode* BSTFindMin(BinaryTreeNode *root);
BinaryTreeNode* BSTFindMax(BinaryTreeNode *root);
BinaryTreeNode* BSTGetPrev(BinaryTreeNode *node);
BinaryTreeNode* BSTGetNext(BinaryTreeNode *node);
void BSTInsert(BinaryTreeNode **root, int value);
void BSTDelete(BinaryTreeNode **root, int value);

#endif //ALGORITHMISMYGIRLFRIEND_BINARYTREE_BINARY_SEARCH_TREE_H_
