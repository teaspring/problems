#include "distinctSubsequences.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::numDistinct_01(const string& S, const string& T)
 *
 * int Solution::numDistinct_02(const string& S, const string& T)
 * */

TEST(numDistinct_01_Test, Positive01){
    Solution s;

    string S("rabbbit");
    string T("rabit");

    int expected = 3;
    EXPECT_EQ(expected, s.numDistinct_01(S, T));
}

TEST(numDistinct_01_Test, Negative01){
    Solution s;

    string S("ABCDE");
    string T("AEC");

    int expected = 0;
    EXPECT_EQ(expected, s.numDistinct_01(S, T));
}

TEST(numDistinct_02_Test, Positive01){
    Solution s;

    string S("rabbbit");
    string T("rabit");

    int expected = 3;
    EXPECT_EQ(expected, s.numDistinct_02(S, T));
}

TEST(numDistinct_02_Test, Negative01){
    Solution s;

    string S("ABCDE");
    string T("AEC");

    int expected = 0;
    EXPECT_EQ(expected, s.numDistinct_02(S, T));
}
