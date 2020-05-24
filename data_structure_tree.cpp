//
// Created by Dan Jiang on 2020/5/5.
//

#include "data_structure_tree.h"

#include <iostream>
#include <iomanip>
#include <deque>
#include <stack>

struct BinaryTreeNode {
  int value;
  BinaryTreeNode *left = nullptr;
  BinaryTreeNode *right = nullptr;

  BinaryTreeNode() {
  }

  BinaryTreeNode(int value) {
    this->value = value;
  }
};

BinaryTreeNode* BinarySearchTreeInsert(BinaryTreeNode **root, int value) {
  BinaryTreeNode *new_node = new BinaryTreeNode();
  new_node->value = value;

  if (root == nullptr || *root == nullptr) {
    *root = new_node;
  } else {
    BinaryTreeNode *parent_node = nullptr;
    BinaryTreeNode *node = *root;
    while (node != nullptr) {
      parent_node = node;
      if (new_node->value < node->value) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    if (new_node->value < parent_node->value) {
      parent_node->left = new_node;
    } else {
      parent_node->right = new_node;
    }
  }

  return new_node;
}

void InorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    InorderBinaryTreeWalk(root->left);
    std::cout << root->value << " ";
    InorderBinaryTreeWalk(root->right);
  }
}

void PreorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    std::cout << root->value << " ";
    PreorderBinaryTreeWalk(root->left);
    PreorderBinaryTreeWalk(root->right);
  }
}

void PostorderBinaryTreeWalk(BinaryTreeNode *root) {
  if (root != nullptr) {
    PostorderBinaryTreeWalk(root->left);
    PostorderBinaryTreeWalk(root->right);
    std::cout << root->value << " ";
  }
}

BinaryTreeNode* FindKthNodeInBSTCore(BinaryTreeNode *root, int &k) {
  BinaryTreeNode *found_node = nullptr;
  if (root->left != nullptr) {
    found_node = FindKthNodeInBSTCore(root->left, k);
  }
  if (found_node == nullptr) {
    if (k == 1) {
      found_node = root;
    }
    k--;
  }
  if (found_node == nullptr && root->right != nullptr) {
    found_node = FindKthNodeInBSTCore(root->right, k);
  }
  return found_node;
}

BinaryTreeNode* FindKthNodeInBST(BinaryTreeNode *root, int k) {
  if (root == nullptr || k <= 0) {
    return nullptr;
  }
  return FindKthNodeInBSTCore(root, k);
}

BinaryTreeNode* ConstructCore(int *start_preorder, int *end_preorder,
    int *start_inorder, int *end_inorder) {
  int root_value = *start_preorder; // first node of preorder is root node

  BinaryTreeNode *root = new BinaryTreeNode();
  root->value = root_value;
  root->left = nullptr;
  root->right = nullptr;

  if (start_preorder == end_preorder) {
    if (start_preorder == end_preorder && *start_preorder == *start_inorder) {
      return root;
    } else {
      std::cout << "Invalid input." << std::endl;
      return nullptr;
    }
  }

  int *root_inorder = start_inorder; // find root node in inorder
  while (root_inorder <= end_inorder) {
    if (*root_inorder == root_value) {
      break;
    } else if (root_inorder == end_inorder) {
      std::cout << "Invalid input." << std::endl;
      return nullptr;
    } else {
      root_inorder++;
    }
  }

  int left_length = root_inorder - start_inorder;
  if (left_length > 0) {
    root->left = ConstructCore(start_preorder + 1, start_preorder + left_length, start_inorder, root_inorder - 1);
  }
  int right_length = end_inorder - root_inorder;
  if (right_length > 0) {
    root->right = ConstructCore(end_preorder - right_length + 1, end_preorder, root_inorder + 1, root_inorder + right_length);
  }

  return root;
}

BinaryTreeNode* Construct(int *preorder, int *inorder, int length) {
  if (preorder == nullptr || inorder == nullptr || length <= 0) {
    return nullptr;
  }
  return ConstructCore(preorder, preorder + length - 1,
      inorder, inorder + length - 1);
}

