#include "countPrimes.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::countPrimes(int n)
 * */
TEST(countPrimesTest, Positive){
    Solution s;
    EXPECT_EQ(3, s.countPrimes(6));
    EXPECT_EQ(3, s.countPrimes(7));
    EXPECT_EQ(4, s.countPrimes(8));
    EXPECT_EQ(4, s.countPrimes(9));
    EXPECT_EQ(4, s.countPrimes(10));
    EXPECT_EQ(4, s.countPrimes(11));
    EXPECT_EQ(5, s.countPrimes(12));
}

