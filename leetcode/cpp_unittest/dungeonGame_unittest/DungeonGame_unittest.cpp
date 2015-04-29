#include "DungeonGame.cpp"
#include "gtest/gtest.h"

TEST(Function_Test, Positive01){
    Solution s;

    const int rows = 3, cols = 3;
    int arr[][cols] = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};

    vector<vector<int> > dungeon;
    for(int i = 0; i < rows; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 7;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}

TEST(Function_Test, Positive02){
    Solution s;

    const int rows = 2, cols = 3;
    int arr[][3] = {
        {  3, -20, 30},
        { -3,   4,  0}};

    vector<vector<int> > dungeon;
    for(int i = 0; i < rows; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 1;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}

TEST(Function_Test, Positive03){
    Solution s;

    const int rows = 3, cols = 3;
    int arr[][cols] = {
        { 1, -3, 3},
        { 0, -2, 0},
        {-3, -3, -3}};

    vector<vector<int> > dungeon;
    for(int i = 0; i < rows; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 3;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}


TEST(Function_Test, Positive04){
    Solution s;

    const int rows = 8, cols = 7;
    int arr[][cols] = {
        { 0, -74, -47, -20, -23, -39, -48},
        { 37, -30,  37, -65, -82,  28, -27},
        {-76, -33,   7,  42,   3,  49, -93},
        { 37, -41,  35, -16, -96, -56,  38},
        {-52,  19, -37,  14, -65, -42,   9},
        {  5, -26, -30, -65,  11,   5,  16},
        {-60,   9,  36, -36,  41, -47, -86},
        {-22,  19,  -5, -41,  -8, -96, -95}};

    vector<vector<int> > dungeon;
    for(int i = 0; i < rows; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 30;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}

TEST(Function_Test, Positive05){
    Solution s;

    const int rows = 3, cols = 3;
    int arr[][cols] = {
        { 1,  2,  1},
        {-2, -3, -3},
        { 3,  2, -2}};

    vector<vector<int> > dungeon;
    for(int i = 0; i < rows; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + cols));
    }

    int expected = 1;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}

TEST(Edge_Test, single){
    Solution s;
    int arr1[] = {10};

    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));

    int expected = 1;
    int result = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(expected, result);

    dungeon.clear();
}
