//
// Created by Dan Jiang on 2020/4/26.
//

#include "time_efficiency.h"
#include <cstdio>

struct Result {
    int offset; // 序列的开始位置
    int count;  // 序列的长度
};
// [1, 5, 3, 4, 10, 7, 8, 9, 20, 21, 11, 12, 13, 14, 15, 22] => [11, 12, 13, 14, 15] => {10, 5}
int FindLongestSeq(int arr[], int size, struct Result * result) {
    if (arr == nullptr || size == 0) {
        return -1;
    }
    if (size <= 1) {
        result->offset = 0;
        result->count = 1;
        return 0;
    }
    int maxOffset = 0;
    int maxCount = 1;
    int count = 1;
    int index = 1;
    while (index < size) {
        if (arr[index - 1] + 1 == arr[index]) {
            count++;
        } else {
            if (count > maxCount) {
               maxCount = count;
               maxOffset = index - count;
            }
            count = 1;
        }
        index++;
    }
    index--;
    if (arr[index - 1] + 1 == arr[index]) {
        if (count > maxCount) {
            maxCount = count;
            maxOffset = index - count + 1;
        }
    }
    result->offset = maxOffset;
    result->count = maxCount;
    return 0;
}

void ValidFindLongestSeq(int array[], int size) {
    Result result;
    if (FindLongestSeq(array, size, &result) == 0) {
        printf("%d, %d : ", result.offset, result.count);
        for (int i = result.offset; i < result.offset + result.count; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        printf("Invalid\n");
    }
}

void TestFindLongestSeq() {
    int array1[] = {1, 5, 3, 4, 10, 7, 8, 9, 20, 21, 11, 12, 13, 14, 15, 22};
    int size1 = int(sizeof(array1) / sizeof(array1[0]));
    ValidFindLongestSeq(array1, size1);
    int array2[] = {1, 3, 4, 6, 7, 8, 9, 20, 21, 10, 11, 12, 13, 14, 15};
    int size2 = int(sizeof(array2) / sizeof(array2[0]));
    ValidFindLongestSeq(array2, size2);
    int array3[] = {2};
    ValidFindLongestSeq(array3, 1);
    int array4[] = {};
    ValidFindLongestSeq(array4, 0);
}