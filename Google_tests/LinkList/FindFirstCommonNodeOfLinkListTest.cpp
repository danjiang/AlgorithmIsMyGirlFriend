//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list_append_node.h"
#include "find_first_common_node_of_link_list.h"

TEST(FindFirstCommonNodeOfLinkList, Test1) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 2);
  LinkListAppendNode(&head1, 3);
  auto common_node = LinkListAppendNode(&head1, 6);
  LinkListAppendNode(&head1, 7);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 4);
  auto current = LinkListAppendNode(&head2, 5);
  ConnectListNodes(current, common_node);
  auto found_node = FindFirstCommonNodeOfLinkList(head1, head2);
  EXPECT_EQ(found_node->value, common_node->value);
}

TEST(FindFirstCommonNodeOfLinkList, Test2) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 2);
  LinkListAppendNode(&head1, 3);
  LinkListAppendNode(&head1, 4);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 5);
  LinkListAppendNode(&head2, 6);
  LinkListAppendNode(&head2, 7);
  auto found_node = FindFirstCommonNodeOfLinkList(head1, head2);
  EXPECT_EQ(found_node, nullptr);
}

TEST(FindFirstCommonNodeOfLinkList, Test3) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 2);
  LinkListAppendNode(&head1, 3);
  LinkListAppendNode(&head1, 4);
  auto common_node = LinkListAppendNode(&head1, 7);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 5);
  auto current = LinkListAppendNode(&head2, 6);
  ConnectListNodes(current, common_node);
  auto found_node = FindFirstCommonNodeOfLinkList(head1, head2);
  EXPECT_EQ(found_node->value, common_node->value);
}

TEST(FindFirstCommonNodeOfLinkList, Test4) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 4);
  LinkListAppendNode(&head, 5);
  auto found_node = FindFirstCommonNodeOfLinkList(head, head);
  EXPECT_EQ(found_node->value, 1);

  found_node = FindFirstCommonNodeOfLinkList(head, nullptr);
  EXPECT_EQ(found_node, nullptr);

  found_node = FindFirstCommonNodeOfLinkList(nullptr, head);
  EXPECT_EQ(found_node, nullptr);

  found_node = FindFirstCommonNodeOfLinkList(nullptr, nullptr);
  EXPECT_EQ(found_node, nullptr);
}
