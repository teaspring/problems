#include "max2DRectangle.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::maximumRectangle(vector<vector<char> >&)
 *
 * int Solution::largestRectangleArea(vector<int>&)
 * */

TEST(largestRectangleAreaTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 2, 3, 2};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 8;
    EXPECT_EQ(expected, s.largestRectangleArea(heights));
}

TEST(largestRectangleAreaTest, Positive02){
    Solution s;

    int arr[] = {1, 2, 1, 4, 3};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 6;
    EXPECT_EQ(expected, s.largestRectangleArea(heights));
}

TEST(largestRectangleAreaTest, Positive03){
    Solution s;

    int arr[] = {1, 2, 2, 3, 2, 2, 1, 2};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 10;
    EXPECT_EQ(expected, s.largestRectangleArea(heights));
}

TEST(maximumRectangleTest, Positive01){
    Solution s;

    char arr[][5] = {{'1', '0', '1', '1', '1'},
                     {'0', '1', '1', '1', '0'},
                     {'1', '0', '1', '1', '1'}};
    vector<vector<char> > matrix;
    for(int i = 0; i < 3; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + 5));
    }

    int expected = 6;
    EXPECT_EQ(expected, s.maximumRectangle(matrix));
}

TEST(maximumRectangleTest, Negative01){
    Solution s;

    char arr[][2] = {{'1', '0'},
                     {'0', '1'}};
    vector<vector<char> > matrix;
    for(int i = 0; i < 2; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + 2));
    }

    int expected = 1;
    EXPECT_EQ(expected, s.maximumRectangle(matrix));
}
