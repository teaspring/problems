#include "interleaveString.cpp"
#include "gtest/gtest.h"

/*
 * bool isInterleave(const string& s1, const string& s2, const string& s3)
 * */

TEST(interleaveStringTest, Positive01){
    Solution s;

    string s1("abcc");
    string s2("bcd");

    string s3("abbcccd");
    EXPECT_TRUE(s.isInterleave(s1, s2, s3));

    string s4("abbccdc");
    EXPECT_TRUE(s.isInterleave(s1, s2, s4));

    string s5("abbdccc");
    EXPECT_FALSE(s.isInterleave(s1, s2, s5));

    string s6("acbcbcdc");
    EXPECT_FALSE(s.isInterleave(s1, s2, s6));
}

TEST(interleaveStringTest, Positive02){
    Solution s;

    string s1;
    string s2("b");

    string s3("b");
    EXPECT_TRUE(s.isInterleave(s1, s2, s3));
}
