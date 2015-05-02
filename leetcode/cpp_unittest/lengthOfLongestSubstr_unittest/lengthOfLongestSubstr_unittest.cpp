#include "lengthOfLongestSubstr.cpp"
#include "gtest/gtest.h"

/*
 * int lengthOfLongestSubstr(vector<int>&)
 * */

TEST(lengthOfLongestSubstrTest, Positive01){
    Solution s;

    string str("abcasdadas");

    int expected = 5;
    EXPECT_EQ(expected, s.lengthOfLongestSubstr(str));
}
