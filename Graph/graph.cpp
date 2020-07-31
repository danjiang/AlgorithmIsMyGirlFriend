//
// Created by Dan Jiang on 2020/7/31.
//

#include "graph.h"

#include <queue>
#include <stack>
#include <iostream>

GraphInLinkList::GraphInLinkList(int vertices_size):
vertices_size_(vertices_size),
adjacent_vertices_(vertices_size) {
}

void GraphInLinkList::AddEdge(int start_vertex, int end_vertex) {
  adjacent_vertices_[start_vertex].push_back(end_vertex);
  adjacent_vertices_[end_vertex].push_back(start_vertex);
}

void GraphInLinkList::BFS(int start_vertex, int end_vertex) {
  if (start_vertex == end_vertex) {
    return;
  }

  std::queue<int> queue;
  std::vector<bool> visited(vertices_size_, false);
  std::vector<int> prev(vertices_size_, -1);

  queue.push(start_vertex);
  visited[start_vertex] = true;

  while (!queue.empty()) {
    int vertex = queue.front();
    queue.pop();
    for (int adjacent_vertex: adjacent_vertices_[vertex]) {
      if (!visited[adjacent_vertex]) {
        queue.push(adjacent_vertex);
        visited[adjacent_vertex] = true;
        prev[adjacent_vertex] = vertex;
        if (adjacent_vertex == end_vertex) {
          std::cout << "BFS" << std::endl;
          Print(prev, start_vertex, end_vertex);
          std::cout << std::endl;
          return;
        }
      }
    }
  }
}

void GraphInLinkList::DFS(int start_vertex, int end_vertex) {
  if (start_vertex == end_vertex) {
    return;
  }

  std::vector<bool> visited(vertices_size_, false);
  std::vector<int> prev(vertices_size_, -1);

  visited[start_vertex] = true;
  if (DFSCore(start_vertex, end_vertex, visited, prev)) {
    std::cout << "DFS" << std::endl;
    Print(prev, start_vertex, end_vertex);
    std::cout << std::endl;
  }
}

bool GraphInLinkList::DFSCore(int vertex, int end_vertex, std::vector<bool> visited, std::vector<int> &prev) {
  for (int adjacent_vertex: adjacent_vertices_[vertex]) {
    if (!visited[adjacent_vertex]) {
      visited[adjacent_vertex] = true;
      prev[adjacent_vertex] = vertex;
      if (adjacent_vertex == end_vertex) {
        return true;
      }
      if (DFSCore(adjacent_vertex, end_vertex, visited, prev)) {
        return true;
      }
    }
  }
  return false;
}

void GraphInLinkList::Print(std::vector<int> prev, int start_vertex, int end_vertex) {
  if (prev[end_vertex] != -1 && start_vertex != end_vertex) {
    Print(prev, start_vertex, prev[end_vertex]);
  }
  std::cout << end_vertex << " ";
}

