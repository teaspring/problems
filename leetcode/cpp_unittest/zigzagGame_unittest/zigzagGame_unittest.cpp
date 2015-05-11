#include "zigzagGame.cpp"
#include "gtest/gtest.h"

/*
 * string zigzag(const string &str, int rows)
 * */

TEST(zigzag_Test, Positive01){
    Solution s;

    string str("paypalistring");
    int rows = 3;

    string result = s.zigzag(str, rows);

    string expected("patgaplsrnyii");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}
