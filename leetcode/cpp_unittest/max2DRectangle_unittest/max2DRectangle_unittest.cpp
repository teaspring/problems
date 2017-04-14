#include "max2DRectangle.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::maximumRectangle(vector<vector<char> >&)
 *
 * int Solution::largestRectangleInArray(vector<int>&)
 * */

TEST(largestRectangleInArrayTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 2, 3, 2};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 8;
    EXPECT_EQ(expected, s.largestRectangleInArray(heights));

    heights.clear();
}

TEST(largestRectangleInArrayTest, Positive02){
    Solution s;

    int arr[] = {1, 2, 1, 4, 3};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 6;
    EXPECT_EQ(expected, s.largestRectangleInArray(heights));

    heights.clear();
}

TEST(largestRectangleInArrayTest, Positive03){
    Solution s;

    int arr[] = {1, 2, 2, 3, 2, 2, 1, 2};
    vector<int> heights(arr, arr + sizeof(arr)/sizeof(int));

    int expected = 10;
    EXPECT_EQ(expected, s.largestRectangleInArray(heights));

    heights.clear();
}

TEST(maximumRectangleTest, Positive01){
    Solution s;

    const int rows = 3, cols = 5;
    char arr[][cols] = {
        {'1', '0', '1', '1', '1'},
        {'0', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    int expected = 6;
    EXPECT_EQ(expected, s.maximumRectangle(matrix));

    matrix.clear();
}

TEST(maximumRectangleTest, Negative01){
    Solution s;

    const int rows = 2, cols = 2;
    char arr[][cols] = {
        {'1', '0'},
        {'0', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    int expected = 1;
    EXPECT_EQ(expected, s.maximumRectangle(matrix));

    matrix.clear();
}
