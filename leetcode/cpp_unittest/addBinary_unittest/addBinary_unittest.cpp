#include "addBinary.cpp"
#include "gtest/gtest.h"

/* string Solution::addBinary(string, string) */

TEST(addBinaryTest, Positive01){
    Solution s;

    string sa("1001");
    string sb("100");

    string expected("1101");
    EXPECT_STREQ(expected.c_str(), s.addBinary(sa, sb).c_str());
}

TEST(addBinaryTest, Positive02){
    Solution s;

    string sa("11101101");
    string sb("11110111");

    string expected("111100100");
    EXPECT_STREQ(expected.c_str(), s.addBinary(sa, sb).c_str());
}
