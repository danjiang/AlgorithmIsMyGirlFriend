//
// Created by Dan Jiang on 2020/6/14.
//

#include "get_tree_last_common_parent.h"

bool GetNodePath(TreeNode *root, TreeNode *node, std::vector<TreeNode *> &path) {
  if (root->value == node->value) {
    return true;
  }

  path.push_back(root);

  bool found = false;

  std::vector<TreeNode *>::iterator it = root->children.begin();
  while (!found && it != root->children.end()) {
    found = GetNodePath(*it, node, path);
    ++it;
  }

  if (!found) {
    path.pop_back();
  }

  return found;
}

TreeNode* GetLastCommonNode(std::vector<TreeNode *> &path1, std::vector<TreeNode *> &path2) {
  std::vector<TreeNode *>::iterator it1 = path1.begin();
  std::vector<TreeNode *>::iterator it2 = path2.begin();

  TreeNode *last = nullptr;

  while (it1 != path1.end() && it2 != path2.end() && *it1 == *it2) {
    last = *it1;
    it1++;
    it2++;
  }

  return last;
}

TreeNode* GetTreeLastCommonParent(TreeNode *root, TreeNode *node1, TreeNode *node2) {
  if (root == nullptr || node1 == nullptr || node2 == nullptr) {
    return nullptr;
  }
  std::vector<TreeNode *> path1;
  GetNodePath(root, node1, path1);
  std::vector<TreeNode *> path2;
  GetNodePath(root, node2, path2);
  return GetLastCommonNode(path1, path2);
}