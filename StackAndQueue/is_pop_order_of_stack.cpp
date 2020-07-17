//
// Created by Dan Jiang on 2020/7/17.
//

#include "is_pop_order_of_stack.h"

#include <stack>

bool IsPopOrderOfStack(int *push_array, int *pop_array, int length) {
  if (push_array == nullptr || pop_array == nullptr || length <= 0) {
    return false;
  }

  std::stack<int> stack;
  int push_index = 0;
  int pop_index = 0;

  while (pop_index < length) {
    int pop = pop_array[pop_index];
    if (!stack.empty() && stack.top() == pop) {
      stack.pop();
    } else {
      while (push_index < length) {
        int push = push_array[push_index];
        if (push == pop) {
          push_index++;
          break;
        } else {
          push_index++;
          stack.push(push);
        }
      }
    }
    pop_index++;
  }

  return stack.empty();
}