//
// Created by Dan Jiang on 2020/6/7.
//

#include "find_summary_path_in_binary_tree.h"

#include <vector>

void FindSummaryPathInBTCore(BinaryTreeNode *root, int expected_sum, std::vector<int> &path, int current_sum, std::ostringstream &os) {
  current_sum += root->value;
  path.push_back(root->value);

  bool is_leaf = root->left == nullptr && root->right == nullptr;
  if (current_sum == expected_sum && is_leaf) {
    std::vector<int>::iterator it = path.begin();
    for (; it != path.end(); it++) {
      os << *it << " ";
    }
    os << std::endl;
  }

  if (root->left != nullptr) {
    FindSummaryPathInBTCore(root->left, expected_sum, path, current_sum, os);
  }
  if (root->right != nullptr) {
    FindSummaryPathInBTCore(root->right, expected_sum, path, current_sum, os);
  }

  path.pop_back();
}

void FindSummaryPathInBT(BinaryTreeNode *root, int expected_sum, std::ostringstream &os) {
  if (root == nullptr) {
    return;
  }

  std::vector<int> path;
  int current_sum = 0;
  FindSummaryPathInBTCore(root, expected_sum, path, current_sum, os);
}

