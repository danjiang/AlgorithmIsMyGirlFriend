//
// Created by Dan Jiang on 2020/6/14.
//

#include "find_kth_to_tail_of_link_list.h"

ListNode* FindKthToTailOfLinkList(ListNode *head, int k) {
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


