#include "climbStairs.cpp"
#include "gtest/gtest.h"

/* int Solution::climbStairs(n) */

TEST(climbStairsTest, Positive){
    Solution s;

    EXPECT_EQ(0, s.climbStairs(0));
    EXPECT_EQ(1, s.climbStairs(1));
    EXPECT_EQ(2, s.climbStairs(2));
    EXPECT_EQ(3, s.climbStairs(3));
    EXPECT_EQ(5, s.climbStairs(4));
    EXPECT_EQ(8, s.climbStairs(5));
    EXPECT_EQ(13, s.climbStairs(6));
    EXPECT_EQ(21, s.climbStairs(7));
}
