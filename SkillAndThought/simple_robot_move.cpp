//
// Created by Dan Jiang on 2020/8/6.
//

#include "simple_robot_move.h"

#include <string>

int SimpleRobotMoveSum(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

bool SimpleRobotMoveCheck(int row, int column, bool visited[],
                          int rows, int columns, int threshold) {
  if (row >= 0 && row < rows
      && column >= 0 && column < columns
      && SimpleRobotMoveSum(row) + SimpleRobotMoveSum(column) <= threshold
      && !visited[row * columns + column]) {
    return true;
  }
  return false;
}

int SimpleRobotMoveCore(int row, int column, bool visited[],
                        int rows, int columns, int threshold) {
  int count = 0;
  if (SimpleRobotMoveCheck(row, column, visited, rows, columns, threshold)) {
    visited[row * columns + column] = true;
    count = 1 + SimpleRobotMoveCore(row - 1, column, visited, rows, columns, threshold)
        + SimpleRobotMoveCore(row + 1, column, visited, rows, columns, threshold)
        + SimpleRobotMoveCore(row, column - 1, visited, rows, columns, threshold)
        + SimpleRobotMoveCore(row, column + 1, visited, rows, columns, threshold);
  }
  return count;
}

int SimpleRobotMove(int rows, int columns, int threshold) {
  if (rows <= 0 || columns <= 0 || threshold < 0) {
    throw invalid_input("invalid input");
  }

  bool visited[rows * columns];
  for (int i = 0; i < rows * columns; ++i) {
    visited[i] = false;
  }

  return SimpleRobotMoveCore(0, 0, visited, rows, columns, threshold);
}