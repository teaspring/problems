#include "multiplyStrings.cpp"
#include "gtest/gtest.h"

/*
 * string multiplyStrings(string& str1, string& str2)
 * */

TEST(multiplyStringsTest, Positive01){
    Solution s;

    string str1("12");
    string str2("9");

    string expected = "108";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}

TEST(multiplyStringsTest, Positive02){
    Solution s;

    string str1("15");
    string str2("15");

    string expected = "225";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}

TEST(multiplyStringsTest, Positive03){
    Solution s;

    string str1("101");
    string str2("1");

    string expected = "101";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}

TEST(multiplyStringsTest, Positive04){
    Solution s;

    string str1("1");
    string str2("101");

    string expected = "101";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}

TEST(multiplyStringsTest, Zero01){
    Solution s;

    string str1("101");
    string str2("0");

    string expected = "0";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}

TEST(multiplyStringsTest, Zero02){
    Solution s;

    string str1("0");
    string str2("100");

    string expected = "0";

    EXPECT_STREQ(expected.c_str(), s.multiply(str1, str2).c_str());
}
