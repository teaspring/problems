#include "radixsort.cpp"
#include "gtest/gtest.h"

/* 
 * int* Solution::countSort(int *A, int n) 
 *
 * void Solution::radixSort(int *A, int n)
 * */

TEST(radixSortTest, Positive01){
    Solution s;

    int arr[] = {329, 457, 657, 839, 436, 720, 355, 41};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {41, 329, 355, 436, 457, 657, 720, 839};

    s.radixSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(countSortTest, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14};

    int *result = s.countSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}
