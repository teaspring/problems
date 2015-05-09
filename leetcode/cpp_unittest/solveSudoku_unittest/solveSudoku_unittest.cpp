#include "solveSudoku.cpp"
#include "gtest/gtest.h"

/*
 * void Solution::solveSudoku(vector<vector<char> >& board)
 * */

void assertBoard(vector<vector<char> >& expected, vector<vector<char> >& result){
    EXPECT_EQ(expected.size(), result.size());
    const int rows = expected.size();
    const int cols = expected[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/* ---------------- test body ---------------- */
TEST(solveSudokuTest, Positive01){
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

    vector<vector<char> > result;
    for(int i = 0; i < rows; i++){
        result.push_back(vector<char>(A[i], A[i] + cols));
    }

    s.solveSudoku(result);

    char B[][cols] = {
        {'7', '4', '2', '5', '8', '6', '3', '1', '9'},
        {'8', '5', '1', '9', '3', '4', '6', '7', '2'},
        {'9', '6', '3', '1', '2', '7', '8', '4', '5'},
        {'3', '9', '6', '2', '4', '5', '1', '8', '7'},
        {'5', '1', '4', '8', '7', '9', '2', '3', '6'},
        {'2', '8', '7', '3', '6', '1', '5', '9', '4'},
        {'6', '2', '9', '7', '1', '3', '4', '5', '8'},
        {'1', '7', '8', '4', '5', '2', '9', '6', '3'},
        {'4', '3', '5', '6', '9', '8', '7', '2', '1'}};

    vector<vector<char> > expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(vector<char>(B[i], B[i] + cols));
    }

    assertBoard(expected, result);
}
