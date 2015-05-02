#include "removeKdigits.cpp"
#include "gtest/gtest.h"

/*
 * string removechar_01(const string& str, int k)
 * void   removechar_02(string& str, int k)
 * string removechar_03(const string& str, int k)
 * */

TEST(removeKdigits1_Test, Positive01){
    Solution s;

    string str("13243221");
    int k = 5;

    string expected("121");

    string result1 = s.removechar_01(str, k);
    EXPECT_STREQ(expected.c_str(), result1.c_str());
}

TEST(removeKdigits2_Test, Positive01){
    Solution s;

    string str("13243221");
    int k = 5;

    string expected("121");

    s.removechar_02(str, k);
    EXPECT_STREQ(expected.c_str(), str.c_str());
}

TEST(removeKdigits3_Test, Positive01){
    Solution s;

    string str("13243221");
    int k = 5;

    string expected("121");

    string result3 = s.removechar_03(str, k);
    EXPECT_STREQ(expected.c_str(), result3.c_str());
}

TEST(removeKdigits3_Test, Positive02){
    Solution s;

    string str("14532431");
    int k = 4;

    string expected("1231");

    string result3 = s.removechar_03(str, k);
    EXPECT_STREQ(expected.c_str(), result3.c_str());
}
