//
// Created by Dan Jiang on 2020/6/14.
//

#include "reverse_link_list.h"

ListNode* ReverseLinkList(ListNode *head) {
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