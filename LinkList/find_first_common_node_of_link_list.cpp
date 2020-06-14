//
// Created by Dan Jiang on 2020/6/14.
//

#include "find_first_common_node_of_link_list.h"

ListNode* FindFirstCommonNodeOfLinkList(ListNode *first_head, ListNode *second_head) {
  int length1 = LengthOfLinkList(first_head);
  int length2 = LengthOfLinkList(second_head);
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

