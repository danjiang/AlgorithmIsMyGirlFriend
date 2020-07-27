//
// Created by Dan Jiang on 2020/7/27.
//

#ifndef ALGORITHMISMYGIRLFRIEND_HASHTABLE_CHAR_HASH_TABLE_H_
#define ALGORITHMISMYGIRLFRIEND_HASHTABLE_CHAR_HASH_TABLE_H_

char FindFirstNotRepeatChar(const char *string);

class CharStatistics {
 public:
  CharStatistics();
  void Insert(char ch);
  char FirstAppearingOnce();
 private:
  int occurrence[256];
  int index;
};

#endif //ALGORITHMISMYGIRLFRIEND_HASHTABLE_CHAR_HASH_TABLE_H_
