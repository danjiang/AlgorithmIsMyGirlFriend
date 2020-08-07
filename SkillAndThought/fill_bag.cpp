//
// Created by Dan Jiang on 2020/8/5.
//

#include "fill_bag.h"

#include <iostream>

void PrintBagBacktracking(int max, bool max_chosen[],
                          int weights[], int weights_size,
                          int values[]) {
  std::cout <<  std::endl;
  std::cout << "backtracking" << std::endl;
  if (values != nullptr) {
    std::cout << "max value = " << max << std::endl;
  } else {
    std::cout << "max weight = " << max << std::endl;
  }
  for (int i = 0; i < weights_size; ++i) {
    if (max_chosen[i]) {
      std::cout << "[" << i << "]=" << weights[i];
      if (values != nullptr) {
        std::cout << "," << values[i];
      }
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void PrintBagDynamic(bool states[], int max_weight, int weights[], int size, int bag_max_weight) {
  int bag_size = bag_max_weight + 1;
  std::cout <<  std::endl;
  std::cout << "dynamic programming" << std::endl;
  std::cout << "max weight = " << max_weight << std::endl;
  for (int index = size - 1; index >= 0; --index) {
    if (max_weight - weights[index] >= 0
        && states[(index - 1) * bag_size + max_weight - weights[index]]) {
      std::cout << "[" << index << "]=" << weights[index] << " ";
      max_weight -= weights[index];
    }
  }
  std::cout << std::endl;
}

void PrintBagAdvanceDynamic(int states[], int max_weight, int weights[], int size, int bag_max_weight, int max_value, int values[]) {
  int bag_size = bag_max_weight + 1;
  std::cout <<  std::endl;
  std::cout << "dynamic programming" << std::endl;
  std::cout << "max value = " << max_value << std::endl;
  for (int index = size - 1; index >= 0; --index) {
    int old_value = 0;
    if (index - 1 >= 0) {
      old_value = states[(index - 1) * bag_size + max_weight - weights[index]];
    }
    if (max_weight - weights[index] >= 0
        && old_value + values[index] == max_value) {
      std::cout << "[" << index << "]=" << weights[index] << "," << values[index] << " ";
      max_weight -= weights[index];
      max_value -= values[index];
    }
  }
  std::cout << std::endl;
}

void FillBagBacktrackingCore(int index, int weight, bool chosen[],
                             int *max_weight, bool max_chosen[],
                             int weights[], int size, int bag_max_weight) {
  chosen[index] = false; // not choose item for right now
  if (weight == bag_max_weight || index == size) { // bag is full or no items
    if (weight > *max_weight) {
      *max_weight = weight;
      for (int i = 0; i < size; ++i) {
        max_chosen[i] = chosen[i];
      }
    }
    return;
  }
  // try next item without current item
  FillBagBacktrackingCore(index + 1, weight, chosen,
                          max_weight, max_chosen,
                          weights, size, bag_max_weight);
  // check current item
  if (weight + weights[index] <= bag_max_weight) {
    chosen[index] = true; // choose item
    // try next item with current item
    FillBagBacktrackingCore(index + 1, weight + weights[index], chosen,
                            max_weight, max_chosen,
                            weights, size, bag_max_weight);
  }
}

void FillBagBacktracking(int weights[], int size, int bag_max_weight) {
  if (weights == nullptr || size <= 0 || bag_max_weight <= 0) {
    return;
  }

  bool chosen[size];
  for (int i = 0; i < size; ++i) {
    chosen[i] = false;
  }
  int max_weight = 0 ;
  bool max_chosen[size];
  FillBagBacktrackingCore(0, 0, chosen,
                          &max_weight, max_chosen,
                          weights, size, bag_max_weight);
  PrintBagBacktracking(max_weight, max_chosen, weights, size, nullptr);
}

void FillBagDynamic(int weights[], int size, int bag_max_weight) {
  if (weights == nullptr || size <= 0 || bag_max_weight <= 0) {
    return;
  }

  int bag_size = bag_max_weight + 1;
  bool states[size * bag_size];
  for (int i = 0; i < size * bag_size; ++i) {
    states[i] = false;
  }
  states[0] = true; // not choose first item
  states[weights[0]] = true; // choose first item

  for (int index = 1; index < size; ++index) {
    for (int weight = 0; weight < bag_size; ++weight) {
      if (states[(index - 1) * bag_size + weight]) { // got state
        states[index * bag_size + weight] = true; // not choose item
        if (weights[index] + weight <= bag_max_weight) { // choose item
          states[index * bag_size + weights[index] + weight] = true;
        }
      }
    }
  }

  int max_weight = 0;
  for (int weight = bag_size - 1; weight >= 0; --weight) {
    if (states[(size - 1) * bag_size + weight]) {
      max_weight = weight;
      break;
    }
  }

  PrintBagDynamic(states, max_weight, weights, size, bag_max_weight);
}


void FillBagAdvanceDynamicCore(int index, int weight, int value, bool chosen[],
                               int *max_value, bool max_chosen[],
                               int weights[], int weights_size, int bag_max_weight,
                               int values[]) {
  chosen[index] = false; // not choose item for right now
  if (weight == bag_max_weight || index == weights_size) { // bag is full or no items
    if (value > *max_value) {
      *max_value = value;
      for (int i = 0; i < weights_size; ++i) {
        max_chosen[i] = chosen[i];
      }
    }
    return;
  }
  // try next item without current item
  FillBagAdvanceDynamicCore(index + 1, weight, value, chosen,
                            max_value, max_chosen,
                            weights, weights_size, bag_max_weight,
                            values);
  // check current item
  if (weight + weights[index] <= bag_max_weight) {
    chosen[index] = true; // choose item
    // try next item with current item
    FillBagAdvanceDynamicCore(index + 1, weight + weights[index], value + values[index], chosen,
                              max_value, max_chosen,
                              weights, weights_size, bag_max_weight,
                              values);
  }
}

void FillBagAdvanceBacktracking(int weights[], int size, int bag_max_weight, int values[]) {
  if (weights == nullptr || size <= 0 || bag_max_weight <= 0 || values == nullptr) {
    return;
  }

  bool chosen[size];
  for (int i = 0; i < size; ++i) {
    chosen[i] = false;
  }
  int max_value = 0 ;
  bool max_chosen[size];
  FillBagAdvanceDynamicCore(0, 0, 0, chosen,
                            &max_value, max_chosen,
                            weights, size, bag_max_weight,
                            values);
  PrintBagBacktracking(max_value, max_chosen, weights, size, values);
}

void FillBagAdvanceDynamic(int weights[], int size, int bag_max_weight, int values[]) {
  if (weights == nullptr || size <= 0 || bag_max_weight <= 0 || values == nullptr) {
    return;
  }

  int bag_size = bag_max_weight + 1;
  int states[size * bag_size];
  for (int i = 0; i < size * bag_size; ++i) {
    states[i] = -1;
  }
  states[0] = 0; // not choose first item
  states[weights[0]] = values[0]; // choose first item

  for (int index = 1; index < size; ++index) {
    for (int weight = 0; weight < bag_size; ++weight) {
      if (states[(index - 1) * bag_size + weight] >= 0) { // got state
        // not choose item
        if (states[(index - 1) * bag_size + weight] > states[index * bag_size + weight]) {
          states[index * bag_size + weight] = states[(index - 1) * bag_size + weight];
        }
        // choose item
        if (weights[index] + weight <= bag_max_weight) {
          if (states[(index - 1) * bag_size + weight] + values[index] > states[index * bag_size + weights[index] + weight]) {
            states[index * bag_size + weights[index] + weight] = states[(index - 1) * bag_size + weight] + values[index];
          }
        }
      }
    }
  }

  int max_value = 0;
  int max_weight = 0;
  for (int weight = bag_size - 1; weight >= 0; --weight) {
    if (states[(size - 1) * bag_size + weight] > max_value) {
      max_value = states[(size - 1) * bag_size + weight];
      max_weight = weight;
    }
  }
  if (max_value == -1) {
    return;
  }

  PrintBagAdvanceDynamic(states, max_weight, weights, size, bag_max_weight, max_value, values);
}
