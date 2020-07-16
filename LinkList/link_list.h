//
// Created by Dan Jiang on 2020/6/14.
//

#ifndef ALGORITHMISMYGIRLFRIEND_LINKLIST_LINK_LIST_H_
#define ALGORITHMISMYGIRLFRIEND_LINKLIST_LINK_LIST_H_

#include <sstream>

struct ListNode {
  int value;
  int count = 1;
  ListNode *next = nullptr;

  ListNode() {};

  ListNode(int value) {
    this->value = value;
  }
};

void ConnectListNodes(ListNode *current, ListNode *next);
void DestroyLinkList(ListNode *head);
bool IsSameLinkList(ListNode *head1, ListNode *head2);
void PrintLinkList(ListNode *head, std::ostringstream &os);
int LengthOfLinkList(ListNode *head);

#endif //ALGORITHMISMYGIRLFRIEND_LINKLIST_LINK_LIST_H_
