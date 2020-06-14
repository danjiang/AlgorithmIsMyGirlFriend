//
// Created by Dan Jiang on 2020/6/14.
//

#include "intersect_two_sorted_link_list.h"

ListNode* IntersectTwoSortedLinkList(ListNode *first_head, ListNode *second_head) {
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