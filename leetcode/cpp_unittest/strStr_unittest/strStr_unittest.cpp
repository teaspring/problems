#include "strStr.cpp"
#include "gtest/gtest.h"

/* char* Solution::strStr(char *str, char *pattern) */

TEST(strStrTest, Negative01){
    Solution s;

    const char *str = "abaaba";
    const char *pattern = "ababa";

    const char *expected = NULL;
    EXPECT_EQ(expected, s.strStr(str, pattern));
}

TEST(strStrTest, Negative02){
    Solution s;

    const char *str = "abaaba";
    const char *pattern = "";

    const char *expected = "abaaba";
    EXPECT_EQ(expected, s.strStr(str, pattern));
}

TEST(strStrTest, Negative03){
    Solution s;

    const char *str = "abaa";
    const char *pattern = "ababa";

    const char *expected = NULL;
    EXPECT_EQ(expected, s.strStr(str, pattern));
}

TEST(strStrTest, Positive01){
    Solution s;

    const char *str = "abbaabbaabab";
    const char *pattern = "abab";

    const char *expected = "abab";
    EXPECT_STREQ(expected, s.strStr(str, pattern));
}

TEST(strStrTest, Positive02){
    Solution s;

    const char *str = "aabaaaabaaaaa";
    const char *pattern = "aaaaa";

    const char *expected = "aaaaa";
    EXPECT_STREQ(expected, s.strStr(str, pattern));
}
