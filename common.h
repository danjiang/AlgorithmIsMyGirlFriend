//
// Created by Dan Jiang on 2020/4/11.
//

#ifndef ALGORITHMISMYGIRLFRIEND_COMMON_H
#define ALGORITHMISMYGIRLFRIEND_COMMON_H

#include <stdexcept>

class invalid_input: public std::logic_error {
 public:
  explicit invalid_input(const std::string &s): std::logic_error(s) {}
};

class invalid_operation: public std::logic_error {
 public:
  explicit invalid_operation(const std::string &s): std::logic_error(s) {}
};

#endif //ALGORITHMISMYGIRLFRIEND_COMMON_H
