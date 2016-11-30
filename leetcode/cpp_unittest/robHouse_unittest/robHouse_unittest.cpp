#include "robHouse.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::rob(vector<int>&)
 * */
TEST(robHouseI_Test, Positive1_01){
    Solution s;

    int arr[] = {3, 4, 2, 3, 1, 2, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    int expected = 10;

    EXPECT_EQ(expected, s.rob(nums));
    nums.clear();
}

