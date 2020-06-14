//
// Created by Dan Jiang on 2020/6/14.
//

#include "find_middle_node_of_link_list.h"

ListNode* FindMiddleNodeOfLinkList(ListNode *head) {
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