#include "BytePairEncoding.cpp"
#include "gtest/gtest.h"
#include "ut_shared.cpp"

using namespace std;

TEST(HackingRobberCityTest, Positive01)
{
    Solution s;
    string msg = "aaabdaaabac";
    // expected result
    string expected_encoded_msg = "XdXac";
    vector<string> expected_rules = {
        "Z = aa",
        "Y = Za",
        "X = Yb"
    };
    // result
    string encoded_msg;
    vector<string> rules;
    s.process1(msg, encoded_msg, rules);
    // assert
    EXPECT_EQ(expected_encoded_msg, encoded_msg);
    EXPECT_EQ_VEC<string>(expected_rules, rules);
}

TEST(HackingRobberCityTest, Positive02)
{
    Solution s;
    string msg = "cdeaafdhhhcdecbfcbhfhdhhccfhedeadggchefhgcaffgdcagdfedaghgceafbdccegbfggafhdffbhahgadeabccabhfgeceff";
    // expected result
    string expected_encoded_msg = "cXYQhcZcbfcWVQUVeXdgTheVTYSdcPOedPhTeYbdUegbSgYhOfWahgaXbUaWSeceff";
    vector<string> expected_rules = {
        "Z = de",
        "Y = af",
        "X = Za",
        "W = bh",
        "V = fh",
        "U = cc",
        "T = gc",
        "S = fg",
        "R = dh",
        "Q = Rh",
        "P = ag",
        "O = df"
    };
    // result
    string encoded_msg;
    vector<string> rules;
    s.process1(msg, encoded_msg, rules);
    // assert
    EXPECT_EQ(expected_encoded_msg, encoded_msg);
    EXPECT_EQ_VEC<string>(expected_rules, rules);
}