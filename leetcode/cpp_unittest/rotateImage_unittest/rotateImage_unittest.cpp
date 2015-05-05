#include "rotateImage.cpp"
#include "gtest/gtest.h"

/*
 * void rotateClockwiseQuarter(vector<vector<int> >&)
 * */

void assertMatrix(vector<vector<int> >& expected,
            vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/* ------------- test cases ------------- */
TEST(rotateImageTest, Positive01){
    Solution s;

    const int n = 3;

    int A[][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int> > matrix;
    for(int i = 0; i < n; i++){
        matrix.push_back(vector<int>(A[i], A[i] + n));
    }

    s.rotateClockwiseQuarter(matrix);

    int B[][n] = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    vector<vector<int> > expected;
    for(int i = 0; i < n; i++){
        expected.push_back(vector<int>(B[i], B[i] + n));
    }

    assertMatrix(expected, matrix);

    expected.clear();
    matrix.clear();
}

TEST(rotateImageTest, Positive02){
    Solution s;

    const int n = 4;

    int A[][n] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int> > matrix;
    for(int i = 0; i < n; i++){
        matrix.push_back(vector<int>(A[i], A[i] + n));
    }

    s.rotateClockwiseQuarter(matrix);

    int B[][n] = {
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}
    };
    vector<vector<int> > expected;
    for(int i = 0; i < n; i++){
        expected.push_back(vector<int>(B[i], B[i] + n));
    }

    assertMatrix(expected, matrix);

    expected.clear();
    matrix.clear();
}
