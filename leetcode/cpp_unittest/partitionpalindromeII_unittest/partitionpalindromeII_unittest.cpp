/*
 * int minCut(const string& s)
 * */

#include "partitionpalindromeII.cpp"
#include "gtest/gtest.h"
#include <algorithm>

TEST(partitionpalindromeIITest, Positive01){
    Solution s;

    string str("abbaa");

    int expected = 1;
    EXPECT_EQ(expected, s.minCut(str));
}

TEST(partitionpalindromeIITest, Positive02){
    Solution s;

    string str("aaaa");

    int expected = 0;
    EXPECT_EQ(expected, s.minCut(str));
}

TEST(partitionpalindromeIITest, Positive03){
    Solution s;

    string str("aaaaaaaaad");

    int expected = 1;
    EXPECT_EQ(expected, s.minCut(str));
}

TEST(partitionpalindromeIITest, Positive04){
    Solution s;

    string str("baaaaaaaac");

    int expected = 2;
    EXPECT_EQ(expected, s.minCut(str));
}
