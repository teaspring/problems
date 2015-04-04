#include "minWindow.cpp"
#include "gtest/gtest.h"

/* string Solution::minWindow(const string& S, const string& T) */

TEST(minWindowTest, Negative01){
    Solution s;

    string S("abaaba");
    string T("abc");

    string result = s.minWindow(S, T);
    EXPECT_TRUE(result.empty());
}

TEST(minWindowTest, Positive01){
    Solution s;

    string S("abdacdca");
    string T("bdcca");

    string expected("bdacdc");
    string result = s.minWindow(S, T);
    EXPECT_STREQ(expected.c_str(), result.c_str());
}


