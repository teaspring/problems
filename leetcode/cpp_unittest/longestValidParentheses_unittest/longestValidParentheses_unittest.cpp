#include "longestValidParentheses.cpp"
#include "gtest/gtest.h"

/* inat Solution::longestValidParentheses_01(const string&) */

TEST(longestValidParenthesesTest, Positive01){
    Solution s;

    string str("()(())");
    const int expected = 6;

    EXPECT_EQ(expected, s.longestValidParentheses_01(str));
    EXPECT_EQ(expected, s.longestValidParentheses_02(str));
    EXPECT_EQ(expected, s.longestValidParentheses_03(str));
}

TEST(longestValidParenthesesTest, Positive02){
    Solution s;

    string str("((())()(");
    const int expected = 6;

    EXPECT_EQ(expected, s.longestValidParentheses_01(str));
    EXPECT_EQ(expected, s.longestValidParentheses_02(str));
    EXPECT_EQ(expected, s.longestValidParentheses_03(str));
}

TEST(longestValidParenthesesTest, Positive03){
    Solution s;

    string str("()())(()()))");
    const int expected = 6;

    EXPECT_EQ(expected, s.longestValidParentheses_01(str));
    EXPECT_EQ(expected, s.longestValidParentheses_02(str));
    EXPECT_EQ(expected, s.longestValidParentheses_03(str));
}
