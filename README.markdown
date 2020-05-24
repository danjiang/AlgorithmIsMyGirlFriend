## 数据结构

### 字符串
- [字符串转数字: 10 进制](data_structure_string.cpp#L52)
- [字符串转数字: 26 进制的大写字母](data_structure_string.cpp#L57)
- [翻转字符串，翻转单词，左旋转字符串](data_structure_string.cpp#L62)

### 链表
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

### 二叉树

#### 三种遍历

掌握前序遍历、中序遍历、后序遍历，命名的方式是操作子树根节点相对于遍历其左右子树的顺序。

前序遍历结果的特点：第一个数字是树的根节点的值，后面的数字可以分为两部分，
第一部分是左子树节点的值，如果是 BST，它们都比根节点的值小，
第一部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

中序遍历结果的特点：根节点的值在中间，剩下的数字可以分为前后两部分，
前面部分是左子树节点的值，如果是 BST，它们都比根节点的值小，
后面部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

后序遍历结果的特点：最后一个数字是数的根节点的值，前面的数字可以分为两部分，
第一部分是左子树节点的值，如果是 BST，它们都比根节点的值小，
第一部分是右子树节点的值，如果是 BST，它们都比根节点的值大。

利用队列或栈作为树的辅助。

- [查找二叉搜索树的第 k 大节点](data_structure_tree.cpp#L93)
- [输入二叉树的前序遍历和中序遍历的结果，结果中不含重复数字，重建此二叉树](data_structure_tree.cpp#L142)
- [输入两棵二叉树 A 和 B，判断 B 是不是 A 的子结构](data_structure_tree.cpp#L165)
- [二叉树的镜像](data_structure_tree.cpp#L183)
- [从上到下打印二叉树](data_structure_tree.cpp#L203)
- [分行从上到下打印二叉树](data_structure_tree.cpp#L227)
- [之字形从上到下打印二叉树](data_structure_tree.cpp#L263)

## 数据操作

### 排序
- [冒泡排序](sort.cpp#L23)
- [插入排序](sort.cpp#L50)
- [快速排序](sort.cpp#L87)
- [归并排序](sort.cpp#L138)

## 优化时间和空间效率

### 时间效率
- [整数数组中查找最长递增序列](time_efficiency.cpp#L13)
