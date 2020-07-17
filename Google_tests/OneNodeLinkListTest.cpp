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
#include "find_node_of_cache_in_link_list.h"

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

TEST_F(OneNodeLinkListFixture, FindNodeInFIFOCache) {
  auto node = FindNodeInFIFOCache(1, &head, 2);
  EXPECT_EQ(node->value,1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");

  node = FindNodeInFIFOCache(2, &head, 2);
  EXPECT_EQ(node->value,2);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInFIFOCache(3, &head, 2);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 3 ");
}

TEST_F(OneNodeLinkListFixture, FindNodeInLFUCache) {
  auto node = FindNodeInLFUCache(1, &head, 2);
  EXPECT_EQ(node->value, 1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");

  node = FindNodeInLFUCache(2, &head, 2);
  EXPECT_EQ(node->value,2);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 2 ");

  node = FindNodeInLFUCache(3, &head, 2);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 3 ");
}

TEST_F(OneNodeLinkListFixture, FindNodeInLRUCache) {
  auto node = FindNodeInLRUCache(1, &head, 2);
  EXPECT_EQ(node->value,1);
  std::ostringstream os;
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"1 ");

  node = FindNodeInLRUCache(2, &head, 2);
  EXPECT_EQ(node->value,2);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"2 1 ");

  node = FindNodeInLRUCache(3, &head, 2);
  EXPECT_EQ(node->value,3);
  os.str("");
  PrintLinkList(head, os);
  EXPECT_EQ(os.str(),"3 2 ");
}
