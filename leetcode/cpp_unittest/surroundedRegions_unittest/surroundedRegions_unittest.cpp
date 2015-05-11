#include "surroundedRegions.cpp"
#include "gtest/gtest.h"

/*
 * void solve(vector<vector<char> >& board)
 * */

void assertMatrix(vector<vector<char> >& expected, vector<vector<char> >& result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();

    EXPECT_EQ(expected[0].size(), result[0].size());
    const int m = expected[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/* ------------------ test body -------------- */

/*
 *  x x x
 *  x 0 x
 *  x x x
 * */
TEST(surroundedRegionsTest, Positive01){
    Solution s;

    const int rows = 3, cols = 3;

    char A[][cols] = {
        {'x', 'x', 'x'},
        {'x', '0', 'x'},
        {'x', 'x', 'x'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(A[i], A[i] + cols));
    }

    s.solve(board);  // board turns to result

    char B[][cols] = {
        {'x', 'x', 'x'},
        {'x', '@', 'x'},
        {'x', 'x', 'x'}};

    vector<vector<char> > expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(vector<char>(B[i], B[i] + cols));
    }

    assertMatrix(expected, board);

    expected.clear();
    board.clear();
}

/*
 * x x x 0
 * x 0 0 x
 * x 0 x 0
 * x x 0 x
 * */
TEST(surroundedRegionsTest, Positive02){
    Solution s;

    const int rows = 5, cols = 5;

    char A[][cols] = {
        {'x', 'x', 'x', '0', 'x'},
        {'x', '0', '0', 'x', '0'},
        {'x', '0', 'x', '0', 'x'},
        {'x', 'x', '0', 'x', '0'},
        {'0', 'x', 'x', '0', 'x'}};

    vector<vector<char> > board;
    for(int i = 0; i < rows; i++){
        board.push_back(vector<char>(A[i], A[i] + cols));
    }

    s.solve(board);  // board turns to result

    char B[][cols] = {
        {'x', 'x', 'x', '0', 'x'},
        {'x', '@', '@', 'x', '0'},
        {'x', '@', 'x', '@', 'x'},
        {'x', 'x', '@', 'x', '0'},
        {'0', 'x', 'x', '0', 'x'}};

    vector<vector<char> > expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(vector<char>(B[i], B[i] + cols));
    }

    assertMatrix(expected, board);

    expected.clear();
    board.clear();
}
