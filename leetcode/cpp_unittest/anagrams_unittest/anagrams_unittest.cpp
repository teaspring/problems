#include "anagrams.cpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <cstring>

using namespace std;

/* vector<string> Solution::anagrams(vector<string>&) */

/*
 * assert two vector<> whether have same elements
 * */
bool comparestr(string str1, string str2){ // indicate whether 1st arg should go before 2nd arg
    return strcmp(str1.c_str(), str2.c_str()) <= 0;
}

bool assertTwoStrVectors(vector<string>& expected, vector<string>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    sort(expected.begin(), expected.end(), comparestr);
    sort(result.begin(), result.end(), comparestr);

    for(int i = 0; i < n; i++){
        EXPECT_STREQ(expected[i].c_str(), result[i].c_str());
    }
    return true;
}

void fillStrVector(string arr[], int n, vector<string>& vect){
    for(int i = 0; i < n; i++){
        vect.push_back(string(arr[i]));
    }
}

TEST(anagramsTest, Positive01){
    Solution s;

    vector<string> dict;
    string arr[]{"dog", "god", "odg", "cat"};
    fillStrVector(arr, 4, dict);

    vector<string> expected;
    string expArr[]{"dog", "odg", "god"};
    fillStrVector(expArr, 3, expected);

    vector<string> result = s.anagrams(dict);
    EXPECT_TRUE(assertTwoStrVectors(expected, result));

    dict.clear();
    expected.clear();
    result.clear();
}

TEST(anagramsTest, Positive02){
    Solution s;

    vector<string> dict;
    string arr[]{"red", "god", "odg", "cat", "rde", "der", "dre"};
    fillStrVector(arr, 7, dict);

    vector<string> expected;
    string expArr[]{"odg", "god", "red", "rde", "der", "dre"};
    fillStrVector(expArr, 6, expected);

    vector<string> result = s.anagrams(dict);
    EXPECT_TRUE(assertTwoStrVectors(expected, result));

    dict.clear();
    expected.clear();
    result.clear();
}
