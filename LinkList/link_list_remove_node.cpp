//
// Created by Dan Jiang on 2020/6/14.
//

#include "link_list_remove_node.h"

void LinkListRemoveNode(ListNode **head, int value) {
  if (head == nullptr || *head == nullptr) {
    return;
  }

  ListNode *deleted_node = nullptr;
  if ((*head)->value == value) {
    deleted_node = *head;
    *head = (*head)->next;
  } else {
    ListNode *node = *head;
    ListNode *next_node = (*head)->next;
    while (next_node != nullptr) {
      if (next_node->value == value) {
        deleted_node = next_node;
        node->next = next_node->next;
        break;
      }
      node = node->next;
      next_node = next_node->next;
    }
  }
  delete deleted_node;
}

void LinkListDeleteNode(ListNode **head, ListNode *deleted_node) {
  if (head == nullptr || *head == nullptr || deleted_node == nullptr) {
    return;
  }

  if (deleted_node->next != nullptr) { // not last node
    auto next_node = deleted_node->next;
    deleted_node->value = next_node->value;
    deleted_node->next = next_node->next;

    delete next_node;
  } else if ((*head)->next == nullptr) { // only one node
    *head = nullptr;

    delete deleted_node;
  } else { // last node
    ListNode *node = *head;
    while (node->next->next != nullptr) { // node before last node
      node = node->next;
    }
    node->next = nullptr;

    delete deleted_node;
  }
}

void LinkListDeleteDuplication(ListNode **head) {
  if (head == nullptr || *head == nullptr) {
    return;
  }

  ListNode *prev_node = nullptr;
  ListNode *node = *head;
  while (node != nullptr) {
    ListNode *next_node = node->next;
    bool need_delete = false;
    while (next_node != nullptr && node->value == next_node->value) {
      ListNode *deleted_node = next_node;
      next_node = next_node->next;
      need_delete = true;
      delete deleted_node;
    }
    if (need_delete) {
      delete node;

      if (prev_node == nullptr) {
        *head = next_node;
      } else {
        prev_node->next = next_node;
      }
    } else {
      prev_node = node;
    }
    node = next_node;
  }
}