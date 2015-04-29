#include "spiralmatrix.cpp"
#include "gtest/gtest.h"

/*
 * vector<int> spiralOrder_1(vector<vector<int> >& matrix)
 * vector<int> spiralOrder_2(vector<vector<int> >& matrix)
 *
 * vector<vector<int> > generateMatrix(int n, int m)
 *
 * */

// helper assert method
void assertVector(const vector<int>& expected, const vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

void assertVecVec(const vector<vector<int> >& expected, const vector<vector<int> >& result){
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

/*--------------- test body ---------------*/
TEST(spiralOrder_Test, Positive01){
    Solution s;

    const int rows = 3, cols = 4;
    int arr[][cols] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12}};

    vector<vector<int> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int arrExp[] = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    const int n = sizeof(arrExp) / sizeof(int);
    vector<int> expected(arrExp, arrExp + n);

    vector<int> result1 = s.spiralOrder_1(matrix);
    assertVector(expected, result1);

    vector<int> result2 = s.spiralOrder_2(matrix);
    assertVector(expected, result2);

    matrix.clear();
    expected.clear();
    result1.clear();
    result2.clear();
}

TEST(spiralOrder_Test, Positive02){
    Solution s;

    const int rows = 2, cols = 5;
    int arr[][cols] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10}};

    vector<vector<int> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int arrExp[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    const int n = sizeof(arrExp) / sizeof(int);
    vector<int> expected(arrExp, arrExp + n);

    vector<int> result1 = s.spiralOrder_1(matrix);
    assertVector(expected, result1);

    vector<int> result2 = s.spiralOrder_2(matrix);
    assertVector(expected, result2);

    matrix.clear();
    expected.clear();
    result1.clear();
    result2.clear();
}

TEST(spiralOrder2_Test, Positive03){
    Solution s;

    const int rows = 5, cols = 2;
    int arr[][cols] = {{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};

    vector<vector<int> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int arrExp[] = {1, 2, 4, 6, 8, 10, 9, 7, 5, 3};
    const int n = sizeof(arrExp) / sizeof(int);
    vector<int> expected(arrExp, arrExp + n);

    vector<int> result1 = s.spiralOrder_1(matrix);
    assertVector(expected, result1);

    vector<int> result2 = s.spiralOrder_2(matrix);
    assertVector(expected, result2);

    matrix.clear();
    expected.clear();
    result1.clear();
    result2.clear();
}

TEST(spiralOrder_Test, Positive04){
    Solution s;

    const int rows = 1, cols = 10;
    int arr[][cols] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

    vector<vector<int> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int arrExp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int n = sizeof(arrExp) / sizeof(int);
    vector<int> expected(arrExp, arrExp + n);

    vector<int> result1 = s.spiralOrder_1(matrix);
    assertVector(expected, result1);

    vector<int> result2 = s.spiralOrder_2(matrix);
    assertVector(expected, result2);

    matrix.clear();
    expected.clear();
    result1.clear();
    result2.clear();
}

TEST(spiralOrder_Test, Positive05){
    Solution s;

    const int rows = 7, cols = 1;
    int arr[][cols] = {{1},
                       {2},
                       {3},
                       {4},
                       {5},
                       {6},
                       {7}};

    vector<vector<int> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int arrExp[] = {1, 2, 3, 4, 5, 6, 7};
    const int n = sizeof(arrExp) / sizeof(int);
    vector<int> expected(arrExp, arrExp + n);

    vector<int> result1 = s.spiralOrder_1(matrix);
    assertVector(expected, result1);

    vector<int> result2 = s.spiralOrder_2(matrix);
    assertVector(expected, result2);

    matrix.clear();
    expected.clear();
    result1.clear();
    result2.clear();
}

/* test cases of generateMatrix() */
TEST(generateMatrix_Test, Positive01){
    Solution s;

    const int rows = 4, cols = 4;
    int mat[][cols] = {{1,  2, 3, 4},
                       {12,13,14, 5},
                       {11,16,15, 6},
                       {10, 9, 8, 7}};

    vector<vector<int> > expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(vector<int>(mat[i], mat[i] + cols));
    }

    vector<vector<int> > result = s.generateMatrix(rows, cols);
    assertVecVec(expected, result);
}
