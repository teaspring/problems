#include "shellsort.cpp"
#include "gtest/gtest.h"

/*
 * void Solution::shellSort_Sh(int *A, int n)
 *
 * void Solution::shellSort_LF(int *A, int n)
 *
 * void Solution::shellSort_Hb(int *A, int n)
 *
 * void Solution::shellSort_PS(int *A, int n)
 *
 * void Solution::shellSort_Kn(int *A, int n)
 *
 * void Solution::shellSort_Go(int *A, int n)
 * */

TEST(shellSort_Sh, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 112, 5, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 112};

    s.shellSort_Sh(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(shellSort_LF, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 1, 9, 2, 7, 11, 6, -4};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {-4, 1, 2, 3, 5, 6, 7, 8, 9, 11, 14};

    s.shellSort_LF(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(shellSort_Hb, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 1, 128, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 128};

    s.shellSort_Hb(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(shellSort_PS, Positive01){
    Solution s;

    int arr[] = {3, 251, 14, 8, 5, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 251};

    s.shellSort_PS(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(shellSort_Kn, Positive01){
    Solution s;

    int arr[] = {3, 14, 419, 8, 5, 1, 9, 2, 7, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {1, 2, 3, 5, 6, 7, 8, 9, 11, 14, 419};

    s.shellSort_Kn(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}

TEST(shellSort_Go, Positive01){
    Solution s;

    int arr[] = {3, 14, 8, 5, 1, 9, 2, 7, -11, 11, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected[] = {-11, 1, 2, 3, 5, 6, 7, 8, 9, 11, 14};

    s.shellSort_Go(arr, n);

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], arr[i]);
    }
}
