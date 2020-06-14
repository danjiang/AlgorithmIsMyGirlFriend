//
// Created by Dan Jiang on 2020/6/14.
//

#include "tree.h"

void ConnectTreeNodes(TreeNode *parent, TreeNode *child) {
  if(parent != nullptr) {
    parent->children.push_back(child);
  }
}