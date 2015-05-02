#include "longestConsecutive.cpp"
#include "gtest/gtest.h"

/*
 * int longestConsecutive_01(vector<int>&)
 * int longestConsecutive_02(vector<int>&)
 * */

TEST(longestConsecutive01_Test, Positive01){
    Solution s;

    int arr[] = {100, 4, 1, 3, 99, 5};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 3;

    EXPECT_EQ(expected, s.longestConsecutive_01(num));

    num.clear();
}

TEST(longestConsecutive01_Test, Positive02){
    Solution s;

    int arr[] = {1, 3, -1, 5, 7, -3};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 1;

    EXPECT_EQ(expected, s.longestConsecutive_01(num));

    num.clear();
}

TEST(longestConsecutive01_Test, Positive03){
    Solution s;

    int arr[] = {100, 4, -11, 3, 99, 6, 88, 2};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 3;

    EXPECT_EQ(expected, s.longestConsecutive_01(num));

    num.clear();
}

TEST(longestConsecutive02_Test, Positive01){
    Solution s;

    int arr[] = {100, 4, 1, 3, 99, 5};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 3;

    EXPECT_EQ(expected, s.longestConsecutive_02(num));

    num.clear();
}

TEST(longestConsecutive02_Test, Positive02){
    Solution s;

    int arr[] = {1, 3, -1, 5, 7, -3};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 1;

    EXPECT_EQ(expected, s.longestConsecutive_02(num));

    num.clear();
}

TEST(longestConsecutive02_Test, Positive03){
    Solution s;

    int arr[] = {100, 4, -11, 3, 99, 6, 88, 2};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));

    int expected = 3;

    EXPECT_EQ(expected, s.longestConsecutive_02(num));

    num.clear();
}

