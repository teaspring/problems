#include "romannumeral.h"
#include "gtest/gtest.h"

/*
 * string int2Roman(int)
 *
 * int roman2Int(const string&);
 * */

/*------------ test cases -------------*/
TEST(romannumeral_Test, Positive01){
    Solution s;

    int num = 99;
    string result = s.int2Roman(num);

    string str("XCIX");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive02){
    Solution s;

    int num = 98;
    string result = s.int2Roman(num);

    string str("XCVIII");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive03){
    Solution s;

    int num = 97;
    string result = s.int2Roman(num);

    string str("XCVII");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive04){
    Solution s;

    int num = 96;
    string result = s.int2Roman(num);

    string str("XCVI");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive05){
    Solution s;

    int num = 999;
    string result = s.int2Roman(num);

    string str("CMXCIX");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive06){
    Solution s;

    int num = 998;
    string result = s.int2Roman(num);

    string str("CMXCVIII");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

TEST(romannumeral_Test, Positive07){
    Solution s;

    int num = 987;
    string result = s.int2Roman(num);

    string str("CMLXXXVII");

    EXPECT_STREQ(str.c_str(), result.c_str());

    EXPECT_EQ(num, s.roman2Int(str));
}

