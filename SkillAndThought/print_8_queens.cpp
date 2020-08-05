//
// Created by Dan Jiang on 2020/8/5.
//

#include "print_8_queens.h"

#include <iostream>

void Print8QueensArray(int array[], int size) {
  for (int row = 0; row < size; ++row) {
    for (int column = 0; column < size; ++column) {
      if (array[row] == column) {
        std::cout << "Q";
      } else {
        std::cout << "_";
      }
    }
    std::cout << std::endl;
  }
}

bool Check8QueensRule(int row, int column, int array[], int size) {
  int left_top = column - 1;
  int right_top = column + 1;
  for (int i = row - 1; i >= 0; --i) {
    if (array[i] == column) {
      return false;
    }
    if (left_top >= 0 && array[i] == left_top) {
      return false;
    }
    if (right_top < 8 && array[i] == right_top) {
      return false;
    }
    left_top--;
    right_top++;
  }
  return true;
}

void Fill8QueensArray(int row, int *array, int size) {
  if (row == 8) {
    std::cout << std::endl;
    Print8QueensArray(array, size);
    std::cout << std::endl;
    return;
  }
  // from top to bottom and from left to right
  for (int column = 0; column < size; ++column) {
    if (Check8QueensRule(row, column, array, size)) {
      array[row] = column;
      Fill8QueensArray(row + 1, array, size);
    }
  }
  // if every columns for row is not work, go back to row - 1
}

void Print8Queens() {
  int size = 8;
  int array[size];
  Fill8QueensArray(0, array, size);
}