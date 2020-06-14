//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list.h"

#include "print_link_list_reverse.h"
#include "link_list_remove_node.h"
#include "find_middle_node_of_link_list.h"
#include "entry_node_of_loop_link_list.h"
#include "reverse_link_list.h"

class EmptyLinkListFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    head = nullptr;
  }

  virtual void TearDown() {
  }

  ListNode *head;
};

TEST_F(EmptyLinkListFixture, PrintListReverse) {
  std::ostringstream os;
  PrintLinkListReverseIteratively(head, os);
  EXPECT_EQ(os.str(),"");
  os.str("");
  PrintLinkListReverseRecursively(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(EmptyLinkListFixture, LinkListRemoveNode) {
  LinkListRemoveNode(&head, 1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(EmptyLinkListFixture, LinkListDeleteNode) {
  auto delete_node = head;
  LinkListDeleteNode(&head, delete_node);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(EmptyLinkListFixture, FindMiddleNodeOfLinkList) {
  auto middle = FindMiddleNodeOfLinkList(head);
  EXPECT_EQ(middle, nullptr);
}

TEST_F(EmptyLinkListFixture, LinkListDeleteDuplication) {
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(EmptyLinkListFixture, EntryNodeOfLoopLinkList) {
  auto entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry, nullptr);
}

TEST_F(EmptyLinkListFixture, ReverseLinkList) {
  auto reverse_head = ReverseLinkList(head);
  std::ostringstream os;
  PrintLinkList(reverse_head, os);
  EXPECT_EQ(os.str(),"");
}