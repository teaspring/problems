#include "scrambleString.cpp"
#include "gtest/gtest.h"

/*
 * bool isScramble(string s1, string s2)
 * */

TEST(scrambleStringTest, Positive01){
    Solution s;

    string s1("great");
    string s2("rgeta");

    EXPECT_TRUE(s.isScramble(s1, s2));
}

TEST(scrambleStringTest, Negative01){
    Solution s;

    string s1("great");
    string s2("trage");

    EXPECT_FALSE(s.isScramble(s1, s2));
}
