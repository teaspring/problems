#include "pow.cpp"
#include "gtest/gtest.h"

/*
 * double pow(double x, int n)
 * */

TEST(powTest, Positive01){
    Solution s;

    double x = 3;
    int n = 4;

    double expected = 81;

    EXPECT_EQ(expected, s.pow(x, n));
}

TEST(powTest, Zero01){
    Solution s;

    double x = 12;
    int n = 0;

    double expected = 1;

    EXPECT_EQ(expected, s.pow(x, n));
}

TEST(powTest, Negative01){
    Solution s;

    double x = 6;
    int n = -2;

    double expected = (double)1 / 36;

    EXPECT_EQ(expected, s.pow(x, n));
}

TEST(powTest, Negative02){
    Solution s;

    double x = 2;
    int n = -3;

    double expected = (double)1 / 8;

    EXPECT_EQ(expected, s.pow(x, n));
}
