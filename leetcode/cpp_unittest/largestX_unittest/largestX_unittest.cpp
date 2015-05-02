#include "largestX.cpp"
#include "gtest/gtest.h"

/*
 * int solve(const vector<vector<int> >& board)
 * */

TEST(largestXTest, Positive01){
    Solution s;

    const int rows = 7, cols = 7;
    char arr[][cols] = {
        {'1', '0', '1', '1', '1', '0', '1'},
        {'0', '1', '0', '1', '1', '1', '0'},
        {'1', '0', '1', '0', '1', '0', '1'},
        {'1', '1', '1', '1', '0', '1', '1'},
        {'1', '1', '1', '0', '1', '1', '0'},
        {'1', '0', '1', '1', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '0', '1'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    int expected = 2;
    EXPECT_EQ(expected, s.solve(board));

    for(int i = 0; i < rows; i++){
        board[i].clear();
    }
    board.clear();
}

TEST(largestXTest, Positive02){
    Solution s;

    const int rows = 7, cols = 7;
    char arr[][cols] = {
        {'1', '0', '0', '0', '0', '0', '1'},
        {'0', '1', '0', '0', '0', '1', '0'},
        {'1', '0', '1', '0', '1', '0', '1'},
        {'0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '1', '1', '0'},
        {'0', '1', '0', '0', '0', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '1'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    int expected = 3;
    EXPECT_EQ(expected, s.solve(board));

    for(int i = 0; i < rows; i++){
        board[i].clear();
    }
    board.clear();
}
