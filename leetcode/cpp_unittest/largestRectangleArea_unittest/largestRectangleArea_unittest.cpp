#include "largestRectangleArea.cpp"
#include "gtest/gtest.h"

/*
 * int largestRectangleArea_1(vector<int>&)
 * int largestRectangleArea_2(vector<int>&)
 * */

TEST(largestRectangleAreaTest, Positive01){
    Solution s;

    int arr[] = {2, 1, 3, 1, 4, 2};
    vector<int> height(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 6;
    EXPECT_EQ(expected, s.largestRectangleArea_1(height));
    EXPECT_EQ(expected, s.largestRectangleArea_2(height));
}

TEST(largestRectangleAreaTest, Positive02){
    Solution s;

    int arr[] = {2, 1, 5, 6, 2, 3};
    vector<int> height(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 10;
    EXPECT_EQ(expected, s.largestRectangleArea_1(height));
    EXPECT_EQ(expected, s.largestRectangleArea_2(height));
}

TEST(largestRectangleAreaTest, Positive03){
    Solution s;

    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11};
    vector<int> height(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 11;
    EXPECT_EQ(expected, s.largestRectangleArea_1(height));
    EXPECT_EQ(expected, s.largestRectangleArea_2(height));
}
