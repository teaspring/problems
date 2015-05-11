#include "trapWater.cpp"
#include "gtest/gtest.h"

/*
 * int trapWater(int[] A, int n)
 * */

TEST(trapWaterTest, Positive01){
    Solution s;

    int arr[]     = {1, 3, 2, 4, 1, 5};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 4;

    EXPECT_EQ(expected, s.trapWater(arr, n));
}

TEST(trapWaterTest, Positive02){
    Solution s;

    int arr[]     = {1, 2, 3, 4, 1, 5, 2, 1};
    const int n = sizeof(arr) / sizeof(int);

    int expected = 3;

    EXPECT_EQ(expected, s.trapWater(arr, n));
}
