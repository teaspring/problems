#include "substringConcatAllWords.cpp"
#include "gtest/gtest.h"
#include <algorithm>

/*
 * int Solution::findSubstring_1(const string& S, vector<string>& L)
 *
 * int Solution::findSubstring_2(const string& S, vector<string>& L)
 * */

bool assertIntVector(vector<int>& expected, vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
    return true;
}

/********* solution1 test body *********/
TEST(Solution1_Test, Positive01){
    Solution s;

    const string arr[] = {"bar", "foo"};
    vector<string> L(arr, arr + 2);
    string S("foobarfoo");

    int expectedArr[] = {0, 3};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_1(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution1_Test, Positive02){
    Solution s;

    const string arr[] = {"ab", "ba", "ab", "ba"};
    vector<string> L(arr, arr + 4);
    string S("abaababbaabba");

    int expectedArr[] = {1, 5};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_1(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution1_Test, Positive03){
    Solution s;

    const string arr[] = {"is", "si"};
    vector<string> L(arr, arr + 2);
    string S("mississippi");

    int expectedArr[] = {1, 4};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_1(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution1_Test, Negative01){
    Solution s;

    const string arr[] = {"ab", "ba"};
    vector<string> L(arr, arr + 2);
    string S("abababab");

    vector<int> result = s.findSubstring_1(S, L);
    EXPECT_TRUE(result.empty());
}

/*-------------- solution2 test body -------------*/
TEST(Solution2_Test, Positive01){
    Solution s;

    const string arr[] = {"bar", "foo"};
    vector<string> L(arr, arr + 2);
    string S("foobarfoo");

    int expectedArr[] = {0, 3};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_2(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution2_Test, Positive02){
    Solution s;

    const string arr[] = {"ab", "ba", "ab", "ba"};
    vector<string> L(arr, arr + 4);
    string S("abaababbaabba");

    int expectedArr[] = {1, 5};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_2(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution2_Test, Positive03){
    Solution s;

    const string arr[] = {"is", "si"};
    vector<string> L(arr, arr + 2);
    string S("mississippi");

    int expectedArr[] = {1, 4};
    vector<int> expected(expectedArr, expectedArr + sizeof(expectedArr)/sizeof(int));

    vector<int> result = s.findSubstring_2(S, L);
    sort(result.begin(), result.end());

    EXPECT_TRUE(assertIntVector(expected, result));
}

TEST(Solution2_Test, Negative01){
    Solution s;

    const string arr[] = {"ab", "ba"};
    vector<string> L(arr, arr + 2);
    string S("abababab");

    vector<int> result = s.findSubstring_2(S, L);
    EXPECT_TRUE(result.empty());
}
