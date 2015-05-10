#include "sqrt.cpp"
#include "gtest/gtest.h"

/*
 * int sqrt(int x)
 * */

TEST(sqrtTest, Positive01){
    Solution s;

    int x = 1;

    EXPECT_EQ(1, s.sqrt(x));
}

TEST(sqrtTest, Positive02){
    Solution s;

    int x = 10;

    EXPECT_EQ(3, s.sqrt(x));
}

TEST(sqrtTest, Positive03){
    Solution s;

    int x = 100;

    EXPECT_EQ(10, s.sqrt(x));
}

TEST(sqrtTest, Positive04){
    Solution s;

    int x = 1000;

    EXPECT_EQ(31, s.sqrt(x));
}

TEST(sqrtTest, Positive05){
    Solution s;

    int x = 10000;

    EXPECT_EQ(100, s.sqrt(x));
}

TEST(sqrtTest, Positive06){
    Solution s;

    int x = 100000;

    EXPECT_EQ(316, s.sqrt(x));
}

TEST(sqrtTest, Positive07){
    Solution s;

    int x = 1000000;

    EXPECT_EQ(1000, s.sqrt(x));
}

TEST(sqrtTest, Positive08){
    Solution s;

    int x = 10000000;

    EXPECT_EQ(3162, s.sqrt(x));
}

TEST(sqrtTest, Positive09){
    Solution s;

    int x = 100000000;

    EXPECT_EQ(10000, s.sqrt(x));
}

TEST(sqrtTest, Positive10){
    Solution s;

    int x = 1000000000;

    EXPECT_EQ(31622, s.sqrt(x));
}
