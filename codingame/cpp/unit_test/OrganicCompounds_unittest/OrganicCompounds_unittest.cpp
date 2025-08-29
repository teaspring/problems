#include "OrganicCompounds.cpp"
#include "gtest/gtest.h"
#include "ut_shared.cpp"

using namespace std;

TEST(HackingRobberCityTest, Positive01)
{
    Solution s;
    vector<string> organic_compounds = {
        "CH2(1)CH2(1)CH1(1)CH2",
        "(1)         (1)   (1)",
        "CH2         CH2   CH2",
        "(1)         (1)   (1)",
        "CH2(1)CH2(1)CH1(1)CH2"
    };
    // result
    string check_res;
    s.process1(organic_compounds, check_res);
    // assert
    EXPECT_EQ("VALID", check_res);
}

TEST(HackingRobberCityTest, Negative01)
{
    Solution s;
    vector<string> organic_compounds = {
        "CH3(1)CH1(1)CH2(1)CH1(1)CH3",
        "(1)         (1)",
        "CH3         CH1(1)CH1(1)CH3",
        "            (1)",
        "            CH3"
    };
    // result
    string check_res;
    s.process1(organic_compounds, check_res);
    // assert
    EXPECT_EQ("INVALID", check_res);
}