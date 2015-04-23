#include "maxdistance.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::maxDistance(int *A, int n, int& left)
 *
 * */

TEST(maxdistanceTest, Positive01){
    Solution s;

    int arr[] = {1, 4, 3, 5, 2, 7, 5, 4};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 7;
    int left = 0;
    EXPECT_EQ(expected, s.maxDistance(arr, n, left));
}

TEST(maxdistanceTest, Positive02){
    Solution s;

    int arr[] = {7, 1, 3, 4, 5, 6};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;
    int left = 0;
    EXPECT_EQ(expected, s.maxDistance(arr, n, left));
}

TEST(maxdistanceTest, Negative01){
    Solution s;

    int arr[] = {6, 5, 4, 3, 2, 1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 0;
    int left = 0;
    EXPECT_EQ(expected, s.maxDistance(arr, n, left));
}
