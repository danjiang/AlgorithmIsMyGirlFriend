//
// Created by Dan Jiang on 2020/7/31.
//

#ifndef ALGORITHMISMYGIRLFRIEND_GRAPH_GRAPH_H_
#define ALGORITHMISMYGIRLFRIEND_GRAPH_GRAPH_H_

#include "../common.h"
#include <vector>
#include <list>

class GraphInLinkList {
 public:
  GraphInLinkList(int vertices_size);
  void AddEdge(int start_vertex, int end_vertex);
  void BFS(int start_vertex, int end_vertex);
  void DFS(int start_vertex, int end_vertex);
 private:
  std::vector<std::list<int>> adjacent_vertices_;
  int vertices_size_;
  bool DFSCore(int vertex, int end_vertex, std::vector<bool> visited, std::vector<int> &prev);
  void Print(std::vector<int> prev, int start_vertex, int end_vertex);
};


#endif //ALGORITHMISMYGIRLFRIEND_GRAPH_GRAPH_H_
