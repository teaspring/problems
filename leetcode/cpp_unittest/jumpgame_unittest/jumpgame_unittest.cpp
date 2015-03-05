#include "jumpgameII.cpp"
#include "gtest/gtest.h"

// Test case: jumpgameTest
// Test name: negative
TEST(jumpgameTest, Negative){
    Solution s;
    int arr1[] = {1, 1, 0, 0};
    EXPECT_EQ(-1, s.jump_2(arr1, sizeof(arr1)/sizeof(int)));
    int arr2[] = {0, 1, 1};
    EXPECT_EQ(-1, s.jump_2(arr2, sizeof(arr2)/sizeof(int)));
}

// Test case: jumpgameTest
// Test name: Zero
TEST(jumpgameTest, Zero){
    Solution s;
    int arr1[] = {0};
    EXPECT_EQ(0, s.jump_2(arr1, sizeof(arr1)/sizeof(int)));
}

// Test case: jumpgameTest
// Test name: Positive
TEST(jumpgameTest, Positive){
    Solution s;
    int arr1[] = {1, 2};
    EXPECT_EQ(1, s.jump_2(arr1, sizeof(arr1)/sizeof(int)));
    int arr2[] = {2, 3, 1, 1, 4};
    EXPECT_EQ(2, s.jump_2(arr2, sizeof(arr2)/sizeof(int)));
    int arr3[] = {3, 4, 3, 2, 5, 4, 3};
    EXPECT_EQ(3, s.jump_2(arr3, sizeof(arr3)/sizeof(int)));
    int arr4[] = {5, 4, 0, 1, 3, 6, 8, 0, 9, 4, 9, 1, 8, 7, 4, 8};
    EXPECT_EQ(3, s.jump_2(arr4, sizeof(arr4)/sizeof(int)));
}
