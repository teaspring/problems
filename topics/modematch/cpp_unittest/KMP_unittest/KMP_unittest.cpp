#include "KMP.cpp"
#include "gtest/gtest.h"

/*
 * bool Solution::isMatchKMP(const string& str, const string& pattern)
 * */
TEST(KMPTest, Positive01){
    Solution s;
    string str("asbdadlasda");
    string pattern("dad");

    EXPECT_TRUE(s.isMatchKMP(str, pattern));
}

TEST(KMPTest, Negative01){
    Solution s;
    string str("asbdadlasda");
    string pattern("dada");

    EXPECT_FALSE(s.isMatchKMP(str, pattern));
}
