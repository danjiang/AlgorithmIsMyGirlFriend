//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list.h"

#include "print_link_list_reverse.h"
#include "link_list_append_node.h"
#include "link_list_remove_node.h"
#include "entry_node_of_loop_link_list.h"
#include "reverse_link_list.h"

class OneNodeLinkListFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    // 1
    auto node1 = new ListNode(1);

    head = node1;
  }

  virtual void TearDown() {
    DestroyLinkList(head);
  }

  ListNode *head;
};

TEST_F(OneNodeLinkListFixture, PrintListReverse) {
  std::ostringstream os;
  PrintLinkListReverseIteratively(head, os);
  EXPECT_EQ(os.str(),"1 ");
  os.str("");
  PrintLinkListReverseRecursively(head, os);
  EXPECT_EQ(os.str(),"1 ");
}

TEST_F(OneNodeLinkListFixture, LinkListAppendNode) {
  ListNode *new_head;
  LinkListAppendNode(&new_head, 1);
  EXPECT_TRUE(IsSameLinkList(head, new_head));
}

TEST_F(OneNodeLinkListFixture, LinkListRemoveNode) {
  LinkListRemoveNode(&head, 1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(OneNodeLinkListFixture, LinkListDeleteNode) {
  auto delete_node = head;
  LinkListDeleteNode(&head, delete_node);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"");
}

TEST_F(OneNodeLinkListFixture, LinkListDeleteDuplication) {
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");
}

TEST_F(OneNodeLinkListFixture, EntryNodeOfLoopLinkList) {
  auto entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry, nullptr);
}

TEST_F(OneNodeLinkListFixture, ReverseLinkList) {
  auto reverse_head = ReverseLinkList(head);
  std::ostringstream os;
  PrintLinkList(reverse_head, os);
  EXPECT_EQ(os.str(),"1 ");
}