bool TreeContainSubTree(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  if (root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr) {
    return false;
  }
  if (root1->value != root2->value) {
    return false;
  }

  return TreeContainSubTree(root1->left, root2->left)
      && TreeContainSubTree(root1->right, root2->right);
}

bool TreeHasSubTree(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  bool has = false;

  if (root1 != nullptr && root2 != nullptr) {
    if (root1->value == root2->value) {
      has = TreeContainSubTree(root1, root2);
    }
    if (!has) {
      has = TreeHasSubTree(root1->left, root2);
    }
    if (!has) {
      has = TreeHasSubTree(root1->right, root2);
    }
  }

  return has;
}

void MirrorTree(BinaryTreeNode *root) {
  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return;
  }

  BinaryTreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  if (root->left != nullptr) {
    MirrorTree(root->left);
  }
  if (root->right != nullptr) {
    MirrorTree(root->right);
  }
}

void TopToBottomBinaryTreeWalk(BinaryTreeNode *root) {
  if (!root) {
    return;
  }

  std::deque<BinaryTreeNode *> node_queue;

  node_queue.push_back(root);

  while (!node_queue.empty()) {
    BinaryTreeNode *node = node_queue.front();
    node_queue.pop_front();

    std::cout << node->value << " ";

    if (node->left) {
      node_queue.push_back(node->left);
    }
    if (node->right) {
      node_queue.push_back(node->right);
    }
  }
}

void TopToBottomLineBreakBinaryTreeWalk(BinaryTreeNode *root) {
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

    std::cout << node->value << " ";
    current_level_need_print_count--;

    if (current_level_need_print_count == 0) {
      std::cout << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
    }
  }
}

void TopToBottomLineBreakZBinaryTreeWalk(BinaryTreeNode *root) {
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

    std::cout << node->value << " ";
    current_level_need_print_count--;

    if (current_level_need_print_count == 0) {
      std::cout << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
      is_reverse = !is_reverse;
    }
  }
}

void TopToBottomLineBreakEmptyBinaryTreeWalk(BinaryTreeNode *root) {
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
      std::cout << std::setw(2) << node->value << std::setfill('0') << " ";
    } else {
      std::cout << "-- ";
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
      std::cout << std::endl;
      current_level_need_print_count = next_level_count;
      next_level_count = 0;
    }
  }
}

void TestBinaryTree() {
  BinaryTreeNode *tree = nullptr;
  BinarySearchTreeInsert(&tree, 10);
  BinarySearchTreeInsert(&tree, 6);
  BinarySearchTreeInsert(&tree, 14);
  BinarySearchTreeInsert(&tree, 4);
  BinarySearchTreeInsert(&tree, 8);
  BinarySearchTreeInsert(&tree, 12);
  BinarySearchTreeInsert(&tree, 16);

  // 10 6 4 8 14 12 16
  PreorderBinaryTreeWalk(tree);
  std::cout << std::endl;
  // 4 6 8 10 12 14 16
  InorderBinaryTreeWalk(tree);
  std::cout << std::endl;
  // 4 8 6 12 16 14 10
  PostorderBinaryTreeWalk(tree);
  std::cout << std::endl;
}

