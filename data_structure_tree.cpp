//
// Created by Dan Jiang on 2020/5/5.
//

#include "data_structure_tree.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <stack>
#include <vector>

struct BinaryTreeNode {
  int value;
  BinaryTreeNode *left = nullptr;
  BinaryTreeNode *right = nullptr;
  BinaryTreeNode *parent = nullptr;

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

bool IsPostorderSequenceOfBST(int *sequence, int length) {
  if (sequence == nullptr || length <= 0) {
    return false;
  }

  int root = sequence[length - 1];

  int i = 0;
  for (; i < length - 1; ++i) {
    if (sequence[i] > root) {
      break;
    }
  }

  int j = i;
  for (; j < length - 1; ++j) {
    if (sequence[j] < root) {
      return false;
    }
  }

  bool left = true;
  if (i > 0) {
    IsPostorderSequenceOfBST(sequence, i);
  }

  bool right = true;
  if (i < length - 1) {
    IsPostorderSequenceOfBST(sequence + i, length - i - 1);
  }

  return left && right;
}

void FindPathCore(BinaryTreeNode *root, int expected_sum, std::vector<int> &path, int current_sum) {
  current_sum += root->value;
  path.push_back(root->value);

  bool is_leaf = root->left == nullptr && root->right == nullptr;
  if (current_sum == expected_sum && is_leaf) {
    std::cout << "A path is found: ";
    std::vector<int>::iterator it = path.begin();
    for (; it != path.end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  if (root->left != nullptr) {
    FindPathCore(root->left, expected_sum, path, current_sum);
  }
  if (root->right != nullptr) {
    FindPathCore(root->right, expected_sum, path, current_sum);
  }

  path.pop_back();
}

void FindPath(BinaryTreeNode *root, int expected_sum) {
  if (root == nullptr) {
    return;
  }

  std::vector<int> path;
  int current_sum = 0;
  FindPathCore(root, expected_sum, path, current_sum);
}

void TreeToListCore(BinaryTreeNode *node, BinaryTreeNode **last_node) {
  if (node == nullptr) {
    return;
  }

  BinaryTreeNode *current_node = node;

  if (current_node->left != nullptr) {
    TreeToListCore(current_node->left, last_node);
  }

  current_node->left = *last_node;
  if (*last_node != nullptr) {
    (*last_node)->right = current_node;
  }

  *last_node = current_node;

  if (current_node->right != nullptr) {
    TreeToListCore(current_node->right, last_node);
  }
}

BinaryTreeNode* TreeToList(BinaryTreeNode *root) {
  BinaryTreeNode *last_node = nullptr;

  TreeToListCore(root, &last_node);

  BinaryTreeNode *head = last_node;
  while (head != nullptr && head->left != nullptr) {
    head = head->left;
  }

  return head;
}

void WalkTreeAsList(BinaryTreeNode *head) {
  if (head == nullptr) {
    std::cout << "empty link list" << std::endl;
    return;
  }
  BinaryTreeNode *node = head;
  while (node != nullptr){
    std::cout << node->value << " ";
    node = node->right;
  }
  std::cout << std::endl;
}

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

void SerializeTree(BinaryTreeNode *root, std::ostringstream &os) {
  if (root == nullptr) {
    os << "$,";
    return;
  } else {
    os << root->value << ",";
  }
  SerializeTree(root->left, os);
  SerializeTree(root->right, os);
}

void DeserializeTree(BinaryTreeNode **root, std::istringstream &is) {
  int number;
  if (ReadStream(is, &number)) {
    *root = new BinaryTreeNode();
    (*root)->value = number;
    (*root)->left = nullptr;
    (*root)->right = nullptr;

    DeserializeTree(&((*root)->left), is);
    DeserializeTree(&((*root)->right), is);
  }
}

int TreeDepth(BinaryTreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int left = TreeDepth(root->left);
  int right = TreeDepth(root->right);
  return left > right ? left + 1 : right + 1;
}

bool TreeIsBalanceCore(BinaryTreeNode *root, int *depth) {
  if (root == nullptr) {
    *depth = 0;
    return true;
  }

  int left, right;
  if (TreeIsBalanceCore(root->left, &left)
      && TreeIsBalanceCore(root->right, &right)) {
    int diff = left - right;
    if (diff <= 1 && diff >= -1) {
      *depth = left > right ? left + 1 : right + 1;
      return true;
    }
  }

  return false;
}

bool TreeIsBalance(BinaryTreeNode *root) {
  int depth = 0;
  return TreeIsBalanceCore(root, &depth);
}

BinaryTreeNode* GetInorderWalkNext(BinaryTreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }

  BinaryTreeNode *next = nullptr;
  if (root->right != nullptr) {
    BinaryTreeNode *right = root->right;
    while (right->left != nullptr) {
      right = right->left;
    }
    next = right;
  } else if (root->parent != nullptr) {
    BinaryTreeNode *current = root;
    BinaryTreeNode *parent = root->parent;
    while (parent != nullptr && current == parent->right) {
      current = parent;
      parent = parent->parent;
    }
    next = parent;
  }

  return next;
}

bool IsTreeSymmetricalCore(BinaryTreeNode *root1, BinaryTreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  if (root1->value != root2->value) {
    return false;
  }
  return IsTreeSymmetricalCore(root1->left, root2->right)
    && IsTreeSymmetricalCore(root1->right, root2->left);
}

bool IsTreeSymmetrical(BinaryTreeNode *root) {
  return IsTreeSymmetricalCore(root, root);
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

void TestIsPostorderSequenceOfBST() {
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
  int sequence1[] = { 4, 8, 6, 12, 16, 14, 10 };
  std::cout << (IsPostorderSequenceOfBST(sequence1, sizeof(sequence1) / sizeof(int)) == true ? "Test1 Passed" : "Test1 Failed") << std::endl;

//           5
//          / \
//         4   7
//            /
//           6
  int sequence2[] = { 4, 6, 7, 5 };
  std::cout << (IsPostorderSequenceOfBST(sequence2, sizeof(sequence2) / sizeof(int)) == true ? "Test2 Passed" : "Test2 Failed") << std::endl;

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
  int sequence3[] = { 1, 2, 3, 4, 5 };
  std::cout << (IsPostorderSequenceOfBST(sequence3, sizeof(sequence3) / sizeof(int)) == true ? "Test3 Passed" : "Test3 Failed") << std::endl;

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
  int sequence4[] = { 5, 4, 3, 2, 1 };
  std::cout << (IsPostorderSequenceOfBST(sequence4, sizeof(sequence4) / sizeof(int)) == true ? "Test4 Passed" : "Test4 Failed") << std::endl;

  int sequence5[] = { 5 };
  std::cout << (IsPostorderSequenceOfBST(sequence5, sizeof(sequence5) / sizeof(int)) == true ? "Test5 Passed" : "Test5 Failed") << std::endl;

  int sequence6[] = { 7, 4, 6, 5 };
  std::cout << (IsPostorderSequenceOfBST(sequence6, sizeof(sequence6) / sizeof(int)) == false ? "Test6 Passed" : "Test6 Failed") << std::endl;

  int sequence7[] = { 4, 6, 12, 8, 16, 14, 10 };
  std::cout << (IsPostorderSequenceOfBST(sequence7, sizeof(sequence7) / sizeof(int)) == false ? "Test7 Passed" : "Test7 Failed") << std::endl;

  std::cout << (IsPostorderSequenceOfBST(nullptr, 0) == false ? "Test8 Passed" : "Test8 Failed") << std::endl;
}

void TestFindPath() {
//            10
//         /      \
//        5        12
//       /\
//      4  7
  BinaryTreeNode *node11 = new BinaryTreeNode(10);
  BinaryTreeNode *node12 = new BinaryTreeNode(5);
  BinaryTreeNode *node13 = new BinaryTreeNode(12);
  BinaryTreeNode *node14 = new BinaryTreeNode(4);
  BinaryTreeNode *node15 = new BinaryTreeNode(7);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  FindPath(node11, 22);
  FindPath(node11, 15);

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
  FindPath(node21, 15);

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
  FindPath(node31, 16);

  BinaryTreeNode *node41 = new BinaryTreeNode(1);
  FindPath(node41, 1);

  FindPath(nullptr, 0);
}

void TestTreeToList() {
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
  BinaryTreeNode *tree1 = nullptr;
  BinarySearchTreeInsert(&tree1, 10);
  BinarySearchTreeInsert(&tree1, 6);
  BinarySearchTreeInsert(&tree1, 14);
  BinarySearchTreeInsert(&tree1, 4);
  BinarySearchTreeInsert(&tree1, 8);
  BinarySearchTreeInsert(&tree1, 12);
  BinarySearchTreeInsert(&tree1, 16);
  BinaryTreeNode *list1 = TreeToList(tree1);
  WalkTreeAsList(list1);

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
  BinaryTreeNode *list2 = TreeToList(tree2);
  WalkTreeAsList(list2);

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
  BinaryTreeNode *list3 = TreeToList(tree3);
  WalkTreeAsList(list3);

  BinaryTreeNode *tree4 = new BinaryTreeNode(1);
  BinaryTreeNode *list4 = TreeToList(tree4);
  WalkTreeAsList(list4);

  BinaryTreeNode *list5 = TreeToList(nullptr);
  WalkTreeAsList(list5);
}

void TestSerializeTree() {
  std::ostringstream os;
  std::istringstream is;

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
  SerializeTree(tree1, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_tree1 = nullptr;
  DeserializeTree(&new_tree1, is);
  PreorderBinaryTreeWalk(new_tree1);
  std::cout << std::endl;

//            5
//          4
//        3
//      2
  BinaryTreeNode *node21 = new BinaryTreeNode(5);
  BinaryTreeNode *node22 = new BinaryTreeNode(4);
  BinaryTreeNode *node23 = new BinaryTreeNode(3);
  BinaryTreeNode *node24 = new BinaryTreeNode(2);
  node21->left = node22;
  node22->left = node23;
  node23->left = node24;
  os.str("");
  SerializeTree(node21, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_node21 = nullptr;
  DeserializeTree(&new_node21, is);
  PreorderBinaryTreeWalk(new_node21);
  std::cout << std::endl;

//        5
//         4
//          3
//           2
  BinaryTreeNode *node31 = new BinaryTreeNode(5);
  BinaryTreeNode *node32 = new BinaryTreeNode(4);
  BinaryTreeNode *node33 = new BinaryTreeNode(3);
  BinaryTreeNode *node34 = new BinaryTreeNode(2);
  node31->right = node32;
  node32->right = node33;
  node33->right = node34;
  os.str("");
  SerializeTree(node31, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_node31 = nullptr;
  DeserializeTree(&new_node31, is);
  PreorderBinaryTreeWalk(new_node31);
  std::cout << std::endl;

  BinaryTreeNode *node41 = new BinaryTreeNode(5);
  os.str("");
  SerializeTree(node41, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_node41 = nullptr;
  DeserializeTree(&new_node41, is);
  PreorderBinaryTreeWalk(new_node41);
  std::cout << std::endl;

  os.str("");
  SerializeTree(nullptr, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_node51 = nullptr;
  DeserializeTree(&new_node51, is);
  PreorderBinaryTreeWalk(new_node51);
  std::cout << std::endl;

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
  BinaryTreeNode *node61 = new BinaryTreeNode(5);
  BinaryTreeNode *node62 = new BinaryTreeNode(5);
  BinaryTreeNode *node63 = new BinaryTreeNode(5);
  BinaryTreeNode *node64 = new BinaryTreeNode(5);
  BinaryTreeNode *node65 = new BinaryTreeNode(5);
  BinaryTreeNode *node66 = new BinaryTreeNode(5);
  BinaryTreeNode *node67 = new BinaryTreeNode(5);
  BinaryTreeNode *node68 = new BinaryTreeNode(5);
  BinaryTreeNode *node69 = new BinaryTreeNode(5);
  node61->right = node62;
  node62->right = node63;
  node63->left = node64;
  node64->left = node65;
  node65->left = node66;
  node65->right = node67;
  node66->left = node68;
  node67->right = node69;
  os.str("");
  SerializeTree(node61, os);
  std::cout << os.str() << std::endl;
  is.str(os.str());
  BinaryTreeNode *new_node61 = nullptr;
  DeserializeTree(&new_node61, is);
  PreorderBinaryTreeWalk(new_node61);
  std::cout << std::endl;
}

void TestTreeDepth() {
//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
  BinaryTreeNode *node11 = new BinaryTreeNode(1);
  BinaryTreeNode *node12 = new BinaryTreeNode(2);
  BinaryTreeNode *node13 = new BinaryTreeNode(3);
  BinaryTreeNode *node14 = new BinaryTreeNode(4);
  BinaryTreeNode *node15 = new BinaryTreeNode(5);
  BinaryTreeNode *node16 = new BinaryTreeNode(6);
  BinaryTreeNode *node17 = new BinaryTreeNode(7);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  node13->right = node16;
  node15->left = node17;
  std::cout << TreeDepth(node11) << std::endl;

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
  BinaryTreeNode *node21 = new BinaryTreeNode(1);
  BinaryTreeNode *node22 = new BinaryTreeNode(2);
  BinaryTreeNode *node23 = new BinaryTreeNode(3);
  BinaryTreeNode *node24 = new BinaryTreeNode(4);
  BinaryTreeNode *node25 = new BinaryTreeNode(5);
  node21->left = node22;
  node22->left = node23;
  node23->left = node24;
  node24->left = node25;
  std::cout << TreeDepth(node21) << std::endl;

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
  std::cout << TreeDepth(node31) << std::endl;

  BinaryTreeNode *node41 = new BinaryTreeNode(1);
  std::cout << TreeDepth(node41) << std::endl;

  std::cout << TreeDepth(nullptr) << std::endl;
}

void TestTreeIsBalance() {
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
  BinaryTreeNode *node11 = new BinaryTreeNode(1);
  BinaryTreeNode *node12 = new BinaryTreeNode(2);
  BinaryTreeNode *node13 = new BinaryTreeNode(3);
  BinaryTreeNode *node14 = new BinaryTreeNode(4);
  BinaryTreeNode *node15 = new BinaryTreeNode(5);
  BinaryTreeNode *node16 = new BinaryTreeNode(6);
  BinaryTreeNode *node17 = new BinaryTreeNode(7);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = node15;
  node13->left = node16;
  node13->right = node17;
  std::cout << TreeIsBalance(node11) << std::endl;

//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
  BinaryTreeNode *node21 = new BinaryTreeNode(1);
  BinaryTreeNode *node22 = new BinaryTreeNode(2);
  BinaryTreeNode *node23 = new BinaryTreeNode(3);
  BinaryTreeNode *node24 = new BinaryTreeNode(4);
  BinaryTreeNode *node25 = new BinaryTreeNode(5);
  BinaryTreeNode *node26 = new BinaryTreeNode(6);
  BinaryTreeNode *node27 = new BinaryTreeNode(7);
  node21->left = node22;
  node21->right = node23;
  node22->left = node24;
  node22->right = node25;
  node23->right = node26;
  node25->left = node27;
  std::cout << TreeIsBalance(node21) << std::endl;

//             1
//         /      \
//        2        3
//       /\
//      4  5
//        /
//       6
  BinaryTreeNode *node31 = new BinaryTreeNode(1);
  BinaryTreeNode *node32 = new BinaryTreeNode(2);
  BinaryTreeNode *node33 = new BinaryTreeNode(3);
  BinaryTreeNode *node34 = new BinaryTreeNode(4);
  BinaryTreeNode *node35 = new BinaryTreeNode(5);
  BinaryTreeNode *node36 = new BinaryTreeNode(6);
  node31->left = node32;
  node31->right = node33;
  node32->left = node34;
  node32->right = node35;
  node35->left = node36;
  std::cout << TreeIsBalance(node31) << std::endl;

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
  BinaryTreeNode *node41 = new BinaryTreeNode(1);
  BinaryTreeNode *node42 = new BinaryTreeNode(2);
  BinaryTreeNode *node43 = new BinaryTreeNode(3);
  BinaryTreeNode *node44 = new BinaryTreeNode(4);
  BinaryTreeNode *node45 = new BinaryTreeNode(5);
  node41->left = node42;
  node42->left = node43;
  node43->left = node44;
  node44->left = node45;
  std::cout << TreeIsBalance(node41) << std::endl;

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
  BinaryTreeNode *node51 = new BinaryTreeNode(1);
  BinaryTreeNode *node52 = new BinaryTreeNode(2);
  BinaryTreeNode *node53 = new BinaryTreeNode(3);
  BinaryTreeNode *node54 = new BinaryTreeNode(4);
  BinaryTreeNode *node55 = new BinaryTreeNode(5);
  node51->right = node52;
  node52->right = node53;
  node53->right = node54;
  node54->right = node55;
  std::cout << TreeIsBalance(node51) << std::endl;

  BinaryTreeNode *node61 = new BinaryTreeNode(1);
  std::cout << TreeIsBalance(node61) << std::endl;

  std::cout << TreeIsBalance(nullptr) << std::endl;
}

void ConnectTreeNodes(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right) {
  if(parent != nullptr) {
    parent->left = left;
    parent->right = right;

    if(left != nullptr)
      left->parent = parent;
    if(right != nullptr)
      right->parent = parent;
  }
}

void TestGetInorderWalkNext() {
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
  ConnectTreeNodes(node11, node12, node13);
  ConnectTreeNodes(node12, node14, node15);
  ConnectTreeNodes(node13, node16, node17);
  std::cout << node11->value << " -> " << GetInorderWalkNext(node11)->value << std::endl;
  std::cout << node12->value << " -> " << GetInorderWalkNext(node12)->value << std::endl;
  std::cout << node13->value << " -> " << GetInorderWalkNext(node13)->value << std::endl;
  std::cout << node14->value << " -> " << GetInorderWalkNext(node14)->value << std::endl;
  std::cout << node15->value << " -> " << GetInorderWalkNext(node15)->value << std::endl;
  std::cout << node16->value << " -> " << GetInorderWalkNext(node16)->value << std::endl;
  std::cout << node17->value << " -> " << (GetInorderWalkNext(node17) == nullptr ? "null" : "error") << std::endl;
  std::cout << std::endl;

//            5
//          4
//        3
//      2
  BinaryTreeNode *node21 = new BinaryTreeNode(5);
  BinaryTreeNode *node22 = new BinaryTreeNode(4);
  BinaryTreeNode *node23 = new BinaryTreeNode(3);
  BinaryTreeNode *node24 = new BinaryTreeNode(2);
  ConnectTreeNodes(node21, node22, nullptr);
  ConnectTreeNodes(node22, node23, nullptr);
  ConnectTreeNodes(node23, node24, nullptr);
  std::cout << node21->value << " -> " << (GetInorderWalkNext(node21) == nullptr ? "null" : "error") << std::endl;
  std::cout << node22->value << " -> " << GetInorderWalkNext(node22)->value << std::endl;
  std::cout << node23->value << " -> " << GetInorderWalkNext(node23)->value << std::endl;
  std::cout << node24->value << " -> " << GetInorderWalkNext(node24)->value << std::endl;
  std::cout << std::endl;

//        2
//         3
//          4
//           5
  BinaryTreeNode *node31 = new BinaryTreeNode(2);
  BinaryTreeNode *node32 = new BinaryTreeNode(3);
  BinaryTreeNode *node33 = new BinaryTreeNode(4);
  BinaryTreeNode *node34 = new BinaryTreeNode(5);
  ConnectTreeNodes(node31, nullptr, node32);
  ConnectTreeNodes(node32, nullptr, node33);
  ConnectTreeNodes(node33, nullptr, node34);
  std::cout << node31->value << " -> " << GetInorderWalkNext(node31)->value << std::endl;
  std::cout << node32->value << " -> " << GetInorderWalkNext(node32)->value << std::endl;
  std::cout << node33->value << " -> " << GetInorderWalkNext(node33)->value << std::endl;
  std::cout << node34->value << " -> " << (GetInorderWalkNext(node34) == nullptr ? "null" : "error") << std::endl;
  std::cout << std::endl;

  BinaryTreeNode *node41 = new BinaryTreeNode(5);
  std::cout << node41->value << " -> " << (GetInorderWalkNext(node41) == nullptr ? "null" : "error") << std::endl;
}

void TestIsTreeSymmetrical() {
//            8
//        6      6
//       5 7    7 5
  BinaryTreeNode *node11 = new BinaryTreeNode(8);
  BinaryTreeNode *node12 = new BinaryTreeNode(6);
  BinaryTreeNode *node13 = new BinaryTreeNode(6);
  BinaryTreeNode *node14 = new BinaryTreeNode(5);
  BinaryTreeNode *node15 = new BinaryTreeNode(7);
  BinaryTreeNode *node16 = new BinaryTreeNode(7);
  BinaryTreeNode *node17 = new BinaryTreeNode(5);
  ConnectTreeNodes(node11, node12, node13);
  ConnectTreeNodes(node12, node14, node15);
  ConnectTreeNodes(node13, node16, node17);
  std::cout << IsTreeSymmetrical(node11) << std::endl;

//            8
//        6      9
//       5 7    7 5
  BinaryTreeNode *node21 = new BinaryTreeNode(8);
  BinaryTreeNode *node22 = new BinaryTreeNode(6);
  BinaryTreeNode *node23 = new BinaryTreeNode(9);
  BinaryTreeNode *node24 = new BinaryTreeNode(5);
  BinaryTreeNode *node25 = new BinaryTreeNode(7);
  BinaryTreeNode *node26 = new BinaryTreeNode(7);
  BinaryTreeNode *node27 = new BinaryTreeNode(5);
  ConnectTreeNodes(node21, node22, node23);
  ConnectTreeNodes(node22, node24, node25);
  ConnectTreeNodes(node23, node26, node27);
  std::cout << IsTreeSymmetrical(node21) << std::endl;

//            8
//        6      6
//       5 7    7
  BinaryTreeNode *node31 = new BinaryTreeNode(8);
  BinaryTreeNode *node32 = new BinaryTreeNode(6);
  BinaryTreeNode *node33 = new BinaryTreeNode(6);
  BinaryTreeNode *node34 = new BinaryTreeNode(5);
  BinaryTreeNode *node35 = new BinaryTreeNode(7);
  BinaryTreeNode *node36 = new BinaryTreeNode(7);
  ConnectTreeNodes(node31, node32, node33);
  ConnectTreeNodes(node32, node34, node35);
  ConnectTreeNodes(node33, node36, nullptr);
  std::cout << IsTreeSymmetrical(node31) << std::endl;

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
  BinaryTreeNode *node41 = new BinaryTreeNode(5);
  BinaryTreeNode *node42 = new BinaryTreeNode(3);
  BinaryTreeNode *node43 = new BinaryTreeNode(3);
  BinaryTreeNode *node44 = new BinaryTreeNode(4);
  BinaryTreeNode *node45 = new BinaryTreeNode(4);
  BinaryTreeNode *node46 = new BinaryTreeNode(2);
  BinaryTreeNode *node47 = new BinaryTreeNode(2);
  BinaryTreeNode *node48 = new BinaryTreeNode(1);
  BinaryTreeNode *node49 = new BinaryTreeNode(1);
  ConnectTreeNodes(node41, node42, node43);
  ConnectTreeNodes(node42, node44, nullptr);
  ConnectTreeNodes(node43, nullptr, node45);
  ConnectTreeNodes(node44, node46, nullptr);
  ConnectTreeNodes(node45, nullptr, node47);
  ConnectTreeNodes(node46, node48, nullptr);
  ConnectTreeNodes(node47, nullptr, node49);
  std::cout << IsTreeSymmetrical(node41) << std::endl;

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
  BinaryTreeNode *node51 = new BinaryTreeNode(5);
  BinaryTreeNode *node52 = new BinaryTreeNode(3);
  BinaryTreeNode *node53 = new BinaryTreeNode(3);
  BinaryTreeNode *node54 = new BinaryTreeNode(4);
  BinaryTreeNode *node55 = new BinaryTreeNode(4);
  BinaryTreeNode *node56 = new BinaryTreeNode(6);
  BinaryTreeNode *node57 = new BinaryTreeNode(2);
  BinaryTreeNode *node58 = new BinaryTreeNode(1);
  BinaryTreeNode *node59 = new BinaryTreeNode(1);
  ConnectTreeNodes(node51, node52, node53);
  ConnectTreeNodes(node52, node54, nullptr);
  ConnectTreeNodes(node53, nullptr, node55);
  ConnectTreeNodes(node54, node56, nullptr);
  ConnectTreeNodes(node55, nullptr, node57);
  ConnectTreeNodes(node56, node58, nullptr);
  ConnectTreeNodes(node57, nullptr, node59);
  std::cout << IsTreeSymmetrical(node51) << std::endl;

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
  BinaryTreeNode *node61 = new BinaryTreeNode(5);
  BinaryTreeNode *node62 = new BinaryTreeNode(3);
  BinaryTreeNode *node63 = new BinaryTreeNode(3);
  BinaryTreeNode *node64 = new BinaryTreeNode(4);
  BinaryTreeNode *node65 = new BinaryTreeNode(4);
  BinaryTreeNode *node66 = new BinaryTreeNode(2);
  BinaryTreeNode *node67 = new BinaryTreeNode(2);
  BinaryTreeNode *node68 = new BinaryTreeNode(1);
  ConnectTreeNodes(node61, node62, node63);
  ConnectTreeNodes(node62, node64, nullptr);
  ConnectTreeNodes(node63, nullptr, node65);
  ConnectTreeNodes(node64, node66, nullptr);
  ConnectTreeNodes(node65, nullptr, node67);
  ConnectTreeNodes(node67, nullptr, node68);
  std::cout << IsTreeSymmetrical(node61) << std::endl;

  BinaryTreeNode *node71 = new BinaryTreeNode(1);
  std::cout << IsTreeSymmetrical(node71) << std::endl;

  std::cout << IsTreeSymmetrical(nullptr) << std::endl;

//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
  BinaryTreeNode *node81 = new BinaryTreeNode(5);
  BinaryTreeNode *node82 = new BinaryTreeNode(5);
  BinaryTreeNode *node83 = new BinaryTreeNode(5);
  BinaryTreeNode *node84 = new BinaryTreeNode(5);
  BinaryTreeNode *node85 = new BinaryTreeNode(5);
  BinaryTreeNode *node86 = new BinaryTreeNode(5);
  BinaryTreeNode *node87 = new BinaryTreeNode(5);
  ConnectTreeNodes(node81, node82, node83);
  ConnectTreeNodes(node82, node84, nullptr);
  ConnectTreeNodes(node83, nullptr, node85);
  ConnectTreeNodes(node84, node86, nullptr);
  ConnectTreeNodes(node85, nullptr, node87);
  std::cout << IsTreeSymmetrical(node81) << std::endl;

//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
  BinaryTreeNode *node91 = new BinaryTreeNode(5);
  BinaryTreeNode *node92 = new BinaryTreeNode(5);
  BinaryTreeNode *node93 = new BinaryTreeNode(5);
  BinaryTreeNode *node94 = new BinaryTreeNode(5);
  BinaryTreeNode *node95 = new BinaryTreeNode(5);
  BinaryTreeNode *node96 = new BinaryTreeNode(5);
  BinaryTreeNode *node97 = new BinaryTreeNode(5);
  ConnectTreeNodes(node91, node92, node93);
  ConnectTreeNodes(node92, node94, nullptr);
  ConnectTreeNodes(node93, nullptr, node95);
  ConnectTreeNodes(node94, node96, nullptr);
  ConnectTreeNodes(node95, node97, nullptr);
  std::cout << IsTreeSymmetrical(node91) << std::endl;
}