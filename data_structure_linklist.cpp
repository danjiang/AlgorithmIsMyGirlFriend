//
// Created by Dan Jiang on 2020/4/26.
//

#include "data_structure_linklist.h"
#include <iostream>
#include <stack>

struct ListNode {
  int value;
  ListNode *next;
};

ListNode* AppendNode(ListNode **head, int value) {
  ListNode *new_node = new ListNode();
  new_node->value = value;
  new_node->next = nullptr;

  if (head == nullptr || *head == nullptr) {
    *head = new_node;
  } else {
    ListNode *node = *head;
    while (node->next != nullptr) {
      node = node->next;
    }
    node->next = new_node;
  }
  return new_node;
}

void RemoveNode(ListNode **head, int value) {
  if (head == nullptr || *head == nullptr) {
    return;
  }

  ListNode *deleted_node = nullptr;
  if ((*head)->value == value) {
    deleted_node = *head;
    *head = (*head)->next;
  } else {
    ListNode *node = *head;
    ListNode *next_node = (*head)->next;
    while (next_node != nullptr) {
      if (next_node->value == value) {
        deleted_node = next_node;
        node->next = next_node->next;
        break;
      }
      node = node->next;
      next_node = next_node->next;
    }
  }
  if (deleted_node != nullptr) {
    delete deleted_node;
    deleted_node = nullptr;
  }
}

