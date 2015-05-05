#include "reverseWords.cpp"
#include "gtest/gtest.h"

/*
 * void reverseWords(string&)
 * */

TEST(reverseWordsTest, Positive01){
    Solution s;

    string str("   blue    hell  sky   xyz  ");
    s.reverseWords(str);

    string expected("xyz sky hell blue");

    EXPECT_STREQ(expected.c_str(), str.c_str());
}
