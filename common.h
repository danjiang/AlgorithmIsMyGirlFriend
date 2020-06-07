//
// Created by Dan Jiang on 2020/4/11.
//

#ifndef ALGORITHMISMYGIRLFRIEND_COMMON_H
#define ALGORITHMISMYGIRLFRIEND_COMMON_H

#include <stdexcept>

void PrintArray(int array[], int size);
void Swap(int *a, int *b);

 class invalid_input: public std::logic_error {
  public:
   explicit invalid_input(const std::string &s): std::logic_error(s) {}
 };

#endif //ALGORITHMISMYGIRLFRIEND_COMMON_H
