#include "wildcardMatch.cpp"
#include "gtest/gtest.h"

/*
 * bool isMatch(const char *s, const char *p)
 * */

TEST(wildcardMatchTest, Positive01){
    Solution s;

    EXPECT_TRUE(s.isMatch("hi", "*?i"));

    EXPECT_TRUE(s.isMatch("hi", "*i"));

    EXPECT_TRUE(s.isMatch("hi", "*"));
}

TEST(wildcardMatchTest, Negative01){
    Solution s;

    EXPECT_FALSE(s.isMatch("hi", "**a"));

    EXPECT_FALSE(s.isMatch("hi", "*?a"));

    EXPECT_FALSE(s.isMatch("", "*?"));
}

TEST(wildcardMatchTest, Positive02){
    Solution s;

    EXPECT_TRUE(s.isMatch("aa", "aa"));

    EXPECT_TRUE(s.isMatch("aa", "*"));

    EXPECT_TRUE(s.isMatch("aa", "a*"));

    EXPECT_TRUE(s.isMatch("ab", "?*"));
}

TEST(wildcardMatchTest, Negative02){
    Solution s;

    EXPECT_FALSE(s.isMatch("aa", "a"));

    EXPECT_FALSE(s.isMatch("aa", "aaa"));

    EXPECT_FALSE(s.isMatch("aab", "c*a*b"));
}
