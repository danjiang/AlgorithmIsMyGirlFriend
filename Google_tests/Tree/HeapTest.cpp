//
// Created by Dan Jiang on 2020/7/30.
//

#include "gtest/gtest.h"

#include "heap.h"

TEST(Heap, HeapInArray) {
  HeapInArray heap{14};

  heap.Insert(33);
  heap.Insert(17);
  heap.Insert(21);
  heap.Insert(16);
  heap.Insert(13);
  heap.Insert(15);
  heap.Insert(9);
  heap.Insert(5);
  heap.Insert(6);
  heap.Insert(7);
  heap.Insert(8);
  heap.Insert(1);
  heap.Insert(2);

  heap.PrintArray();
  heap.PrintTree();

  heap.Insert(22);

  heap.PrintArray();
  heap.PrintTree();

  heap.RemoveTop();

  heap.PrintArray();
  heap.PrintTree();
}