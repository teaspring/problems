#include "find1stmissingpositive.cpp"
#include "gtest/gtest.h"

/* int Solution::findMissingPositive(int A[], int n) */

TEST(find1stmissingpositiveTest, Positive01){
    Solution s;

    int arr[] = {3, 2, 4, 6, 5, 1, 8};
    int n = sizeof(arr) / sizeof(int);

    int expected = 7;

    EXPECT_EQ(expected, s.findMissingPositive(arr, n));
}

TEST(find1stmissingpositiveTest, Positive02){
    Solution s;

    int arr[] = {3, 2, 4, 6, 5, 1, 7};
    int n = sizeof(arr) / sizeof(int);

    int expected = 8;

    EXPECT_EQ(expected, s.findMissingPositive(arr, n));
}
