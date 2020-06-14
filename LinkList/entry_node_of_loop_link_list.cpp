//
// Created by Dan Jiang on 2020/6/14.
//

#include "entry_node_of_loop_link_list.h"

ListNode* EntryNodeOfLoopLinkList(ListNode *head) {
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