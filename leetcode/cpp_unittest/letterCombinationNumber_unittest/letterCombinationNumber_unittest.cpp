#include "letterCombinationNumber.cpp"
#include "gtest/gtest.h"
#include <algorithm>

/*
 * vector<string> letterCombinations(const string& digits)
 * */

/* customized methods to falicitate construct and assert */

void equalsList(vector<string>& list1, vector<string>& list2){
    EXPECT_EQ(list1.size(), list2.size());

    const int n = list1.size();
    for(int i = 0; i < n; i++){
        EXPECT_STREQ(list1[i].c_str(), list2[i].c_str());
    }
}

/*
 * 1        2(ABC)   3(DEF)
 * 4(GHI)   5(JKL)   6(MNO)
 * 7(PQRS)  8(TUV)   9(WXYZ)
 * */

/*---------------------- test case ----------------------*/
TEST(letterCombinationNumberTest, Positive01){
    Solution game;

    string digits("235");

    const int rows = 27;
    string arr[rows] = { "adj", "adk", "adl", "aej", "aek", "ael", "afj", "afk", "afl",
                         "bdj", "bdk", "bdl", "bej", "bek", "bel", "bfj", "bfk", "bfl",
                         "cdj", "cdk", "cdl", "cej", "cek", "cel", "cfj", "cfk", "cfl"};

    vector<string> expected;
    for(int i = 0; i < rows; i++){
        expected.push_back(arr[i]);
    }

    vector<string> result = game.letterCombinations(digits);

    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());

    equalsList(expected, result);

    expected.clear();
    result.clear();
}
