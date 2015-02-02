#include "DungeonGame.cpp"
#include "gtest/gtest.h"

// Test case: Function_Test
// Test name: Positive01
TEST(Function_Test, Positive01){
    Solution s;
    int arr1[] = {-2, -3, 3};
    int arr2[] = {-5, -10, 1};
    int arr3[] = {10, 30, -5};
    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));
    dungeon.push_back(vector<int>(arr2, arr2 + sizeof(arr2)/sizeof(int)));
    dungeon.push_back(vector<int>(arr3, arr3 + sizeof(arr3)/sizeof(int)));
    int hp = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(7, hp);
}

// Test case: Function_Test
// Test name: Positive02
TEST(Function_Test, Positive02){
    Solution s;
    int arr[][3] = {{  3, -20, 30},
                    { -3,   4,  0}};
    vector<vector<int> > dungeon;
    for(int i=0; i<2; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + sizeof(arr[i])/sizeof(int)));
    }
    int hp = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(1, hp);
}

// Test case: Function_Test
// Test name: Positive03
TEST(Function_Test, Positive03){
    Solution s;
    int arr[][3] = {{ 1, -3, 3},
                    { 0, -2, 0},
                    {-3, -3, -3}};
    vector<vector<int> > dungeon;
    for(int i=0; i<3; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + sizeof(arr[i])/sizeof(int)));
    }
    int hp = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(3, hp);
}


// Test case: Function_Test
// Test name: Positive03
TEST(Function_Test, Positive04){
    Solution s;
    int arr[][7] = {{ 0, -74, -47, -20, -23, -39, -48},
                   { 37, -30,  37, -65, -82,  28, -27},
                   {-76, -33,   7,  42,   3,  49, -93},
                   { 37, -41,  35, -16, -96, -56,  38},
                   {-52,  19, -37,  14, -65, -42,   9},
                   {  5, -26, -30, -65,  11,   5,  16},
                   {-60,   9,  36, -36,  41, -47, -86},
                   {-22,  19,  -5, -41,  -8, -96, -95}};
    vector<vector<int> > dungeon;
    for(int i=0; i<8; i++){
        dungeon.push_back(vector<int>(arr[i], arr[i] + sizeof(arr[i])/sizeof(int)));
    }
    int hp = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(30, hp);
}

// Test case: Edge_Test
// Test name: single
TEST(Edge_Test, single){
    Solution s;
    int arr1[] = {10};
    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(arr1, arr1 + sizeof(arr1)/sizeof(int)));
    int hp = s.calculateMinimumHP(dungeon);
    EXPECT_EQ(1, hp);
}
