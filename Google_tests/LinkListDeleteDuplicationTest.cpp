//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list_append_node.h"
#include "link_list_remove_node.h"

TEST(LinkListDeleteDuplication, Test1) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 4);
  LinkListAppendNode(&head, 4);
  LinkListAppendNode(&head, 5);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 5 ");
}

TEST(LinkListDeleteDuplication, Test2) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 4);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 3 4 ");
}

TEST(LinkListDeleteDuplication, Test3) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 ");
}

TEST(LinkListDeleteDuplication, Test4) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST(LinkListDeleteDuplication, Test5) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 3);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST(LinkListDeleteDuplication, Test6) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 2);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 3);
  LinkListAppendNode(&head, 4);
  LinkListAppendNode(&head, 5);
  LinkListAppendNode(&head, 5);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 4 ");
}

TEST(LinkListDeleteDuplication, Test7) {
  ListNode *head = nullptr;
  LinkListAppendNode(&head, 1);
  LinkListAppendNode(&head, 1);
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}