//
// Created by Dan Jiang on 2020/6/14.
//

#ifndef ALGORITHMISMYGIRLFRIEND_TREE_TREE_H_
#define ALGORITHMISMYGIRLFRIEND_TREE_TREE_H_

#include <vector>

struct TreeNode {
  int value;
  std::vector<TreeNode *> children;

  TreeNode() {
  }

  TreeNode(int value) {
    this->value = value;
  }
};

void ConnectTreeNodes(TreeNode *parent, TreeNode *child);

#endif //ALGORITHMISMYGIRLFRIEND_TREE_TREE_H_
