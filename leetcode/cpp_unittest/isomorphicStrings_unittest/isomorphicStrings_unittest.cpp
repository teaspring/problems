#include "isomorphicStrings.cpp"
#include "gtest/gtest.h"

/*
 * bool isIssomorphic_01(string, string)
 * */
TEST(isomorphicStrings01Test, Positive01){
    Solution solution;
    string s("egg");
    string t("add");

    EXPECT_TRUE(solution.isIsomorphic_01(s, t));
}

TEST(isomorphicStrings01Test, Positive02){
    Solution solution;
    string s("paper");
    string t("title");

    EXPECT_TRUE(solution.isIsomorphic_01(s, t));
}

TEST(isomorphicStrings01Test, Negative01){
    Solution solution;
    string s("egg");
    string t("agd");

    EXPECT_FALSE(solution.isIsomorphic_01(s, t));
}

TEST(isomorphicStrings01Test, Negative02){
    Solution solution;
    string s("ab");
    string t("aa");

    EXPECT_FALSE(solution.isIsomorphic_01(s, t));
}

TEST(isomorphicStrings01Test, Negative03){
    Solution solution;
    string s("aa");
    string t("cb");

    EXPECT_FALSE(solution.isIsomorphic_01(s, t));
}

/*
 * bool isIssomorphic_02(string, string)
 * */
TEST(isomorphicStrings02Test, Positive01){
    Solution solution;
    string s("egg");
    string t("add");

    EXPECT_TRUE(solution.isIsomorphic_02(s, t));
}

TEST(isomorphicStrings02Test, Positive02){
    Solution solution;
    string s("paper");
    string t("title");

    EXPECT_TRUE(solution.isIsomorphic_02(s, t));
}

TEST(isomorphicStrings02Test, Negative01){
    Solution solution;
    string s("egg");
    string t("agd");

    EXPECT_FALSE(solution.isIsomorphic_02(s, t));
}

TEST(isomorphicStrings02Test, Negative02){
    Solution solution;
    string s("ab");
    string t("aa");

    EXPECT_FALSE(solution.isIsomorphic_02(s, t));
}

TEST(isomorphicStrings02Test, Negative03){
    Solution solution;
    string s("aa");
    string t("cb");

    EXPECT_FALSE(solution.isIsomorphic_02(s, t));
}