void PrintLinkList(ListNode *head) {
  if (head == nullptr) {
    std::cout << "empty link list" << std::endl;
    return;
  }
  ListNode *node = head;
  while (node != nullptr){
    std::cout << node->value << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

void PrintListReverseIteratively(ListNode *head) {
  std::stack<ListNode*> nodes;
  ListNode *node = head;
  while (node != nullptr) {
    nodes.push(node);
    node = node->next;
  }
  while (!nodes.empty()) {
    node = nodes.top();
    std::cout << node->value << " ";
    nodes.pop();
  }
  std::cout << std::endl;
}

void PrintListReverseRecursively(ListNode *head) {
  if (head != nullptr) {
    if (head->next != nullptr) {
      PrintListReverseRecursively(head->next);
    }
  }
  std::cout << head->value << " ";
}

ListNode* FindMiddleNode(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast != nullptr &&
      fast->next != nullptr &&
      fast->next->next != nullptr) {
    fast = fast->next->next; // two steps
    slow = slow->next; // one step
  }
  return slow;
}

ListNode* IntersectTwoSortedList(ListNode *first_head, ListNode *second_head) {
  ListNode *head = nullptr;
  ListNode *node = nullptr;
  ListNode *first_node = first_head;
  ListNode *second_node = second_head;
  while (first_node != nullptr && second_node != nullptr) {
    if (first_node->value == second_node->value) {
      ListNode *new_node = new ListNode();
      new_node->value = first_node->value;
      if (node == nullptr) {
        node = new_node;
        head = node;
      } else {
        node->next = new_node;
        node = node->next;
      }
      first_node = first_node->next;
      second_node = second_node->next;
    } else if (first_node->value > second_node->value) {
      second_node = second_node->next;
    } else {
      first_node = first_node->next;
    }
  }
  return head;
}

void DeleteNode(ListNode **head, ListNode *deleted_node) {
  if (head == nullptr || *head == nullptr || deleted_node == nullptr) {
    return;
  }

  if (deleted_node->next != nullptr) { // not last node
    ListNode *next_node = deleted_node->next;
    deleted_node->value = next_node->value;
    deleted_node->next = next_node->next;

    delete next_node;
    next_node = nullptr;
  } else if ((*head)->next == nullptr) { // only one node
    *head = nullptr;

    delete deleted_node;
    deleted_node = nullptr;
  } else { // last node
    ListNode *node = *head;
    while (node->next->next != nullptr) {
      node = node->next;
    }
    node->next = nullptr;

    delete deleted_node;
    deleted_node = nullptr;
  }
}

void DeleteDuplication(ListNode **head) {
  if (head == nullptr || *head == nullptr) {
    return;
  }

  ListNode *prev_node = nullptr;
  ListNode *node = *head;
  while (node != nullptr) {
    ListNode *next_node = node->next;
    bool need_delete = false;
    while (next_node != nullptr && node->value == next_node->value) {
      delete next_node;

      next_node = next_node->next;
      need_delete = true;
    }
    if (need_delete) {
      delete node;

      if (prev_node == nullptr) {
        *head = next_node;
      } else {
        prev_node->next = next_node;
      }
    } else {
      prev_node = node;
    }
    node = next_node;
  }
}

ListNode* FindKthToTail(ListNode *head, int k) {
 if (head == nullptr || k <= 0) {
   return nullptr;
 }
 ListNode *k_node = nullptr;
 ListNode *node = head;
 int index = 1;
 while (node != nullptr) {
   if (index == k) {
     k_node = head;
   } else if (k_node != nullptr) {
     k_node = k_node->next;
   }
   index++;
   node = node->next;
 }
 return k_node;
}

ListNode* EntryNodeOfLoop(ListNode *head) {
  ListNode *fast_node = head;
  ListNode *slow_node = head;

  bool have_loop = false; // detect loop, next node of last node is in link list
  while (fast_node != nullptr
      && fast_node->next != nullptr
      && fast_node->next->next != nullptr) {
    fast_node = fast_node->next->next;
    slow_node = slow_node->next;
    if (fast_node == slow_node) {
      have_loop = true;
      break;
    }
  }

  if (have_loop) {
    ListNode *node = fast_node->next; // fast node must in loop
    int nodes_in_loop = 1; // find number of nodes in loop
    while (fast_node != node) {
      nodes_in_loop++;
      node = node->next;
    }

    slow_node = head;
    fast_node = head;
    for (int i = 0; i < nodes_in_loop; ++i) { // fast node go first
      fast_node = fast_node->next;
    }
    while (slow_node != fast_node) { // slow node and fast node both go
      slow_node = slow_node->next;
      fast_node = fast_node->next;
    }

    return fast_node;
  } else {
    return nullptr;
  }
}

ListNode* ReverseList(ListNode *head) {
  ListNode *reverse_head = nullptr;
  ListNode *node = head;
  ListNode *prev_node = nullptr;
  while (node != nullptr) {
    ListNode *next_node = node->next;
    if (next_node == nullptr) {
      reverse_head = node;
    }

    node->next = prev_node;
    prev_node = node;
    node = next_node;
  }

  return reverse_head;
}

ListNode* MergeList(ListNode *first_head, ListNode *second_head) {
  ListNode *head = nullptr;
  if (first_head == nullptr) {
    return second_head;
  } else if (second_head == nullptr) {
    return first_head;
  }
  if (first_head->value < second_head->value) {
    head = first_head;
    head->next = MergeList(first_head->next, second_head);
  } else {
    head = second_head;
    head->next = MergeList(first_head, second_head->next);
  }
  return head;
}

int LengthOfList(ListNode *head) {
  int length = 0;
  ListNode *node = head;
  while (node != nullptr) {
    node = node->next;
    length++;
  }
  return length;
}

ListNode* FindFirstCommonNode(ListNode *first_head, ListNode *second_head) {
  int length1 = LengthOfList(first_head);
  int length2 = LengthOfList(second_head);
  ListNode *first_node = first_head;
  ListNode *second_node = second_head;
  if (length1 > length2) {
    int distance = length1 - length2;
    for (int i = 0; i < distance; ++i) {
      first_node = first_node->next;
    }
  } else {
    int distance = length2 - length1;
    for (int i = 0; i < distance; ++i) {
      second_node = second_node->next;
    }
  }
  while (first_node != nullptr && second_node != nullptr) {
    if (first_node == second_node) {
      return first_node;
    }
    first_node = first_node->next;
    second_node = second_node->next;
  }
  return nullptr;
}

void TestListNode() {
  ListNode *head = nullptr;
  AppendNode(&head, 5);
  AppendNode(&head, 6);
  AppendNode(&head, 7);
  PrintLinkList(head);

  RemoveNode(&head, 6);
  PrintLinkList(head);
  RemoveNode(&head, 5);
  PrintLinkList(head);
  RemoveNode(&head, 3);
  PrintLinkList(head);
  RemoveNode(&head, 7);
  PrintLinkList(head);
}

void TestPrintListReverse() {
  ListNode *head = nullptr;
  AppendNode(&head, 5);
  AppendNode(&head, 6);
  AppendNode(&head, 7);
  PrintListReverseIteratively(head);
  PrintListReverseRecursively(head);
  printf("\n");
}

void TestFindMiddleNode() {
  ListNode *head = nullptr;
  AppendNode(&head, 5);
  AppendNode(&head, 6);
  AppendNode(&head, 7);
  PrintLinkList(head);
  ListNode *middle_node = FindMiddleNode(head);
  printf("middle = %d\n", middle_node->value);

  AppendNode(&head, 8);
  AppendNode(&head, 9);
  AppendNode(&head, 10);
  PrintLinkList(head);
  middle_node = FindMiddleNode(head);
  printf("middle = %d\n", middle_node->value);
}

void TestIntersectTwoSortedList() {
  ListNode *first_list = nullptr;
  AppendNode(&first_list, 1);
  AppendNode(&first_list, 2);
  AppendNode(&first_list, 8);
  AppendNode(&first_list, 10);
  AppendNode(&first_list, 12);
  PrintLinkList(first_list);

  ListNode *second_list = nullptr;
  AppendNode(&second_list, 2);
  AppendNode(&second_list, 3);
  AppendNode(&second_list, 8);
  AppendNode(&second_list, 10);
  AppendNode(&second_list, 14);
  AppendNode(&second_list, 16);
  PrintLinkList(second_list);

  ListNode *intersect_list = IntersectTwoSortedList(second_list, first_list);
  PrintLinkList(intersect_list);
}

void TestDeleteNode() {
  ListNode *list1 = nullptr;
  AppendNode(&list1, 5);
  ListNode *deleted_node = AppendNode(&list1, 6);
  AppendNode(&list1, 7);
  PrintLinkList(list1);
  DeleteNode(&list1, deleted_node);
  PrintLinkList(list1);

  ListNode *list2 = nullptr;
  AppendNode(&list2, 5);
  AppendNode(&list2, 6);
  deleted_node = AppendNode(&list2, 7);
  PrintLinkList(list2);
  DeleteNode(&list2, deleted_node);
  PrintLinkList(list2);

  ListNode *list3 = nullptr;
  deleted_node = AppendNode(&list3, 5);
  AppendNode(&list3, 6);
  AppendNode(&list3, 7);
  PrintLinkList(list3);
  DeleteNode(&list3, deleted_node);
  PrintLinkList(list3);

  ListNode *list4 = nullptr;
  deleted_node = AppendNode(&list4, 5);
  PrintLinkList(list4);
  DeleteNode(&list4, deleted_node);
  PrintLinkList(list4);

  DeleteNode(nullptr, nullptr);
}

void TestDeleteDuplication() {
  ListNode *list1 = nullptr;
  AppendNode(&list1, 1);
  AppendNode(&list1, 2);
  AppendNode(&list1, 3);
  AppendNode(&list1, 3);
  AppendNode(&list1, 4);
  AppendNode(&list1, 4);
  AppendNode(&list1, 5);
  PrintLinkList(list1);
  DeleteDuplication(&list1);
  PrintLinkList(list1);

  ListNode *list2 = nullptr;
  AppendNode(&list2, 1);
  AppendNode(&list2, 2);
  AppendNode(&list2, 3);
  AppendNode(&list2, 4);
  PrintLinkList(list2);
  DeleteDuplication(&list2);
  PrintLinkList(list2);

  ListNode *list3 = nullptr;
  AppendNode(&list3, 1);
  AppendNode(&list3, 1);
  AppendNode(&list3, 1);
  AppendNode(&list3, 2);
  PrintLinkList(list3);
  DeleteDuplication(&list3);
  PrintLinkList(list3);

  ListNode *list4 = nullptr;
  AppendNode(&list4, 1);
  AppendNode(&list4, 1);
  AppendNode(&list4, 1);
  AppendNode(&list4, 1);
  PrintLinkList(list4);
  DeleteDuplication(&list4);
  PrintLinkList(list4);

  ListNode *list5 = nullptr;
  AppendNode(&list5, 1);
  AppendNode(&list5, 1);
  AppendNode(&list5, 2);
  AppendNode(&list5, 2);
  AppendNode(&list5, 3);
  AppendNode(&list5, 3);
  PrintLinkList(list5);
  DeleteDuplication(&list5);
  PrintLinkList(list5);

  ListNode *list6 = nullptr;
  AppendNode(&list6, 1);
  AppendNode(&list6, 1);
  AppendNode(&list6, 2);
  AppendNode(&list6, 3);
  AppendNode(&list6, 3);
  AppendNode(&list6, 4);
  AppendNode(&list6, 5);
  AppendNode(&list6, 5);
  PrintLinkList(list6);
  DeleteDuplication(&list6);
  PrintLinkList(list6);

  ListNode *list7 = nullptr;
  AppendNode(&list7, 1);
  AppendNode(&list7, 2);
  PrintLinkList(list7);
  DeleteDuplication(&list7);
  PrintLinkList(list7);

  ListNode *list8 = nullptr;
  AppendNode(&list8, 1);
  PrintLinkList(list8);
  DeleteDuplication(&list8);
  PrintLinkList(list8);

  ListNode *list9 = nullptr;
  AppendNode(&list9, 1);
  AppendNode(&list9, 1);
  PrintLinkList(list9);
  DeleteDuplication(&list9);
  PrintLinkList(list9);

  DeleteDuplication(nullptr);
}

void TestFindKthToTail() {
  ListNode *list1 = nullptr;
  AppendNode(&list1, 1);
  AppendNode(&list1, 2);
  AppendNode(&list1, 3);
  AppendNode(&list1, 4);
  AppendNode(&list1, 5);
  PrintLinkList(list1);
  if (FindKthToTail(list1, 2)->value == 4) {
    std::cout << "Test1 Pass" << std::endl;
  } else {
    std::cout << "Test1 Fail" << std::endl;
  }
  if (FindKthToTail(list1, 1)->value == 5) {
    std::cout << "Test2 Pass" << std::endl;
  } else {
    std::cout << "Test2 Fail" << std::endl;
  }
  if (FindKthToTail(list1, 5)->value == 1) {
    std::cout << "Test3 Pass" << std::endl;
  } else {
    std::cout << "Test3 Fail" << std::endl;
  }
  if (FindKthToTail(list1, 6) == nullptr) {
    std::cout << "Test4 Pass" << std::endl;
  } else {
    std::cout << "Test4 Fail" << std::endl;
  }
  if (FindKthToTail(list1, 0) == nullptr) {
    std::cout << "Test5 Pass" << std::endl;
  } else {
    std::cout << "Test5 Fail" << std::endl;
  }
  if (FindKthToTail(nullptr, 100) == nullptr) {
    std::cout << "Test6 Pass" << std::endl;
  } else {
    std::cout << "Test6 Fail" << std::endl;
  }
}

void TestEntryNodeOfLoop() {
  ListNode *list1 = nullptr;
  AppendNode(&list1, 1);
  if (EntryNodeOfLoop(list1) == nullptr) {
    std::cout << "Test1 Pass" << std::endl;
  } else {
    std::cout << "Test1 Fail" << std::endl;
  }

  ListNode *list2 = nullptr;
  ListNode *entry_node = AppendNode(&list2, 1);
  ListNode *last_node = AppendNode(&list2, 2);
  last_node->next = entry_node;
  if (EntryNodeOfLoop(list2)->value == entry_node->value) {
    std::cout << "Test2 Pass" << std::endl;
  } else {
    std::cout << "Test2 Fail" << std::endl;
  }

  ListNode *list3 = nullptr;
  AppendNode(&list3, 1);
  AppendNode(&list3, 2);
  entry_node = AppendNode(&list3, 3);
  AppendNode(&list3, 4);
  last_node = AppendNode(&list3, 5);
  last_node->next = entry_node;
  if (EntryNodeOfLoop(list3)->value == entry_node->value) {
    std::cout << "Test3 Pass" << std::endl;
  } else {
    std::cout << "Test3 Fail" << std::endl;
  }

  ListNode *list4 = nullptr;
  entry_node = AppendNode(&list4, 1);
  AppendNode(&list4, 2);
  AppendNode(&list4, 3);
  AppendNode(&list4, 4);
  last_node = AppendNode(&list4, 5);
  last_node->next = entry_node;
  if (EntryNodeOfLoop(list4)->value == entry_node->value) {
    std::cout << "Test4 Pass" << std::endl;
  } else {
    std::cout << "Test4 Fail" << std::endl;
  }

  ListNode *list5 = nullptr;
  AppendNode(&list5, 1);
  AppendNode(&list5, 2);
  AppendNode(&list5, 3);
  AppendNode(&list5, 4);
  last_node = AppendNode(&list5, 5);
  entry_node = last_node;
  last_node->next = entry_node;
  if (EntryNodeOfLoop(list5)->value == entry_node->value) {
    std::cout << "Test5 Pass" << std::endl;
  } else {
    std::cout << "Test5 Fail" << std::endl;
  }

  ListNode *list6 = nullptr;
  AppendNode(&list6, 1);
  AppendNode(&list6, 2);
  AppendNode(&list6, 3);
  AppendNode(&list6, 4);
  AppendNode(&list6, 5);
  if (EntryNodeOfLoop(list6) == nullptr) {
    std::cout << "Test6 Pass" << std::endl;
  } else {
    std::cout << "Test6 Fail" << std::endl;
  }

  if (EntryNodeOfLoop(nullptr) == nullptr) {
    std::cout << "Test7 Pass" << std::endl;
  } else {
    std::cout << "Test7 Fail" << std::endl;
  }
}

void TestReverseList() {
  ListNode *list1 = nullptr;
  AppendNode(&list1, 1);
  AppendNode(&list1, 2);
  AppendNode(&list1, 3);
  AppendNode(&list1, 4);
  AppendNode(&list1, 5);
  PrintLinkList(list1);
  PrintLinkList(ReverseList(list1));

  ListNode *list2 = nullptr;
  AppendNode(&list2, 1);
  PrintLinkList(list2);
  PrintLinkList(ReverseList(list2));

  PrintLinkList(ReverseList(nullptr));
}

void TestMergeList() {
  ListNode *list11 = nullptr;
  AppendNode(&list11, 1);
  AppendNode(&list11, 3);
  AppendNode(&list11, 5);
  PrintLinkList(list11);
  ListNode *list12 = nullptr;
  AppendNode(&list12, 2);
  AppendNode(&list12, 4);
  AppendNode(&list12, 6);
  PrintLinkList(list12);
  PrintLinkList(MergeList(list11, list12));

  ListNode *list21 = nullptr;
  AppendNode(&list21, 1);
  AppendNode(&list21, 3);
  AppendNode(&list21, 5);
  PrintLinkList(list21);
  ListNode *list22 = nullptr;
  AppendNode(&list22, 1);
  AppendNode(&list22, 3);
  AppendNode(&list22, 5);
  PrintLinkList(list22);
  PrintLinkList(MergeList(list21, list22));

  ListNode *list31 = nullptr;
  AppendNode(&list31, 1);
  PrintLinkList(list31);
  ListNode *list32 = nullptr;
  AppendNode(&list32, 2);
  PrintLinkList(list32);
  PrintLinkList(MergeList(list31, list32));

  ListNode *list41 = nullptr;
  AppendNode(&list41, 1);
  AppendNode(&list41, 3);
  AppendNode(&list41, 5);
  PrintLinkList(list41);
  PrintLinkList(MergeList(list41, nullptr));
  PrintLinkList(MergeList(nullptr, list41));

  PrintLinkList(MergeList(nullptr, nullptr));
}

void TestFindFirstCommonNode() {
  ListNode *list11 = nullptr;
  AppendNode(&list11, 1);
  AppendNode(&list11, 2);
  AppendNode(&list11, 3);
  ListNode *common_node = AppendNode(&list11, 6);
  AppendNode(&list11, 7);
  ListNode *list12 = nullptr;
  AppendNode(&list12, 4);
  ListNode *last_node = AppendNode(&list12, 5);
  last_node->next = common_node;
  PrintLinkList(list11);
  PrintLinkList(list12);
  std::cout << FindFirstCommonNode(list11, list12)->value << std::endl;

  ListNode *list21 = nullptr;
  AppendNode(&list21, 1);
  AppendNode(&list21, 2);
  AppendNode(&list21, 3);
  AppendNode(&list21, 4);
  ListNode *list22 = nullptr;
  AppendNode(&list22, 5);
  AppendNode(&list22, 6);
  AppendNode(&list22, 7);
  PrintLinkList(list21);
  PrintLinkList(list22);
  std::cout << (FindFirstCommonNode(list21, list22) == nullptr ? "Test2 Pass" : "Test2 Fail") << std::endl;

  ListNode *list31 = nullptr;
  AppendNode(&list31, 1);
  AppendNode(&list31, 2);
  AppendNode(&list31, 3);
  AppendNode(&list31, 4);
  common_node = AppendNode(&list31, 7);
  ListNode *list32 = nullptr;
  AppendNode(&list32, 5);
  last_node = AppendNode(&list32, 6);
  last_node->next = common_node;
  PrintLinkList(list31);
  PrintLinkList(list32);
  std::cout << FindFirstCommonNode(list31, list32)->value << std::endl;

  ListNode *list41 = nullptr;
  AppendNode(&list41, 1);
  AppendNode(&list41, 2);
  AppendNode(&list41, 3);
  AppendNode(&list41, 4);
  AppendNode(&list41, 5);
  PrintLinkList(list41);
  PrintLinkList(list41);
  std::cout << FindFirstCommonNode(list41, list41)->value << std::endl;

  std::cout << (FindFirstCommonNode(list41, nullptr) == nullptr ? "Test5 Pass" : "Test5 Fail") << std::endl;
  std::cout << (FindFirstCommonNode(nullptr, list41) == nullptr ? "Test6 Pass" : "Test6 Fail") << std::endl;
  std::cout << (FindFirstCommonNode(nullptr, nullptr) == nullptr ? "Test7 Pass" : "Test7 Fail") << std::endl;
}