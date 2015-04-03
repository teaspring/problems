#include "maxContainer.cpp"
#include "gtest/gtest.h"

/* int Solution::maxWater(vector<int>&) */

TEST(maxContainerTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 1};
    vector<int> height(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 2;
    EXPECT_EQ(expected, s.maxWater(height));
}

TEST(maxContainerTest, Positive02){
    Solution s;

    int arr[] = {1, 2, 2, 4, 3, 1};
    vector<int> height(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 6;
    EXPECT_EQ(expected, s.maxWater(height));
}

TEST(maxContainerTest, Positive03){
    Solution s;

    int arr[] = {1, 2, 2, 5, 6, 5};
    vector<int> height(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 10;
    EXPECT_EQ(expected, s.maxWater(height));
}
