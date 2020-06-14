//
// Created by Dan Jiang on 2020/6/14.
//

#include "link_list.h"

void ConnectListNodes(ListNode *current, ListNode *next) {
  if (current != nullptr) {
    current->next = next;
  }
}

void DestroyLinkList(ListNode *head) {
  if (head != nullptr) {
    DestroyLinkList(head->next);
    delete head;
    head = nullptr;
  }
}

bool IsSameLinkList(ListNode *head1, ListNode *head2) {
  if (head1 == nullptr && head2 == nullptr) {
    return true;
  }
  if (head1 == nullptr || head2 == nullptr) {
    return false;
  }
  return head1->value == head2->value
      && IsSameLinkList(head1->next, head2->next);
}

void PrintLinkList(ListNode *head, std::ostringstream &os) {
  if (head != nullptr) {
    ListNode *node = head;
    while (node != nullptr){
      os << node->value << " ";
      node = node->next;
    }
  }
}

int LengthOfLinkList(ListNode *head) {
  int length = 0;
  ListNode *node = head;
  while (node != nullptr) {
    node = node->next;
    length++;
  }
  return length;
}