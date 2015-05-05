#include "reverseInteger.cpp"
#include "gtest/gtest.h"

/*
 * int reverse(int x)
 *
 * actually, what is the correct reverse() output is not clear.
 * */

TEST(reverseIntegerTest, Positive){
    Solution s;

    EXPECT_EQ(9128123, s.reverse(3218219));
    EXPECT_EQ(1, s.reverse(10000));
    EXPECT_EQ(-12312, s.reverse(-21321));
    EXPECT_EQ(0, s.reverse(0));
}

TEST(reverseIntegerTest, Negative){
    Solution s;

    EXPECT_EQ(INT_MAX, s.reverse(INT_MAX));
    EXPECT_EQ(INT_MIN, s.reverse(INT_MIN));
    EXPECT_EQ(INT_MAX, s.reverse(INT_MAX + 1));  // ?
    EXPECT_EQ(INT_MIN, s.reverse(INT_MIN - 1));  // ?
}
