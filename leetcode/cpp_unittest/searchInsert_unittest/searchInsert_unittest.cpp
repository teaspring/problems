#include "searchInsert.cpp"
#include "gtest/gtest.h"

/*
 * int searchInsert(int A[], int n, int x)
 * */

TEST(searchInsertTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 0;

    int expected = 0;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}

TEST(searchInsertTest, Positive02){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 3;

    int expected = 2;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}

TEST(searchInsertTest, Positive03){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 6;

    int expected = 4;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}

TEST(searchInsertTest, Positive04){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 12;

    int expected = 6;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}

TEST(searchInsertTest, Positive05){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 15;

    int expected = 8;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}

TEST(searchInsertTest, Positive06){
    Solution s;

    int arr[] = {1, 2, 4, 5, 7, 9, 13, 14, 16};

    const int n = sizeof(arr) / sizeof(int);

    int x = 17;

    int expected = 9;

    EXPECT_EQ(expected, s.searchInsert(arr, n, x));
}
