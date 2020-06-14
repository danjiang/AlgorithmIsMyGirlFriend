//
// Created by Dan Jiang on 2020/6/14.
//

#include "merge_link_list.h"

ListNode* MergeLinkList(ListNode *first_head, ListNode *second_head) {
  ListNode *head = nullptr;
  if (first_head == nullptr) {
    return second_head;
  } else if (second_head == nullptr) {
    return first_head;
  }
  if (first_head->value < second_head->value) {
    head = first_head;
    head->next = MergeLinkList(first_head->next, second_head);
  } else {
    head = second_head;
    head->next = MergeLinkList(first_head, second_head->next);
  }
  return head;
}