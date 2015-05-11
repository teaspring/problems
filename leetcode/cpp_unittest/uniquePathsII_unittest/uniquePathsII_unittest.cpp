#include "uniquePathsII.cpp"
#include "gtest/gtest.h"

/*
 * int uniquePathsWithObstacles(vector<vector<int> >&)
 * */

TEST(uniquePathsIITest, Positive01){
    Solution s;

    const int rows = 4, cols = 5;

    int arr[][cols] = {
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}};

    vector<vector<int> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 4;

    EXPECT_EQ(expected, s.uniquePathsWithObstacles(board));

    board.clear();
}

TEST(uniquePathsIITest, Positive02){
    Solution s;

    const int rows = 4, cols = 5;

    int arr[][cols] = {
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0}};

    vector<vector<int> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 2;

    EXPECT_EQ(expected, s.uniquePathsWithObstacles(board));

    board.clear();
}
