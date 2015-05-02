#include "lengthOfLastWord.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::lengthOfLastWord(vector<int>&)
 * */

TEST(lengthOfLastWordTest, Positive01){
    Solution s;

    const char* cstr("aAsd asDu*k SADL 2d0");

    int expected = 3;
    EXPECT_EQ(expected, s.lengthOfLastWord(cstr));
}

TEST(lengthOfLastWordTest, Positive02){
    Solution s;

    const char* cstr(" 1 adSL  ");

    int expected = 4;
    EXPECT_EQ(expected, s.lengthOfLastWord(cstr));
}
