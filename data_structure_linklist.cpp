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

void AppendNode(ListNode **head, int value) {
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