//
// Created by Dan Jiang on 2020/7/16.
//

#ifndef ALGORITHMISMYGIRLFRIEND_LINKLIST_FIND_NODE_OF_CACHE_IN_LINK_LIST_H_
#define ALGORITHMISMYGIRLFRIEND_LINKLIST_FIND_NODE_OF_CACHE_IN_LINK_LIST_H_

#include "link_list.h"

ListNode* FindNodeInFIFOCache(int value, ListNode **head, int max_size);
ListNode* FindNodeInLFUCache(int value, ListNode **head, int max_size);
ListNode* FindNodeInLRUCache(int value, ListNode **head, int max_size);

#endif //ALGORITHMISMYGIRLFRIEND_LINKLIST_FIND_NODE_OF_CACHE_IN_LINK_LIST_H_
