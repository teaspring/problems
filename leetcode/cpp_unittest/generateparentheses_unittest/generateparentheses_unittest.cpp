#include "generateparentheses.cpp"
#include "gtest/gtest.h"
#include <cstring>

/* vector<string> Solution::generate(int) */

bool vectorContains(vector<string>& expected, string str){
    const int n = expected.size();
    for(int i = 0; i < n; i++){
        if(strcmp(expected[i].c_str(), str.c_str()) == 0)
          return true;
    }
    return false;
}

bool assertVectorStr(vector<string>& expected, vector<string>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_TRUE(vectorContains(expected, result[i]));
        EXPECT_TRUE(vectorContains(result, expected[i]));
    }
    return true;
}

/* test cases */
TEST(generateparenthesesTest, Positive01){
    Solution s;

    int n = 3;
    string arr[5] = {"((()))", "(()())", "()(())", "()()()", "(())()"};
    vector<string> expected(arr, arr + 5);

    vector<string> result = s.generate(n);
    EXPECT_TRUE(assertVectorStr(expected, result));
}
