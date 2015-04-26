#include "maxInRange.cpp"
#include "gtest/gtest.h"

/*
 * int maxInRange_1(int *A, int n, int begin, int end)
 *
 * */

TEST(maxInRangeTest, Positive01){
    Solution s;

    int arr[] = {1, 4, 3, 6, 2, 7, 5, 4, 2, 3, 8, 1, 5};
    const int n = sizeof(arr) / sizeof(int);

    EXPECT_EQ(arr[3], s.maxInRange_1(arr, n, 1, 3));
    EXPECT_EQ(arr[1], s.maxInRange_1(arr, n, 0, 2));
    EXPECT_EQ(arr[5], s.maxInRange_1(arr, n, 3, 6));
    EXPECT_EQ(arr[9], s.maxInRange_1(arr, n, 8, 9));
}

