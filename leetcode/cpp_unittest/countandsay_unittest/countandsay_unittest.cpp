#include "countandsay.cpp"
#include "gtest/gtest.h"

/* string Solution::countAndSay(int) */

// Test case: countandsayTest
// Test name: Positive
TEST(countandsayTest, Positive){
    Solution s;

    EXPECT_EQ(string("1"), s.countAndSay(1));
    EXPECT_EQ(string("11"), s.countAndSay(2));
    EXPECT_EQ(string("21"), s.countAndSay(3));
    EXPECT_EQ(string("1211"), s.countAndSay(4));
    EXPECT_EQ(string("111221"), s.countAndSay(5));
    EXPECT_EQ(string("312211"), s.countAndSay(6));
    EXPECT_EQ(string("13112221"), s.countAndSay(7));
    EXPECT_EQ(string("1113213211"), s.countAndSay(8));
}
