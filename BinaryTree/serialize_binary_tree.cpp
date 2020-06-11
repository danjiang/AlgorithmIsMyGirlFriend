//
// Created by Dan Jiang on 2020/6/11.
//

#include "serialize_binary_tree.h"

bool ReadStream(std::istringstream &stream, int *number) {
  if(stream.eof())
    return false;

  char buffer[32];
  buffer[0] = '\0';

  char ch;
  stream >> ch;
  int i = 0;
  while(!stream.eof() && ch != ',')
  {
    buffer[i++] = ch;
    stream >> ch;
  }

  bool isNumeric = false;
  if(i > 0 && buffer[0] != '$')
  {
    *number = atoi(buffer);
    isNumeric = true;
  }

  return isNumeric;
}

void SerializeBinaryTree(BinaryTreeNode *root, std::ostringstream &os) {
  if (root == nullptr) {
    os << "$,";
    return;
  } else {
    os << root->value << ",";
  }
  SerializeBinaryTree(root->left, os);
  SerializeBinaryTree(root->right, os);
}

void DeserializeBinaryTree(BinaryTreeNode **root, std::istringstream &is) {
  int number;
  if (ReadStream(is, &number)) {
    *root = new BinaryTreeNode();
    (*root)->value = number;
    (*root)->left = nullptr;
    (*root)->right = nullptr;

    DeserializeBinaryTree(&((*root)->left), is);
    DeserializeBinaryTree(&((*root)->right), is);
  }
}
