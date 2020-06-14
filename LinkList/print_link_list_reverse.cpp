//
// Created by Dan Jiang on 2020/6/14.
//

#include "print_link_list_reverse.h"

#include <stack>

void PrintLinkListReverseIteratively(ListNode *head, std::ostringstream &os) {
  std::stack<ListNode *> nodes;
  ListNode *node = head;
  while (node != nullptr) {
    nodes.push(node);
    node = node->next;
  }
  while (!nodes.empty()) {
    node = nodes.top();
    os << node->value << " ";
    nodes.pop();
  }
}

void PrintLinkListReverseRecursively(ListNode *head, std::ostringstream &os) {
  if (head != nullptr) {
    if (head->next != nullptr) {
      PrintLinkListReverseRecursively(head->next, os);
    }
    os << head->value << " ";
  }
}