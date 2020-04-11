//
// Created by Dan Jiang on 2020/4/11.
//

#include "common.h"
#include <iostream>

void PrintArray(int array[], int size) {
    for (int k = 0; k < size; ++k) {
        std::cout << array[k] << " ";
    }
    std::cout << std::endl;
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
