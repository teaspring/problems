#include "numIslands.cpp"
#include "gtest/gtest.h"

/*
 * int numIslands(vector<vector<char> >&)
 * */
TEST(numIslandsTest, Positive01){
    char arr[] = {'1','0','1', '1', '1', '0', '1', '1'};
    vector<vector<char> > grid;
    grid.push_back(vector<char>(arr, arr + sizeof(arr)/sizeof(char)));

    Solution s;
    EXPECT_EQ(3, s.numIslands(grid));

    grid.clear();
}

TEST(numIslandsTest, Positive02){
    const int rows = 4, cols = 4;
    char arr[][cols] = {
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'},
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    Solution s;
    EXPECT_EQ(8, s.numIslands(matrix));

    matrix.clear();
}

TEST(numIslandsTest, Positive03){
    const int rows = 3, cols = 5;
    char arr[][cols] = {
        {'1', '0', '1', '1', '1'},
        {'0', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    Solution s;
    EXPECT_EQ(3, s.numIslands(matrix));

    matrix.clear();
}

TEST(numIslandsTest, Edge01){
    const int rows = 4, cols = 3;
    char arr[][cols] = {
        {'1', '0', '1'},
        {'1', '0', '1'},
        {'1', '0', '1'},
        {'1', '1', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    Solution s;
    EXPECT_EQ(1, s.numIslands(matrix));

    matrix.clear();
}

TEST(numIslandsTest, Edge02){
    const int rows = 3, cols = 4;
    char arr[][cols] = {
        {'1', '1', '1', '1'},
        {'0', '0', '0', '1'},
        {'1', '1', '1', '1'}};

    vector<vector<char> > matrix;
    for(int i = 0; i < rows; i++){
        matrix.push_back(vector<char>(arr[i], arr[i] + cols));
    }

    Solution s;
    EXPECT_EQ(1, s.numIslands(matrix));

    matrix.clear();
}

TEST(numIslandsTest, Negative01){
    vector<vector<char> > matrix;

    Solution s;
    EXPECT_EQ(0, s.numIslands(matrix));

    matrix.clear();
}
