//
// Created by Dan Jiang on 2020/7/31.
//

#include "gtest/gtest.h"

#include "graph.h"

class GraphFixture : public ::testing::Test {

 protected:
  virtual void SetUp() {
    // 0 - 1 - 2
    // |   |   |
    // 3 - 4 - 5
    //     |   |
    //     6 - 7
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(4, 6);
    graph.AddEdge(5, 7);
    graph.AddEdge(6, 7);
  }

  virtual void TearDown() {
  }

  GraphInLinkList graph { 8 };
};

TEST_F(GraphFixture, BFSCase) {
  graph.BFS(0, 6);
  graph.BFS(1, 6);
  graph.BFS(3, 2);
}

TEST_F(GraphFixture, DFSCase) {
  graph.DFS(0, 6);
  graph.DFS(1, 6);
  graph.DFS(3, 2);
}