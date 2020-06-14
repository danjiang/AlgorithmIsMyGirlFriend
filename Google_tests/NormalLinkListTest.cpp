//
// Created by Dan Jiang on 2020/6/14.
//

#include "gtest/gtest.h"

#include "link_list.h"

#include "print_link_list_reverse.h"
#include "link_list_append_node.h"
#include "link_list_remove_node.h"
#include "find_middle_node_of_link_list.h"
#include "intersect_two_sorted_link_list.h"
#include "find_kth_to_tail_of_link_list.h"
#include "entry_node_of_loop_link_list.h"
#include "reverse_link_list.h"

class NormalLinkListFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    // 1->2->3->4->5
    auto node1 = new ListNode(1);
    auto node2 = new ListNode(2);
    auto node3 = new ListNode(3);
    auto node4 = new ListNode(4);
    auto node5 = new ListNode(5);

    ConnectListNodes(node1, node2);
    ConnectListNodes(node2, node3);
    ConnectListNodes(node3, node4);
    ConnectListNodes(node4, node5);

    head = node1;
  }

  virtual void TearDown() {
    DestroyLinkList(head);
  }

  ListNode *head;
};

TEST_F(NormalLinkListFixture, PrintListReverse) {
  std::ostringstream os;
  PrintLinkListReverseIteratively(head, os);
  EXPECT_EQ(os.str(),"5 4 3 2 1 ");
  os.str("");
  PrintLinkListReverseRecursively(head, os);
  EXPECT_EQ(os.str(),"5 4 3 2 1 ");
}

TEST_F(NormalLinkListFixture, LinkListAppendNode) {
  ListNode *new_head;
  LinkListAppendNode(&new_head, 1);
  LinkListAppendNode(&new_head, 2);
  LinkListAppendNode(&new_head, 3);
  LinkListAppendNode(&new_head, 4);
  LinkListAppendNode(&new_head, 5);
  EXPECT_TRUE(IsSameLinkList(head, new_head));
}

TEST_F(NormalLinkListFixture, LinkListRemoveNode) {
  LinkListRemoveNode(&head, 3);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 4 5 ");
}

TEST_F(NormalLinkListFixture, LinkListDeleteNode) {
  auto delete_node = head->next->next;
  LinkListDeleteNode(&head, delete_node);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 4 5 ");
}

TEST_F(NormalLinkListFixture, FindMiddleNodeOfLinkList) {
  auto middle = FindMiddleNodeOfLinkList(head);
  EXPECT_EQ(middle->value,3);
}

TEST_F(NormalLinkListFixture, IntersectTwoSortedLinkList) {
  // 2->4->5->6->10
  auto node1 = new ListNode(2);
  auto node2 = new ListNode(4);
  auto node3 = new ListNode(5);
  auto node4 = new ListNode(6);
  auto node5 = new ListNode(10);

  ConnectListNodes(node1, node2);
  ConnectListNodes(node2, node3);
  ConnectListNodes(node3, node4);
  ConnectListNodes(node4, node5);
  auto head2 = node1;

  auto new_head = IntersectTwoSortedLinkList(head, head2);
  std::ostringstream os;
  PrintLinkList(new_head, os);
  EXPECT_EQ(os.str(),"2 4 5 ");
}

TEST_F(NormalLinkListFixture, FindKthToTailOfLinkList) {
  auto k_node = FindKthToTailOfLinkList(head, 2);
  EXPECT_EQ(k_node->value,4);
  k_node = FindKthToTailOfLinkList(head, 1);
  EXPECT_EQ(k_node->value,5);
  k_node = FindKthToTailOfLinkList(head, 5);
  EXPECT_EQ(k_node->value,1);
  k_node = FindKthToTailOfLinkList(head, 6);
  EXPECT_EQ(k_node, nullptr);
  k_node = FindKthToTailOfLinkList(head, 0);
  EXPECT_EQ(k_node, nullptr);
  k_node = FindKthToTailOfLinkList(nullptr, 100);
  EXPECT_EQ(k_node, nullptr);
}

TEST_F(NormalLinkListFixture, EntryNodeOfLoopLinkList) {
  auto entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry, nullptr);

  auto last = head->next->next->next->next;
  last->next = head->next->next;
  entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry->value, 3);

  last->next = head;
  entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry->value, 1);

  last->next = last;
  entry = EntryNodeOfLoopLinkList(head);
  EXPECT_EQ(entry->value, 5);

  last->next = nullptr;
}

TEST_F(NormalLinkListFixture, ReverseLinkList) {
  auto reverse_head = ReverseLinkList(head);
  std::ostringstream os;
  PrintLinkList(reverse_head, os);
  EXPECT_EQ(os.str(),"5 4 3 2 1 ");
}