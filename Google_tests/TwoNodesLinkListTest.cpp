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
#include "find_cache_of_link_list.h"

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

TEST_F(TwoNodesLinkListFixture, FindNodeInFIFOCache) {
  auto node = FindNodeInFIFOCache(1, &head, 3);
  EXPECT_EQ(node->value,1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInFIFOCache(2, &head, 3);
  EXPECT_EQ(node->value,2);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInFIFOCache(3, &head, 3);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 3 ");

  node = FindNodeInFIFOCache(4, &head, 3);
  EXPECT_EQ(node->value,4);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 3 4 ");
}

TEST_F(TwoNodesLinkListFixture, FindNodeInLFUCache) {
  auto node = FindNodeInLFUCache(2, &head, 3);
  EXPECT_EQ(node->value, 2);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 1 ");

  node = FindNodeInLFUCache(1, &head, 3);
  EXPECT_EQ(node->value,1);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 1 ");

  node = FindNodeInLFUCache(1, &head, 3);
  EXPECT_EQ(node->value,1);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInLFUCache(3, &head, 3);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 3 ");

  node = FindNodeInLFUCache(4, &head, 3);
  EXPECT_EQ(node->value,4);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 4 ");
}

TEST_F(TwoNodesLinkListFixture, FindNodeInLRUCache) {
  auto node = FindNodeInLRUCache(1, &head, 3);
  EXPECT_EQ(node->value,1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInLRUCache(2, &head, 3);
  EXPECT_EQ(node->value,2);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 1 ");

  node = FindNodeInLRUCache(3, &head, 3);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"3 2 1 ");

  node = FindNodeInLRUCache(4, &head, 3);
  EXPECT_EQ(node->value,4);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"4 3 2 ");
}