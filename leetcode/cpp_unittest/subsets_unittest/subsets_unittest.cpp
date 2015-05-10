#include "subsets.cpp"
#include "gtest/gtest.h"

/*
 * vector<vector<int> > subsets(vector<int>& S)
 * vector<vector<int> > subsetsII(vector<int>& S)
 * */

void assertDuoVector(vector<vector<int> >& expected, vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i].size(), result[i].size());
        const int m = expected[i].size();

        for(int j = 0; j < m; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/*---------------------- test cases ----------------------*/
TEST(subsets_Test, Positive01){
    Solution s;

    int arr[] = {1, 2, 3};
    vector<int> sets(arr, arr + sizeof(arr) / sizeof(int));

    int opt1[] = {};
    int opt2[] = {1};
    int opt3[] = {1, 2};
    int opt4[] = {1, 2, 3};
    int opt5[] = {1, 3};
    int opt6[] = {2};
    int opt7[] = {2, 3};
    int opt8[] = {3};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(opt1, opt1 + sizeof(opt1) / sizeof(int)));
    expected.push_back(vector<int>(opt2, opt2 + sizeof(opt2) / sizeof(int)));
    expected.push_back(vector<int>(opt3, opt3 + sizeof(opt3) / sizeof(int)));
    expected.push_back(vector<int>(opt4, opt4 + sizeof(opt4) / sizeof(int)));
    expected.push_back(vector<int>(opt5, opt5 + sizeof(opt5) / sizeof(int)));
    expected.push_back(vector<int>(opt6, opt6 + sizeof(opt6) / sizeof(int)));
    expected.push_back(vector<int>(opt7, opt7 + sizeof(opt7) / sizeof(int)));
    expected.push_back(vector<int>(opt8, opt8 + sizeof(opt8) / sizeof(int)));

    vector<vector<int> > result = s.subsets(sets);

    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());

    assertDuoVector(expected, result);

    sets.clear();
    expected.clear();
    result.clear();
}

TEST(subsetsII_Test, Positive01){
    Solution s;

    int arr[] = {1, 2, 2};
    vector<int> sets(arr, arr + sizeof(arr) / sizeof(int));

    int opt1[] = {};
    int opt2[] = {1};
    int opt3[] = {1, 2};
    int opt4[] = {1, 2, 2};
    int opt5[] = {2};
    int opt6[] = {2, 2};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(opt1, opt1 + sizeof(opt1) / sizeof(int)));
    expected.push_back(vector<int>(opt2, opt2 + sizeof(opt2) / sizeof(int)));
    expected.push_back(vector<int>(opt3, opt3 + sizeof(opt3) / sizeof(int)));
    expected.push_back(vector<int>(opt4, opt4 + sizeof(opt4) / sizeof(int)));
    expected.push_back(vector<int>(opt5, opt5 + sizeof(opt5) / sizeof(int)));
    expected.push_back(vector<int>(opt6, opt6 + sizeof(opt6) / sizeof(int)));

    vector<vector<int> > result = s.subsetsII(sets);

    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());

    assertDuoVector(expected, result);

    sets.clear();
    expected.clear();
    result.clear();
}
