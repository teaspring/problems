#include "minPathSums.cpp"
#include "gtest/gtest.h"

/*
 * int minPathSum(vector<vector<int> >&)
 * */

TEST(minPathSums_Test, Positive01){
    Solution s;

    const int rows = 3, cols = 3;
    int arr[][cols] = {
        {1, 2, 2},
        {3, 1, 0},
        {2, 3, 1}};

    vector<vector<int> > grid;
    for(int i = 0; i < rows; i++){
        grid.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 5;
    EXPECT_EQ(expected, s.minPathSum(grid));

    grid.clear();
}

