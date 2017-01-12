#include "happyNumber.cpp"
#include "gtest/gtest.h"

/*
 * bool Solution::happyNumber(int n)
 * */
TEST(happyNumberTest, Positive_01){
    Solution s;
    EXPECT_TRUE(s.isHappyNumber(19));
}

TEST(happyNumberTest, Positive_02){
    Solution s;
    EXPECT_TRUE(s.isHappyNumber(23));
}

TEST(happyNumberTest, Negative_01){
    Solution s;
    EXPECT_FALSE(s.isHappyNumber(25));
}
