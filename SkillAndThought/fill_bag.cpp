//
// Created by Dan Jiang on 2020/8/5.
//

#include "fill_bag.h"

#include <iostream>

void PrintBag(int max_weight, bool max_choosed_items[], int items[], int size) {
  std::cout << "max weight = " << max_weight << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << items[i] << ":" << (max_choosed_items[i] ? "Y" : "N") << " ";
  }
  std::cout << std::endl;
}

void FillBagCore(int index, int weight, bool choosed_items[],
                 int *max_weight, bool max_choosed_items[],
                 int items[], int size, int bag_max_weight) {
  choosed_items[index] = false; // not choose item
  if (weight == bag_max_weight || index == size) { // bag is full or no items
    if (weight > *max_weight) {
      *max_weight = weight;
      for (int i = 0; i < size; ++i) {
        max_choosed_items[i] = choosed_items[i];
      }
    }
    return;
  }
  // try next item without current item
  FillBagCore(index + 1, weight, choosed_items,
              max_weight, max_choosed_items,
              items, size, bag_max_weight);
  // check current item
  if (weight + items[index] <= bag_max_weight) {
    choosed_items[index] = true; // choose item
    // try next item with current item
    FillBagCore(index + 1, weight + items[index], choosed_items,
                max_weight, max_choosed_items,
                items, size, bag_max_weight);
  }
}

void FillBagZeroOne(int items[], int size, int bag_max_weight) {
  if (items == nullptr || size <= 0 || bag_max_weight <= 0) {
    return;
  }

  bool choosed_items[size];
  for (int i = 0; i < size; ++i) {
    choosed_items[i] = false;
  }
  int max_weight = 0 ;
  bool max_choosed_items[size];
  FillBagCore(0, 0, choosed_items,
              &max_weight, max_choosed_items,
              items, size, bag_max_weight);
  PrintBag(max_weight, max_choosed_items, items, size);
}
