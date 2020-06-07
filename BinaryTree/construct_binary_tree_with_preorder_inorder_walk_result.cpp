//
// Created by Dan Jiang on 2020/6/7.
//

#include "construct_binary_tree_with_preorder_inorder_walk_result.h"

BinaryTreeNode* ConstructBinaryTreeCore(int *start_preorder, int *end_preorder,
                                        int *start_inorder, int *end_inorder) {
  int root_value = *start_preorder; // first node of preorder is root node

  BinaryTreeNode *root = new BinaryTreeNode();
  root->value = root_value;
  root->left = nullptr;
  root->right = nullptr;

  if (start_preorder == end_preorder) {
    if (start_inorder == end_inorder && *start_preorder == *start_inorder) {
      return root;
    } else {
      throw invalid_input("wrong walk result");
    }
  }

  int *root_inorder = start_inorder; // find root node in inorder
  while (root_inorder <= end_inorder) {
    if (*root_inorder == root_value) {
      break;
    } else if (root_inorder == end_inorder) {
      throw invalid_input("wrong walk result");
    } else {
      root_inorder++;
    }
  }

  int left_length = root_inorder - start_inorder;
  if (left_length > 0) {
    root->left = ConstructBinaryTreeCore(start_preorder + 1, start_preorder + left_length,
                                         start_inorder, root_inorder - 1);
  }
  int right_length = end_inorder - root_inorder;
  if (right_length > 0) {
    root->right = ConstructBinaryTreeCore(end_preorder - right_length + 1, end_preorder,
                                          root_inorder + 1, root_inorder + right_length);
  }

  return root;
}

BinaryTreeNode* ConstructBinaryTree(int *preorder, int *inorder, int length) {
  if (preorder == nullptr || inorder == nullptr || length <= 0) {
    return nullptr;
  }
  return ConstructBinaryTreeCore(preorder, preorder + length - 1,
                                 inorder, inorder + length - 1);
}
