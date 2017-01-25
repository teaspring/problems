#include "minSubArrayLen.cpp"
#include "gtest/gtest.h"

/*
 * int minSubArrayLen_01(int s, vector<int>& nums)
 * */
TEST(minSubArrayLenTest, Positive1_01){
    Solution s;

    int arr[] = {2, 3, 1, 2, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 7;

    int expected = 2; // [4,3]
    EXPECT_EQ(expected, s.minSubArrayLen_01(sum, nums));
    nums.clear();
}

TEST(minSubArrayLenTest, Positive1_02){
    Solution s;

    int arr[] = {2, 3, 1, 2, 2, 1, 3, 6, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 6;

    int expected = 1; // [6]
    EXPECT_EQ(expected, s.minSubArrayLen_01(sum, nums));
    nums.clear();
}