void TestFindKthNodeInBST() {
//            8
//        6      10
//       5 7    9  11
  BinaryTreeNode *tree1 = nullptr;
  BinarySearchTreeInsert(&tree1, 8);
  BinarySearchTreeInsert(&tree1, 6);
  BinarySearchTreeInsert(&tree1, 10);
  BinarySearchTreeInsert(&tree1, 5);
  BinarySearchTreeInsert(&tree1, 7);
  BinarySearchTreeInsert(&tree1, 9);
  BinarySearchTreeInsert(&tree1, 11);
  InorderBinaryTreeWalk(tree1);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree1, 3)->value << std::endl;

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
  BinaryTreeNode *tree2 = nullptr;
  BinarySearchTreeInsert(&tree2, 5);
  BinarySearchTreeInsert(&tree2, 4);
  BinarySearchTreeInsert(&tree2, 3);
  BinarySearchTreeInsert(&tree2, 2);
  BinarySearchTreeInsert(&tree2, 1);
  InorderBinaryTreeWalk(tree2);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree2, 3)->value << std::endl;

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
  BinaryTreeNode *tree3 = nullptr;
  BinarySearchTreeInsert(&tree3, 1);
  BinarySearchTreeInsert(&tree3, 2);
  BinarySearchTreeInsert(&tree3, 3);
  BinarySearchTreeInsert(&tree3, 4);
  BinarySearchTreeInsert(&tree3, 5);
  InorderBinaryTreeWalk(tree3);
  std::cout << std::endl;
  std::cout << FindKthNodeInBST(tree3, 3)->value << std::endl;

  BinaryTreeNode *tree4 = nullptr;
  BinarySearchTreeInsert(&tree4, 1);
  InorderBinaryTreeWalk(tree4);
  std::cout << std::endl;
  std::cout << ((FindKthNodeInBST(tree4, 3) == nullptr) ? "Test4 Pass" : "Test4 Fail") << std::endl;

  std::cout << ((FindKthNodeInBST(nullptr, 3) == nullptr) ? "Test5 Pass" : "Test5 Fail") << std::endl;
}

void TestConstruct() {
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
  const int length1 = 8;
  int preorder1[length1] = { 1, 2, 4, 7, 3, 5, 6, 8 };
  int inorder1[length1] = { 4, 7, 2, 1, 5, 3, 8, 6 };
  BinaryTreeNode *tree1 = Construct(preorder1, inorder1, length1);
  TopToBottomLineBreakEmptyBinaryTreeWalk(tree1);

//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
  const int length2 = 5;
  int preorder2[length2] = { 1, 2, 3, 4, 5 };
  int inorder2[length2] = { 5, 4, 3, 2, 1 };
  BinaryTreeNode *tree2 = Construct(preorder2, inorder2, length2);
  TopToBottomLineBreakEmptyBinaryTreeWalk(tree2);

//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//                   \
//                    5
  const int length3 = 5;
  int preorder3[length3] = { 1, 2, 3, 4, 5 };
  int inorder3[length3] = { 1, 2, 3, 4, 5 };
  BinaryTreeNode *tree3 = Construct(preorder3, inorder3, length3);
  TopToBottomLineBreakEmptyBinaryTreeWalk(tree3);

  const int length4 = 1;
  int preorder4[length4] = { 1 };
  int inorder4[length4] = { 1 };
  BinaryTreeNode *tree4 = Construct(preorder4, inorder4, length4);
  TopToBottomLineBreakEmptyBinaryTreeWalk(tree4);

//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
  const int length5 = 7;
  int preorder5[length5] = { 1, 2, 4, 5, 3, 6, 7 };
  int inorder5[length5] = { 4, 2, 5, 1, 6, 3, 7 };
  BinaryTreeNode *tree5 = Construct(preorder5, inorder5, length5);
  TopToBottomLineBreakEmptyBinaryTreeWalk(tree5);

  Construct(nullptr, nullptr, 0);

  const int length6 = 7;
  int preorder6[length6] = { 1, 2, 4, 5, 3, 6, 7 };
  int inorder6[length6] = { 4, 2, 8, 1, 6, 3, 7 };
  Construct(preorder6, inorder6, length6);
}

