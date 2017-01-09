#include "compareVersion.cpp"
#include "gtest/gtest.h"

/*
 * int Solution::compareVersion(string version1, string version2)
 * */
TEST(compareVersionTest, Positive_01){
    Solution s;

    string version1("0.1");
    string version2("0.2");

    EXPECT_EQ(-1, s.compareVersion(version1, version2));
}

TEST(compareVersionTest, Positive_02){
    Solution s;

    string version1("1.1");
    string version2("0.1");

    EXPECT_EQ(1, s.compareVersion(version1, version2));
}

TEST(compareVersionTest, Positive_03){
    Solution s;

    string version1("1.2");
    string version2("1.2.2");

    EXPECT_EQ(-1, s.compareVersion(version1, version2));
}

TEST(compareVersionTest, Positive_04){
    Solution s;

    string version1("1.1.12");
    string version2("1.1");

    EXPECT_EQ(1, s.compareVersion(version1, version2));
}

TEST(compareVersionTest, Edge_01){
    Solution s;

    string version1("1.0");
    string version2("1");

    EXPECT_EQ(0, s.compareVersion(version1, version2));
}
