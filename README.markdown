## 链表
> 首先，考虑链表为空和只有一个节点的情况；<br>
> 需要查询时，考虑多个不同位置的指针；<br>
> 需要增删改时，考虑被操作的节点在头部、中间和尾部的情况；<br>
- [从尾到头打印链表](data_structure_linklist.cpp#L71)
- [在 O(1) 时间内删除链表节点](data_structure_linklist.cpp#L135)
- [在一个排序的链表中删除重复节点](data_structure_linklist.cpp#L164)
- [从链表中找出倒数第 k 个节点，如 1、2、3、4、5、6，倒数第 3 个节点是 4](data_structure_linklist.cpp#L195)
- [从链表中找出中间的节点](data_structure_linklist.cpp#L96)
- [从链表中找出环的入口节点](data_structure_linklist.cpp#L214)
- [反转链表](data_structure_linklist.cpp#L254)
- [合并两个排序的链表](data_structure_linklist.cpp#L272)
- [两个有序（从小到大）单链表，构造一条新链表，包含同时出现在两个链表的节点](data_structure_linklist.cpp#L108)
- [两个链表的第一个公共节点](data_structure_linklist.cpp#L299)

## 🌲 二叉树 Binary Tree

### 定义

#### 树的路径

从树的根节点开始往下一直到叶节点所经过的节点形成一条路径

#### 树的深度

最长路径的长度为树的深度

#### 二叉树

在二叉树中每个节点最多只能有两个节点

#### 二叉搜索树 Binary Search Tree (BST)

左子节点总是小于或等于根节点，而右子节点总是大于或等于根节点，平均在 O(logn) 的时间内根据数值在 BST 中找到一个节点。

### 测试用例

- [完全二叉树](Google_tests/CompleteBinaryTreeTest.cpp)，[完全二叉搜索树](Google_tests/CompleteBSTTest.cpp)
- [非完全二叉树](Google_tests/NonCompleteBinaryTreeTest.cpp)，[非完全二叉搜索树](Google_tests/NonCompleteBSTTest.cpp)
- [只有左节点的二叉树](Google_tests/OnlyLeftNodeBinaryTreeTest.cpp)，[只有左节点的二叉搜索树](Google_tests/OnlyLeftNodeBSTTest.cpp)
- [只有右节点的二叉树](Google_tests/OnlyRightNodeBinaryTreeTest.cpp)，[只有右节点的二叉搜索树](Google_tests/OnlyRightNodeBSTTest.cpp)
- [只有一个节点的二叉树](Google_tests/OneNodeBinaryTreeTest.cpp)
- [空的二叉树](Google_tests/EmptyBinaryTreeTest.cpp)

### 三种基本遍历

掌握前序遍历、中序遍历、后序遍历，命名的方式是操作子树根节点相对于遍历其左右子树的顺序。

- [前序遍历](BinaryTree/binary_tree.cpp)
- [中序遍历](BinaryTree/binary_tree.cpp)
- [后序遍历](BinaryTree/binary_tree.cpp)

### 前序遍历结果的特点

第一个数字是树的根节点的值，后面的数字可以分为两部分，第一部分是左子树节点的值，如果是 BST，它们都比根节点的值小，
第一部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

- [输入二叉树的前序遍历和中序遍历的结果，结果中不含重复数字，重建此二叉树](BinaryTree/construct_binary_tree_with_preorder_inorder_walk_result.cpp)
- [输入两棵二叉树 A 和 B，判断 B 是不是 A 的子结构](BinaryTree/binary_tree_contain_sub_tree.cpp)
- [二叉树的镜像](BinaryTree/mirror_binary_tree.cpp)
- [对称的二叉树](BinaryTree/binary_tree_is_symmetrical.cpp)
- [序列化和反序列化二叉树](BinaryTree/serialize_binary_tree.cpp)

### 中序遍历结果的特点

根节点的值在中间，剩下的数字可以分为前后两部分，前面部分是左子树节点的值，如果是 BST，它们都比根节点的值小，后面部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

- [查找二叉搜索树的第 k 大节点](BinaryTree/find_kth_node_in_bst.cpp)
- [输入一个棵二叉搜索树，将其转换成一个排序的双向链表，不能创建任何新的节点，只能调整树中节点指针的指向](BinaryTree/bst_to_link_list.cpp)
- [找出二叉树中一个节点的中序遍历序列的下一个节点，树中的节点还有一个指向父节点的指针](BinaryTree/get_binary_tree_inorder_walk_next.cpp)

### 后序遍历结果的特点

最后一个数字是数的根节点的值，前面的数字可以分为两部分，第一部分是左子树节点的值，如果是 BST，它们都比根节点的值小，
第一部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

- [输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果](BinaryTree/is_postorder_sequence_of_bst.cpp)
- [二叉树的深度](BinaryTree/binary_tree_depth.cpp)
- [平衡二叉树，任意节点的左、右子树的深度相差不超过 1](BinaryTree/binary_tree_is_balance.cpp)

### 利用队列或栈作为树的辅助

- [从上到下打印二叉树](BinaryTree/top_to_bottom_binary_tree_walk.cpp)
- [分行从上到下打印二叉树](BinaryTree/top_to_bottom_binary_tree_walk.cpp)
- [之字形从上到下打印二叉树](BinaryTree/top_to_bottom_binary_tree_walk.cpp)
- [输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径](BinaryTree/find_summary_path_in_binary_tree.cpp)

### 树中两个节点的最低公共祖先

- 二叉搜索树：从树的根节点开始和两个输入的节点进行比较，如果当前节点的值比两个节点的值都大，那么最低的共同父节点一定在当前节点的左子树中，于是下一步遍历当前节点的左子节点，如果当前节点的值比两个节点的值都小，那么最低的共同父节点一定在当前节点的右子树中，于是下一步遍历当前节点的右子节点，这样，在树中从上到下找到的第一个在两个输入节点的值之间的节点就是最低的公共祖先。
- 节点带有父节点的树：从树的每个叶节点开始都有一个由指针 parent 串起来的链表，这些链表的尾指针都是树的根节点，两个节点位于两个链表上，它们的最低公共祖先刚好就是这两个链表的一个公共节点。
- [普通树：用两个链表分别保存从根节点到输入的两个节点的路径，把问题转换成两个链表的最后公共节点。](Tree/get_tree_last_common_parent.cpp)

## 排序
- [冒泡排序](sort.cpp#L23)
- [插入排序](sort.cpp#L50)
- [快速排序](sort.cpp#L87)
- [归并排序](sort.cpp#L138)

## 字符串
- [字符串转数字: 10 进制](data_structure_string.cpp#L52)
- [字符串转数字: 26 进制的大写字母](data_structure_string.cpp#L57)
- [翻转字符串，翻转单词，左旋转字符串](data_structure_string.cpp#L62)

## 时间效率
- [整数数组中查找最长递增序列](time_efficiency.cpp#L13)
