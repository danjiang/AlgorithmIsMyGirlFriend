//
// Created by Dan Jiang on 2020/6/14.
//

#include "link_list_append_node.h"

ListNode* LinkListAppendNode(ListNode **head, int value) {
  ListNode *new_node = new ListNode(value);

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