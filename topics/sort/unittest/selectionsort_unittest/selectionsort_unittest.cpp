#include "selectionsort.cpp"
#include "gtest/gtest.h"

/*
 * void Solution::bubbleSort(int *A, int n)
 *
 * void Solution::selectionSort(int *A, int n)
 *
 * void Solution::insertionSort(int *A, int n)
 *
 * void Solution::mergeSort(int *A, int n)
 *
 * */

TEST(bubbleSortTest, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 103, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 103};

    s.bubbleSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(selectionSortTest, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 103, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 103};

    s.selectionSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(insertionSortTest, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 103, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 103};

    s.insertionSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(mergeSortTest, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 103, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 103};

    s.mergeSort(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}
