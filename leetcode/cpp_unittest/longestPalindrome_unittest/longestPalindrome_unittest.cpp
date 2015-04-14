#include "longestPalindrome.cpp"
#include "gtest/gtest.h"

/*
 * string Solution::maxpalindrome(const string&)
 * string Solution::Manache(const string& S)
 * */

TEST(maxpalindromeTest, Positive01){
    Solution s;

    const string str("dbdogodcde");;
    string expected("dogod");

    string result = s.maxpalindrome(str);
    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(maxpalindromeTest, Positive02){
    Solution s;

    const string str("dbdogodcggddggsgsdghhsdfsdfe");;
    string expected("ggddgg");

    string result = s.maxpalindrome(str);
    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(ManacherTest, Positive01){
    Solution s;

    const string str("dbdogodcde");;
    string expected("dogod");

    string result = s.Manacher(str);
    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(ManacherTest, Positive02){
    Solution s;

    const string str("dbdogodcggddggsgsdghhsdfsdfe");;
    string expected("ggddgg");

    string result = s.Manacher(str);
    EXPECT_STREQ(expected.c_str(), result.c_str());
}
