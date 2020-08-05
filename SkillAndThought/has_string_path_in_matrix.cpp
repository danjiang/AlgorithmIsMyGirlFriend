//
// Created by Dan Jiang on 2020/8/5.
//

#include "has_string_path_in_matrix.h"

bool HasStringPathInMatrixCore(char *path, char *matrix, int rows, int columns,
                               int row, int column, int &index, bool visited[]) {
  if (path[index] == '\0') {
    return true;
  }

  bool has_path = false;
  if (row >= 0 && row < rows
      && column >= 0 && column < columns
      && matrix[row * columns + column] == path[index]
      && !visited[row * columns + column]) {
    index++;

    visited[row * columns + column] = true;

    has_path = HasStringPathInMatrixCore(path, matrix, rows, columns, row - 1, column, index, visited)
        || HasStringPathInMatrixCore(path, matrix, rows, columns, row + 1, column, index, visited)
        || HasStringPathInMatrixCore(path, matrix, rows, columns, row, column - 1, index, visited)
        || HasStringPathInMatrixCore(path, matrix, rows, columns, row, column + 1, index, visited);

    if (!has_path) { // go back
      --index;
      visited[row * columns + column] = false;
    }
  }

  return has_path;
}


bool HasStringPathInMatrix(char *path, char *matrix, int rows, int columns) {
  if (path == nullptr || matrix == nullptr || rows <= 0 || columns <= 0) {
    return false;
  }

  bool visited[rows * columns];
  for (int i = 0; i < rows * columns; ++i) {
    visited[i] = false;
  }
  int index = 0;
  for (int row = 0; row < rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      if (HasStringPathInMatrixCore(path, matrix, rows, columns, row, column, index, visited)) {
        return true;
      }
    }
  }

  return false;
}