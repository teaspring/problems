#include "setZeroes.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::setZeroes(vector<vector<int> >&)
 * */

/* facilitate method */
void assertMatrix(const vector<vector<int> >& expected, const vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();
    const int m = expected[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/* ------------------- test body ------------------ */
TEST(setZeroes_Test, Positive01){
    Solution s;

    const int rows = 4, cols = 5;
    int mat[][cols] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1}};

    vector<vector<int> > grid;
    for(int i = 0; i < rows; i++){
        grid.push_back(vector<int>(mat[i], mat[i] + cols));
    }

    int final[][cols] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0}
    };

    vector<vector<int> > expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(vector<int>(final[i], final[i] + cols));
    }

    s.setZeroes(grid);
    assertMatrix(expected, grid);

    grid.clear();
    expected.clear();
}
