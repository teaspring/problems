#include "validPalindrome.cpp"
#include "gtest/gtest.h"

/*
 * bool isPalindrome(const string&)
 * */

TEST(validPalindromeTest, Positive01){
    Solution s;

    string str("ab0adccda0ba");

    EXPECT_TRUE(s.isPalindrome(str));
}

TEST(validPalindromeTest, Negative01){
    Solution s;

    string str("ab0adc1fe1cda0ba");

    EXPECT_FALSE(s.isPalindrome(str));
}
