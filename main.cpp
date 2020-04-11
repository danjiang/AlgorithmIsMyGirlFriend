#include <iostream>
#include "common.h"
#include "sort.h"

int main() {
    int array[] = {5, 1, 4, 2, 8};
    int size = 5;
    MergeSort(array, size, 0, size - 1);
    PrintArray(array, size);
    return 0;
}