void TestTreeHasSubTree() {
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
  BinaryTreeNode *node11 = new BinaryTreeNode(8);
  BinaryTreeNode *node12 = new BinaryTreeNode(8);
  BinaryTreeNode *node13 = new BinaryTreeNode(7);
  BinaryTreeNode *node14 = new BinaryTreeNode(9);
  BinaryTreeNode *node15 = new BinaryTreeNode(2);
  BinaryTreeNode *node16 = new BinaryTreeNode(4);
  BinaryTreeNode *node17 = new BinaryTreeNode(7);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  node15->left = node16;
  node15->right = node17;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node11);
  BinaryTreeNode *node21 = new BinaryTreeNode(8);
  BinaryTreeNode *node22 = new BinaryTreeNode(9);
  BinaryTreeNode *node23 = new BinaryTreeNode(2);
  node21->left = node22;
  node21->right = node23;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node21);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node11, node21) ? "True" : "False") << std::endl;

//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
  node15->value = 3;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node11);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node21);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node11, node21) ? "True" : "False") << std::endl;

//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
  BinaryTreeNode *node31 = new BinaryTreeNode(8);
  BinaryTreeNode *node32 = new BinaryTreeNode(8);
  BinaryTreeNode *node33 = new BinaryTreeNode(9);
  BinaryTreeNode *node34 = new BinaryTreeNode(2);
  BinaryTreeNode *node35 = new BinaryTreeNode(5);
  node31->left = node32;
  node32->left = node33;
  node33->left = node34;
  node34->left = node35;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node31);
  BinaryTreeNode *node41 = new BinaryTreeNode(8);
  BinaryTreeNode *node42 = new BinaryTreeNode(9);
  BinaryTreeNode *node43 = new BinaryTreeNode(2);
  node41->left = node42;
  node42->left = node43;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node41);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node31, node41) ? "True" : "False") << std::endl;

//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
  node43->value = 3;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node31);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node41);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node31, node41) ? "True" : "False") << std::endl;

//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
  BinaryTreeNode *node51 = new BinaryTreeNode(8);
  BinaryTreeNode *node52 = new BinaryTreeNode(8);
  BinaryTreeNode *node53 = new BinaryTreeNode(9);
  BinaryTreeNode *node54 = new BinaryTreeNode(2);
  BinaryTreeNode *node55 = new BinaryTreeNode(5);
  node51->right = node52;
  node52->right = node53;
  node53->right = node54;
  node54->right = node55;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node51);
  BinaryTreeNode *node61 = new BinaryTreeNode(8);
  BinaryTreeNode *node62 = new BinaryTreeNode(9);
  BinaryTreeNode *node63 = new BinaryTreeNode(2);
  node61->right = node62;
  node62->right = node63;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node61);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node51, node61) ? "True" : "False") << std::endl;

//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
  BinaryTreeNode *node64 = new BinaryTreeNode(3);
  node62->left = node64;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node51);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node61);
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node51, node61) ? "True" : "False") << std::endl;

  std::cout << "Has Sub Tree: " << (TreeHasSubTree(node11, nullptr) ? "True" : "False") << std::endl;
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(nullptr, node11) ? "True" : "False") << std::endl;
  std::cout << "Has Sub Tree: " << (TreeHasSubTree(nullptr, nullptr) ? "True" : "False") << std::endl;
}

void TestMirrorTree() {
//            8
//        6      10
//       5 7    9  11
  BinaryTreeNode *node11 = new BinaryTreeNode(8);
  BinaryTreeNode *node12 = new BinaryTreeNode(6);
  BinaryTreeNode *node13 = new BinaryTreeNode(10);
  BinaryTreeNode *node14 = new BinaryTreeNode(5);
  BinaryTreeNode *node15 = new BinaryTreeNode(7);
  BinaryTreeNode *node16 = new BinaryTreeNode(9);
  BinaryTreeNode *node17 = new BinaryTreeNode(11);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  node13->left = node16;
  node13->right = node17;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node11);
  MirrorTree(node11);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node11);

//            8
//          7
//        6
//      5
//    4
  BinaryTreeNode *node21 = new BinaryTreeNode(8);
  BinaryTreeNode *node22 = new BinaryTreeNode(7);
  BinaryTreeNode *node23 = new BinaryTreeNode(6);
  BinaryTreeNode *node24 = new BinaryTreeNode(5);
  BinaryTreeNode *node25 = new BinaryTreeNode(4);
  node21->left = node22;
  node22->left = node23;
  node23->left = node24;
  node24->left = node25;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node21);
  MirrorTree(node21);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node21);

