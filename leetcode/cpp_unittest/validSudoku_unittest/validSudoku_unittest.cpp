#include "validSudoku.cpp"
#include "gtest/gtest.h"

/*
 * bool isValidSudoku(vector<vector<char> >& board)
 * */

/* ---------------- test body ---------------- */
TEST(validSudokuTest, Positive01){
    Solution s;

    const int rows = 9, cols = 9;

    char A[][cols] = {
        {'7', '.', '.', '.', '.', '.', '.', '.', '9'},
        {'.', '5', '1', '.', '.', '.', '6', '7', '.'},
        {'.', '6', '.', '.', '2', '.', '.', '4', '.'},
        {'3', '9', '.', '2', '.', '5', '.', '8', '7'},
        {'.', '.', '4', '.', '.', '.', '2', '.', '.'},
        {'2', '8', '.', '3', '.', '1', '.', '9', '4'},
        {'.', '2', '.', '.', '1', '.', '.', '5', '.'},
        {'.', '7', '8', '.', '.', '.', '9', '6', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '1'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(A[i], A[i] + cols));
    }

    EXPECT_TRUE(s.isValidSudoku(board));
}

TEST(validSudokuTest, Positive02){
    Solution s;

    const int rows = 9, cols = 9;

    char A[][cols] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(A[i], A[i] + cols));
    }

    EXPECT_TRUE(s.isValidSudoku(board));
}

TEST(validSudokuTest, Negative01){
    Solution s;

    const int rows = 9, cols = 9;

    char A[][cols] = {
        {'.', '.', '.', '.', '.', '.', '5', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(A[i], A[i] + cols));
    }

    EXPECT_FALSE(s.isValidSudoku(board));
}
