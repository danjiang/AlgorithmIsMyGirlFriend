//
// Created by Dan Jiang on 2020/7/31.
//

#ifndef ALGORITHMISMYGIRLFRIEND_BINARYTREE_GET_MIDDLE_NUMBER_OF_STREAM_H_
#define ALGORITHMISMYGIRLFRIEND_BINARYTREE_GET_MIDDLE_NUMBER_OF_STREAM_H_

#include <vector>
#include "../common.h"

class DynamicArrayInHeap {
 public:
  DynamicArrayInHeap();
  void Insert(int value);
  double Middle();
 private:
  std::vector<int> max;
  std::vector<int> min;
};

#endif //ALGORITHMISMYGIRLFRIEND_BINARYTREE_GET_MIDDLE_NUMBER_OF_STREAM_H_
