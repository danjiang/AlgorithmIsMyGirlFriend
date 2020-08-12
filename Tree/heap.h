//
// Created by Dan Jiang on 2020/7/30.
//

#ifndef ALGORITHMISMYGIRLFRIEND_BINARYTREE_HEAP_H_
#define ALGORITHMISMYGIRLFRIEND_BINARYTREE_HEAP_H_

#include "../common.h"

class HeapInArray {
 public:
  HeapInArray(int length);
  void Insert(int value);
  void RemoveTop();
  int Top();
  void PrintArray();
  void PrintTree();
 private:
  int *array;
  int size;
  int index;
};

#endif //ALGORITHMISMYGIRLFRIEND_BINARYTREE_HEAP_H_
