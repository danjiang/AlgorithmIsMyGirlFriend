//
// Created by Dan Jiang on 2020/4/11.
//

#ifndef ALGORITHMISMYGIRLFRIEND_SORT_H
#define ALGORITHMISMYGIRLFRIEND_SORT_H

// O(n^2) Bad sorting algorithms, always need O(n^2).
void BubbleSort(int array[], int size);
// O(n^2) Basic sort, is really fast if the array is already sorted and is actually very fast for sorting small arrays.
void InsertionSort(int array[], int size);
// O(n log n) Fast sort, in-place sort.
void QuickSort(int array[], int size, int start, int end);
// O(n log n) Fast sort, but needs a temporary "working" array equal in size to the array being sorted.
void MergeSort(int array[], int size, int start, int end);

#endif //ALGORITHMISMYGIRLFRIEND_SORT_H
