//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list_append_node.h"
#include "merge_link_list.h"

TEST(MergeLinkList, Test1) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 3);
  LinkListAppendNode(&head1, 5);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 2);
  LinkListAppendNode(&head2, 4);
  LinkListAppendNode(&head2, 6);
  auto head = MergeLinkList(head1, head2);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 3 4 5 6 ");
}

TEST(MergeLinkList, Test2) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 3);
  LinkListAppendNode(&head1, 5);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 1);
  LinkListAppendNode(&head2, 3);
  LinkListAppendNode(&head2, 5);
  auto head = MergeLinkList(head1, head2);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 1 3 3 5 5 ");
}

TEST(MergeLinkList, Test3) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  ListNode *head2 = nullptr;
  LinkListAppendNode(&head2, 2);
  auto head = MergeLinkList(head1, head2);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");
}

TEST(MergeLinkList, Test4) {
  ListNode *head1 = nullptr;
  LinkListAppendNode(&head1, 1);
  LinkListAppendNode(&head1, 3);
  LinkListAppendNode(&head1, 5);
  auto head = MergeLinkList(head1, nullptr);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 3 5 ");

  head = MergeLinkList(nullptr, head1);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 3 5 ");
}

TEST(MergeLinkList, Test5) {
  auto head = MergeLinkList(nullptr, nullptr);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}