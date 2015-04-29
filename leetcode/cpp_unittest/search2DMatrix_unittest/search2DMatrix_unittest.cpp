#include "search2DMatrix.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::searchMatrix_01(vector<int>&, int x)
 *
 * int Solution::searchMatrix_02(vector<int>&, int x)
 * */

void constructMatrix_01(vector<vector<int> >& matrix){
    matrix.clear();

    int arr0[] = {1, 3, 5, 7};
    int arr1[] = {10, 11, 16, 20};
    int arr2[] = {23, 30, 34, 50};
    matrix.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    matrix.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    matrix.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));

    return;
}

void cleanMatrix(vector<vector<int> >& matrix){
    const int rows = matrix.size();
    for(int i = 0; i < rows; i++){
        matrix[i].clear();
    }
    matrix.clear();
    return;
}

/* -------------- test body --------------- */
TEST(search2DMatrixTest, Positive_01){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_TRUE(s.searchMatrix_01(matrix, 3));
    EXPECT_TRUE(s.searchMatrix_02(matrix, 3));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Positive_02){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_TRUE(s.searchMatrix_01(matrix, 11));
    EXPECT_TRUE(s.searchMatrix_02(matrix, 11));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Positive_03){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_TRUE(s.searchMatrix_01(matrix, 50));
    EXPECT_TRUE(s.searchMatrix_02(matrix, 50));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Positive_04){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_TRUE(s.searchMatrix_01(matrix, 1));
    EXPECT_TRUE(s.searchMatrix_02(matrix, 1));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Positive_05){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_TRUE(s.searchMatrix_01(matrix, 23));
    EXPECT_TRUE(s.searchMatrix_02(matrix, 23));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Negative_01){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_FALSE(s.searchMatrix_01(matrix, 4));
    EXPECT_FALSE(s.searchMatrix_02(matrix, 4));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Negative_02){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_FALSE(s.searchMatrix_01(matrix, 8));
    EXPECT_FALSE(s.searchMatrix_02(matrix, 8));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Negative_03){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_FALSE(s.searchMatrix_01(matrix, 51));
    EXPECT_FALSE(s.searchMatrix_02(matrix, 51));

    cleanMatrix(matrix);
}

TEST(search2DMatrixTest, Negative_04){
    Solution s;

    vector<vector<int> > matrix;
    constructMatrix_01(matrix);

    EXPECT_FALSE(s.searchMatrix_01(matrix, 0));
    EXPECT_FALSE(s.searchMatrix_02(matrix, 0));

    cleanMatrix(matrix);
}
