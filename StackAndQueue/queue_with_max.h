//
// Created by Dan Jiang on 2020/8/10.
//

#ifndef ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_WITH_MAX_H_
#define ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_WITH_MAX_H_

#include "../common.h"
#include <vector>
#include <deque>

std::vector<int> MaxInSlidingWindow(int array[], int size, int window);

class QueueWithMax {
 public:
  QueueWithMax();
  void Push(int value);
  int Pop();
  int Max();
 private:
  struct InternalData {
    int index;
    int number;
  };
  int index = 0;
  std::deque<InternalData> queue;
  std::deque<InternalData> max;
};

#endif //ALGORITHMISMYGIRLFRIEND_STACKANDQUEUE_QUEUE_WITH_MAX_H_
