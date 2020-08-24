//
// Created by Dan Jiang on 2020/7/16.
//

#include "find_node_of_cache_in_link_list.h"

ListNode* FindNodeInFIFOCache(int value, ListNode **head, int max_size) {
  if (head == nullptr || max_size <= 0) {
    return nullptr;
  }

  ListNode *node = *head;
  ListNode *prev_node = nullptr;
  int size = 0;
  while (node != nullptr && node->value != value) {
    prev_node = node;
    node = node->next;
    size++;
  }
  if (node != nullptr) {
    return node;
  } else {
    auto *new_node = new ListNode(value);
    if (size == max_size) {
      auto deleted_node = *head;
      if ((*head)->next == nullptr) {
        *head = new_node;
      } else {
        *head = (*head)->next;
        prev_node->next = new_node;
      }
      delete deleted_node;
    } else {
      if (prev_node == nullptr) {
        *head = new_node;
      } else {
        prev_node->next = new_node;
      }
    }
    return new_node;
  }
}

ListNode* FindNodeInLFUCache(int value, ListNode **head, int max_size) {
  if (head == nullptr || max_size <= 0) {
    return nullptr;
  }

  ListNode *node = *head;
  ListNode *prev_node = nullptr;
  ListNode *prev_prev_node = nullptr;
  int size = 0;
  while (node != nullptr && node->value != value) {
    prev_prev_node = prev_node;
    prev_node = node;
    node = node->next;
    size++;
  }
  if (node != nullptr) {
    ListNode *inserted_node = node;
    inserted_node->count++;
    if (prev_node != nullptr) {
      prev_node->next = inserted_node->next;

      node = *head;
      prev_node = nullptr;
      while (node != nullptr) {
        if (inserted_node->count > node->count) {
          if (prev_node == nullptr) {
            inserted_node->next = *head;
            *head = inserted_node;
          } else {
            prev_node->next = inserted_node;
            inserted_node->next = node;
          }
          break;
        }
        prev_node = node;
        node = node->next;
      }
      if (node == nullptr) {
        prev_node->next = inserted_node;
        inserted_node->next = nullptr;
      }
    }
    return inserted_node;
  } else {
    auto *new_node = new ListNode(value);
    if (size == max_size) {
      ListNode *deleted_node;
      if (prev_prev_node == nullptr) {
        deleted_node = *head;
        *head = new_node;
      } else {
        deleted_node = prev_node;
        prev_prev_node->next = new_node;
      }
      delete deleted_node;
    } else {
      if (prev_node == nullptr) {
        *head = new_node;
      } else {
        prev_node->next = new_node;
      }
    }
    return new_node;
  }
}

ListNode* FindNodeInLRUCache(int value, ListNode **head, int max_size) {
  if (head == nullptr || max_size <= 0) {
    return nullptr;
  }

  ListNode *node = *head;
  ListNode *prev_node = nullptr;
  ListNode *prev_prev_node = nullptr;
  int size = 0;
  while (node != nullptr && node->value != value) {
    prev_prev_node = prev_node;
    prev_node = node;
    node = node->next;
    size++;
  }
  if (node != nullptr) {
    if (prev_node != nullptr) {
      prev_node->next = node->next;
      node->next = *head;
      *head = node;
    }
    return node;
  } else {
    auto *new_node = new ListNode(value);
    if (size == max_size) {
      ListNode *deleted_node;
      if (prev_prev_node == nullptr) {
        deleted_node = *head;
        *head = new_node;
      } else {
        deleted_node = prev_node;
        prev_prev_node->next = nullptr;
        new_node->next = *head;
        *head = new_node;
      }
      delete deleted_node;
    } else {
      new_node->next = *head;
      *head = new_node;
    }
    return new_node;
  }
}