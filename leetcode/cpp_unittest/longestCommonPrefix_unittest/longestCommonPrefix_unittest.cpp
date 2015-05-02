#include "longestCommonPrefix.cpp"
#include "gtest/gtest.h"
#include <algorithm>

/*
 * string longestCommonPrefix(const vector<string>& strs)
 * */

/*---------------------- test case ----------------------*/
TEST(longestCommonPrefixTest, Positive01){
    Solution game;

    const int rows = 5;
    string arr[] = {"abcelk", "abc0e1", "abcefg", "abc0p2e", "abceklf0"};

    vector<string> strs;
    for(int i = 0; i < rows; i++){
        strs.push_back(arr[i]);
    }

    string expected("abc");
    string result = game.longestCommonPrefix(strs);

    EXPECT_STREQ(expected.c_str(), result.c_str());

    strs.clear();
}
