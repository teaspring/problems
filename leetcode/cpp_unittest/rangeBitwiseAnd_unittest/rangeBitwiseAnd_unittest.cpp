#include "rangeBitwiseAnd.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::rangeBitwiseAnd(int m, int n)
 * */
TEST(rangeBitwiseAndTest, Positive_01){
    Solution s;

    int m = 5, n = 7;
    EXPECT_EQ(4, s.rangeBitwiseAnd(m, n));
}

TEST(rangeBitwiseAndTest, Positive_02){
    Solution s;

    int m = 5, n = 8;
    EXPECT_EQ(0, s.rangeBitwiseAnd(m, n));
}

TEST(rangeBitwiseAndTest, Positive_03){
    Solution s;

    int m = 6, n = 7;
    EXPECT_EQ(6, s.rangeBitwiseAnd(m, n));
}

TEST(rangeBitwiseAndTest, Edge_01){
    Solution s;

    int m = 1, n = 1;
    EXPECT_EQ(1, s.rangeBitwiseAnd(m, n));
}

TEST(rangeBitwiseAndTest, Edge_02){
    Solution s;

    int m = 2, n = 2;
    EXPECT_EQ(2, s.rangeBitwiseAnd(m, n));
}

