#include "shortestPalindrome.cpp"
#include "gtest/gtest.h"

/* char* Solution::shortestPalindrome(string) */

TEST(shortestPalindromeTest, Positive01){
    Solution s;

    const char *str = "abcda";
    const char *expected = "adcbabcda";
    EXPECT_EQ(expected, s.shortestPalindrome(str));
}

TEST(shortestPalindromeTest, Positive02){
    Solution s;

    const char *str = "adabd";
    const char *expected = "dbadabd";
    EXPECT_EQ(expected, s.shortestPalindrome(str));
}

TEST(shortestPalindromeTest, Edge01){
    Solution s;

    const char *str = "aa";
    const char *expected = "aa";
    EXPECT_EQ(expected, s.shortestPalindrome(str));
}

TEST(shortestPalindromeTest, Edge02){
    Solution s;

    const char *str = "ab";
    const char *expected = "bab";
    EXPECT_EQ(expected, s.shortestPalindrome(str));
}

TEST(shortestPalindromeTest, Edge03){
    Solution s;

    const char *str = "aaa";
    const char *expected = "aaa";
    EXPECT_EQ(expected, s.shortestPalindrome(str));
}
