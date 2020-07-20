//
// Created by Dan Jiang on 2020/7/17.
//

#include "check_palindromic_string_in_link_list.h"

bool CheckPalindromicStringInLinkList(const char *string) {
  if (string == nullptr) {
    return false;
  }
  ListNode *head = nullptr;
  ListNode *node = nullptr;
  while (*string != '\0') {
    auto new_node = new ListNode(*string);
    if (node == nullptr) {
      node = new_node;
      head = node;
    } else {
      node->next = new_node;
      node = new_node;
    }
    string++;
  }

  ListNode *fast = head;
  ListNode *slow = head;

  if (fast == nullptr) { // no node
    return false;
  } else if (fast->next == nullptr) { // one node
    return true;
  } else if (fast->next->next == nullptr) { // two nodes
    return fast->value == fast->next->value;
  }

  ListNode *prev = nullptr;
  ListNode *next = slow->next;
  while (fast != nullptr &&
      fast->next != nullptr &&
      fast->next->next != nullptr) {
    fast = fast->next->next; // two steps
    slow->next = prev;
    prev = slow;
    slow = next; // one step
    next = next->next;
  }

  if (fast->next != nullptr) { // number of nodes is even
    slow->next = prev;
    prev = slow;
  }

  while (prev != nullptr && next != nullptr) {
    if (prev->value != next->value) {
      return false;
    }
    prev = prev->next;
    next = next->next;
  }

  return true;
}