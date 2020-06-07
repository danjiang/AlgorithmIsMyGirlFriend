//
// Created by Dan Jiang on 2020/6/7.
//

#include "top_to_bottom_binary_tree_walk.h"

#include <deque>
#include <stack>
#include <iomanip>

void TopToBottomBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (!root) {
    return;
  }

  std::deque<BinaryTreeNode *> node_queue;

  node_queue.push_back(root);

  while (!node_queue.empty()) {
    BinaryTreeNode *node = node_queue.front();
    node_queue.pop_front();

    os << node->value << " ";

    if (node->left) {
      node_queue.push_back(node->left);
    }
    if (node->right) {
      node_queue.push_back(node->right);
    }
  }
}

void TopToBottomLineBreakBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (!root) {
    return;
  }

  std::deque<BinaryTreeNode *> node_queue;
  int next_level_count = 0;
  int current_level_need_print_count = 0;

  node_queue.push_back(root);
  current_level_need_print_count = 1;

  while (!node_queue.empty()) {
    BinaryTreeNode *node = node_queue.front();
    node_queue.pop_front();

    if (node->left) {
      node_queue.push_back(node->left);
      next_level_count++;
    }
    if (node->right) {
      node_queue.push_back(node->right);
      next_level_count++;
    }

    os << node->value << " ";
    current_level_need_print_count--;

    if (current_level_need_print_count == 0) {
      os << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
    }
  }
}

void TopToBottomLineBreakZBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (!root) {
    return;
  }

  std::stack<BinaryTreeNode *> node_stack;
  std::stack<BinaryTreeNode *> node_reverse_stack;
  int next_level_count = 0;
  int current_level_need_print_count = 0;
  bool is_reverse = false;

  node_stack.push(root);
  current_level_need_print_count = 1;

  while (!node_stack.empty() || !node_reverse_stack.empty()) {
    BinaryTreeNode *node;
    if (!is_reverse) {
      node = node_stack.top();
      node_stack.pop();
      if (node->left) {
        node_reverse_stack.push(node->left);
        next_level_count++;
      }
      if (node->right) {
        node_reverse_stack.push(node->right);
        next_level_count++;
      }
    } else {
      node = node_reverse_stack.top();
      node_reverse_stack.pop();
      if (node->right) {
        node_stack.push(node->right);
        next_level_count++;
      }
      if (node->left) {
        node_stack.push(node->left);
        next_level_count++;
      }
    }

    os << node->value << " ";
    current_level_need_print_count--;

    if (current_level_need_print_count == 0) {
      os << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
      is_reverse = !is_reverse;
    }
  }
}

void TopToBottomLineBreakEmptyBinaryTreeWalk(BinaryTreeNode *root, std::ostringstream &os) {
  if (!root) {
    return;
  }

  std::deque<BinaryTreeNode *> node_queue;
  int next_level_count = 0;
  int current_level_need_print_count = 0;
  BinaryTreeNode *empty_node = new BinaryTreeNode(-1);

  node_queue.push_back(root);
  current_level_need_print_count = 1;

  while (!node_queue.empty()) {
    BinaryTreeNode *node = node_queue.front();
    node_queue.pop_front();

    if (node != empty_node) {
      os << std::setw(2) << node->value << std::setfill('0') << " ";
    } else {
      os << "-- ";
    }
    current_level_need_print_count--;

    if (node != empty_node) {
      if (node->left) {
        node_queue.push_back(node->left);
      } else {
        node_queue.push_back(empty_node);
      }
      next_level_count++;
      if (node->right) {
        node_queue.push_back(node->right);
      } else {
        node_queue.push_back(empty_node);
      }
      next_level_count++;
    }

    if (current_level_need_print_count == 0) {
      os << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
    }
  }
}
