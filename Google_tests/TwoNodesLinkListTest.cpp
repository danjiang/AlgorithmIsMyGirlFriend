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

class TwoNodesLinkListFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    // 1->2
    auto node1 = new ListNode(1);
    auto node2 = new ListNode(2);

    ConnectListNodes(node1, node2);

    head = node1;
  }

  virtual void TearDown() {
    DestroyLinkList(head);
  }

  ListNode *head;
};

TEST_F(TwoNodesLinkListFixture, PrintListReverse) {
  std::ostringstream os;
  PrintLinkListReverseIteratively(head, os);
  EXPECT_EQ(os.str(),"2 1 ");
  os.str("");
  PrintLinkListReverseRecursively(head, os);
  EXPECT_EQ(os.str(),"2 1 ");
}

TEST_F(TwoNodesLinkListFixture, LinkListAppendNode) {
  ListNode *new_head;
  LinkListAppendNode(&new_head, 1);
  LinkListAppendNode(&new_head, 2);
  EXPECT_TRUE(IsSameLinkList(head, new_head));
}

TEST_F(TwoNodesLinkListFixture, LinkListRemoveNode) {
  LinkListRemoveNode(&head, 2);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");
}

TEST_F(TwoNodesLinkListFixture, LinkListDeleteNode) {
  auto delete_node = head->next;
  LinkListDeleteNode(&head, delete_node);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");
}

TEST_F(TwoNodesLinkListFixture, LinkListDeleteDuplication) {
  LinkListDeleteDuplication(&head);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");
}

TEST_F(TwoNodesLinkListFixture, EntryNodeOfLoopLinkList) {
  auto last = head->next;
  last->next = head;
  auto entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry->value, 1);
  last->next = nullptr;
}

TEST_F(TwoNodesLinkListFixture, ReverseLinkList) {
  auto reverse_head = ReverseLinkList(head);
  std::ostringstream os;
  PrintLinkList(reverse_head, os);
  EXPECT_EQ(os.str(),"2 1 ");
}