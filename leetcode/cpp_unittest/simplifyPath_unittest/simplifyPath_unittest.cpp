#include "simplifyPath.cpp"
#include "gtest/gtest.h"

/*
 * string simplifyPath(const string&)
 * */

/* ------------- test cases of simplifyPath01() ------------- */
TEST(simplifyPath01_Test, Positive01){
    Solution s;

    string str("/a/b/../../c/");

    string result = s.simplifyPath_01(str);

    string expected("/c");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath01_Test, Positive02){
    Solution s;

    string str("/../");

    string result = s.simplifyPath_01(str);

    string expected("/");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath01_Test, Positive03){
    Solution s;

    string str("/aa//b/../");

    string result = s.simplifyPath_01(str);

    string expected("/aa");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath01_Test, Positive04){
    Solution s;

    string str("//");

    string result = s.simplifyPath_01(str);

    string expected("/");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

/* ------------- test cases of simplifyPath01() ------------- */
TEST(simplifyPath02_Test, Positive01){
    Solution s;

    string str("/a/b/../../c/");

    string result = s.simplifyPath_02(str);

    string expected("/c");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath02_Test, Positive02){
    Solution s;

    string str("/../");

    string result = s.simplifyPath_02(str);

    string expected("/");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath02_Test, Positive03){
    Solution s;

    string str("/aa//b/../");

    string result = s.simplifyPath_02(str);

    string expected("/aa");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}

TEST(simplifyPath02_Test, Positive04){
    Solution s;

    string str("//");

    string result = s.simplifyPath_02(str);

    string expected("/");

    EXPECT_STREQ(expected.c_str(), result.c_str());
}