//            8
//             7
//              6
//               5
//                4
  BinaryTreeNode *node31 = new BinaryTreeNode(8);
  BinaryTreeNode *node32 = new BinaryTreeNode(7);
  BinaryTreeNode *node33 = new BinaryTreeNode(6);
  BinaryTreeNode *node34 = new BinaryTreeNode(5);
  BinaryTreeNode *node35 = new BinaryTreeNode(4);
  node31->right = node32;
  node32->right = node33;
  node33->right = node34;
  node34->right = node35;
  TopToBottomLineBreakEmptyBinaryTreeWalk(node31);
  MirrorTree(node31);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node31);

  BinaryTreeNode *node41 = new BinaryTreeNode(8);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node41);
  MirrorTree(node41);
  TopToBottomLineBreakEmptyBinaryTreeWalk(node41);

  MirrorTree(nullptr);
}

void TestTopToBottomBinaryTreeWalk() {
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
  BinaryTreeNode *node11 = new BinaryTreeNode(10);
  BinaryTreeNode *node12 = new BinaryTreeNode(6);
  BinaryTreeNode *node13 = new BinaryTreeNode(14);
  BinaryTreeNode *node14 = new BinaryTreeNode(4);
  BinaryTreeNode *node15 = new BinaryTreeNode(8);
  BinaryTreeNode *node16 = new BinaryTreeNode(12);
  BinaryTreeNode *node17 = new BinaryTreeNode(16);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  node13->left = node16;
  node13->right = node17;
  TopToBottomBinaryTreeWalk(node11);
  std::cout << std::endl;
  TopToBottomLineBreakBinaryTreeWalk(node11);
  TopToBottomLineBreakZBinaryTreeWalk(node11);
  std::cout << std::endl;

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
  BinaryTreeNode *node21 = new BinaryTreeNode(5);
  BinaryTreeNode *node22 = new BinaryTreeNode(4);
  BinaryTreeNode *node23 = new BinaryTreeNode(3);
  BinaryTreeNode *node24 = new BinaryTreeNode(2);
  BinaryTreeNode *node25 = new BinaryTreeNode(1);
  node21->left = node22;
  node22->left = node23;
  node23->left = node24;
  node24->left = node25;
  TopToBottomBinaryTreeWalk(node21);
  std::cout << std::endl;
  TopToBottomLineBreakBinaryTreeWalk(node21);
  TopToBottomLineBreakZBinaryTreeWalk(node21);
  std::cout << std::endl;

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
  BinaryTreeNode *node31 = new BinaryTreeNode(1);
  BinaryTreeNode *node32 = new BinaryTreeNode(2);
  BinaryTreeNode *node33 = new BinaryTreeNode(3);
  BinaryTreeNode *node34 = new BinaryTreeNode(4);
  BinaryTreeNode *node35 = new BinaryTreeNode(5);
  node31->right = node32;
  node32->right = node33;
  node33->right = node34;
  node34->right = node35;
  TopToBottomBinaryTreeWalk(node31);
  std::cout << std::endl;
  TopToBottomLineBreakBinaryTreeWalk(node31);
  TopToBottomLineBreakZBinaryTreeWalk(node31);
  std::cout << std::endl;

  BinaryTreeNode *node41 = new BinaryTreeNode(1);
  TopToBottomBinaryTreeWalk(node41);
  std::cout << std::endl;
  TopToBottomLineBreakBinaryTreeWalk(node41);
  TopToBottomLineBreakZBinaryTreeWalk(node41);
  std::cout << std::endl;

  TopToBottomBinaryTreeWalk(nullptr);
  TopToBottomLineBreakBinaryTreeWalk(nullptr);
  TopToBottomLineBreakZBinaryTreeWalk(nullptr);
}