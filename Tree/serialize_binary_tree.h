//
// Created by Dan Jiang on 2020/6/11.
//

#ifndef ALGORITHMISMYGIRLFRIEND_BINARYTREE_SERIALIZE_BINARY_TREE_H_
#define ALGORITHMISMYGIRLFRIEND_BINARYTREE_SERIALIZE_BINARY_TREE_H_

#include "binary_tree.h"

void SerializeBinaryTree(BinaryTreeNode *root, std::ostringstream &os);
void DeserializeBinaryTree(BinaryTreeNode **root, std::istringstream &is);

#endif //ALGORITHMISMYGIRLFRIEND_BINARYTREE_SERIALIZE_BINARY_TREE_H_
