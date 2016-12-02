#include "robHouse.cpp"
#include "gtest/gtest.h"

/* int Solution::rob(vector<int>&) */
TEST(robHouseI_Test, Positive1){
    Solution s;

    int arr[] = {3, 4, 2, 3, 1, 2, 3};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(10, s.rob(nums));
    nums.clear();
}

TEST(robHouseI_Test, Positive2){
    Solution s;

    int arr[] = {1, 3, 2, 1, 1, 3, 4, 2, 2};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(10, s.rob(nums));
    nums.clear();
}

TEST(robHouseI_Test, Positive3){
    Solution s;

    int arr[] = {1, 3, 1, 2, 5};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(8, s.rob(nums));
    nums.clear();
}

TEST(robHouseI_Test, Positive4){
    Solution s;

    int arr[] = {1, 1, 10};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(11, s.rob(nums));
    nums.clear();
}

TEST(robHouseI_Test, Positive5){
    Solution s;

    int arr[] = {1, 1, 10, 1};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(11, s.rob(nums));
    nums.clear();
}

TEST(robHouseI_Test, Edge1){
    Solution s;

    int arr[] = {1};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(1, s.rob(nums));
    nums.clear();
}

/* int Solution::robII(vector<int>&) */
TEST(robHouseII_Test, Positive1){
    Solution s;

    int arr[] = {1, 1, 10};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(10, s.robII(nums));
    nums.clear();
}

TEST(robHouseII_Test, Positive2){
    Solution s;

    int arr[] = {1, 1, 10, 1};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    EXPECT_EQ(11, s.robII(nums));
    nums.clear();
}
