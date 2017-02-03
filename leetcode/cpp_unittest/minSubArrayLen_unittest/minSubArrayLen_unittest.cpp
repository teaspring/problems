#include "minSubArrayLen.cpp"
#include "gtest/gtest.h"

// int minSubArrayLen_01(int s, vector<int>& nums)
TEST(minSubArrayLen01_Test, Positive_01){
    Solution s;

    int arr[] = {2, 3, 1, 2, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 7;

    int expected = 2; // [4,3]
    EXPECT_EQ(expected, s.minSubArrayLen_01(sum, nums));
    nums.clear();
}

TEST(minSubArrayLen01_Test, Positive_02){
    Solution s;

    int arr[] = {2, 3, 1, 2, 2, 1, 3, 6, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 6;

    int expected = 1; // [6]
    EXPECT_EQ(expected, s.minSubArrayLen_01(sum, nums));
    nums.clear();
}

// int minSubArrayLen_02(int s, vector<int>& nums)
TEST(minSubArrayLen02_Test, Positive_01){
    Solution s;

    int arr[] = {2, 3, 1, 2, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 7;

    int expected = 2; // [4,3]
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));
    nums.clear();
}

TEST(minSubArrayLen02_Test, Positive_02){
    Solution s;

    int arr[] = {2, 3, 1, 2, 2, 1, 3, 6, 4, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int sum = 6;

    int expected = 1; // [6]
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));
    nums.clear();
}

TEST(minSubArrayLen02_Test, Positive_03){
    Solution s;

    int arr[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    int sum = 2;
    int expected = 3;
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));

    sum = 3;
    expected = 5;
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));
    nums.clear();
}

TEST(minSubArrayLen02_Test, Positive_04){
    Solution s;

    int arr[] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    int sum = 2;
    int expected = 5;
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));

    sum = 3;
    expected = 10;
    EXPECT_EQ(expected, s.minSubArrayLen_02(sum, nums));
    nums.clear();
}
