//
// Created by Dan Jiang on 2020/7/27.
//

#include "find_number_of_matrix.h"

bool FindNumberOfMatrix(int matrix[], int rows, int columns, int number) {
  bool found = false;
  if (matrix != nullptr && rows > 0 && columns > 0) {
    int row = 0;
    int column = columns - 1;
    while (row < rows && column >= 0) {
      if (matrix[row * columns + column] == number) {
        found = true;
        break;
      } else if (matrix[row * columns + column] > number) {
        column--;
      } else {
        row++;
      }
    }
  }
  return found;
}