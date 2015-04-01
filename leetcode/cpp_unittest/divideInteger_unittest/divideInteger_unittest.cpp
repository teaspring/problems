#include "divideInteger.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::divide_01(int, int)
 *
 * int Solution::divide_02(int, int)
 * */

TEST(divide_01_Test, Positive01){
    Solution s;

    EXPECT_EQ(7, s.divide_01(53, 7));
}

TEST(divide_01_Test, Positive02){
    Solution s;

    EXPECT_EQ(14, s.divide_01(154, 11));
}

TEST(divide_02_Test, Positive01){
    Solution s;

    EXPECT_EQ(7, s.divide_02(53, 7));
}

TEST(divide_02_Test, Positive02){
    Solution s;

    EXPECT_EQ(14, s.divide_02(154, 11));
}
